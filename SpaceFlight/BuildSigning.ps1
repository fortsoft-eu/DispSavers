<#
Copyright (c) 2026 Petr Červinka - FortSoft <cervinka@fortsoft.eu>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

Last modified for version 1.2.0.0
#>

[CmdletBinding()]
param (
    [Parameter(Mandatory)][string]$Path,
    [string]$SignerName = $env:BUILD_SIGNER_NAME,
    [string]$CertificateThumbprint = $env:BUILD_CERTIFICATE_THUMBPRINT,
    [string]$SignToolPath = $env:BUILD_SIGNTOOL_PATH,
    [string]$TimestampServer = $env:BUILD_TIMESTAMP_SERVER,
    [switch]$VerifyOnly
)

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"
$securityModule = Join-Path $PSHOME "Modules\Microsoft.PowerShell.Security\Microsoft.PowerShell.Security.psd1"
Import-Module -Name $securityModule

# Returns the newest valid current-user code-signing certificate with a private key matching the requested selector.
function Find-SignerCertificate {
    param (
        [string]$Name,
        [string]$Thumbprint
    )

    if (-not $Name -and -not $Thumbprint) {
        throw "Select a signer name or certificate thumbprint in SpaceFlight Project Properties > Signing."
    }

    $now = Get-Date
    if ($Thumbprint) {
        $normalizedThumbprint = $Thumbprint.Replace(" ", "")
    } else {
        $normalizedThumbprint = $null
    }
    $certificates = @(Get-ChildItem Cert:\CurrentUser\My -CodeSigningCert |
        Where-Object {
            $_.HasPrivateKey -and
            $_.NotBefore -le $now -and
            $_.NotAfter -gt $now -and
            (-not $normalizedThumbprint -or $_.Thumbprint -ieq $normalizedThumbprint) -and
            (-not $Name -or $_.GetNameInfo([Security.Cryptography.X509Certificates.X509NameType]::SimpleName, $false) -ieq $Name)
        } |
        Sort-Object NotAfter -Descending)

    $certificate = $certificates | Select-Object -First 1
    if (-not $certificate) {
        throw "The requested valid code-signing certificate with a private key was not found in CurrentUser\My."
    }
    return $certificate
}

# Resolves the requested signing tool or searches PATH and installed Windows SDK versions.
function Find-SignTool {
    param (
        [string]$RequestedPath
    )

    if ($RequestedPath) {
        if (Test-Path -LiteralPath $RequestedPath -PathType Leaf) {
            return [IO.Path]::GetFullPath($RequestedPath)
        }
        throw "The specified SignTool executable does not exist: $RequestedPath"
    }

    $command = Get-Command signtool.exe -ErrorAction SilentlyContinue | Select-Object -First 1
    if ($command) {
        return $command.Source
    }

    $kitsRoot = Join-Path ${env:ProgramFiles(x86)} "Windows Kits\10\bin"
    if (Test-Path -LiteralPath $kitsRoot -PathType Container) {
        $versionDirectories = Get-ChildItem -LiteralPath $kitsRoot -Directory |
            Where-Object {
                $_.Name -match "^\d+\.\d+\.\d+\.\d+`$"
            } |
            Sort-Object {
                [version]$_.Name
            } -Descending
        foreach ($directory in $versionDirectories) {
            foreach ($architecture in @("x64", "x86")) {
                $candidate = Join-Path $directory.FullName "$architecture\signtool.exe"
                if (Test-Path -LiteralPath $candidate -PathType Leaf) {
                    return $candidate
                }
            }
        }

        foreach ($architecture in @("x64", "x86")) {
            $candidate = Join-Path $kitsRoot "$architecture\signtool.exe"
            if (Test-Path -LiteralPath $candidate -PathType Leaf) {
                return $candidate
            }
        }
    }

    throw "signtool.exe was not found. Install the Windows SDK or set its path in Project Properties > Signing."
}

# Verifies Authenticode trust and requires a trusted signature with a time-stamping certificate.
function Confirm-BinarySignature {
    param (
        [Parameter(Mandatory)][string]$Path,
        [Parameter(Mandatory)][string]$ToolPath
    )

    & $ToolPath verify /pa /tw /v $Path
    if ($LASTEXITCODE -ne 0) {
        throw "Authenticode verification failed for '$Path'."
    }
    $signature = Get-AuthenticodeSignature -LiteralPath $Path
    if ($signature.Status -ne "Valid" -or $null -eq $signature.TimeStamperCertificate) {
        throw "A valid Authenticode signature with a timestamp is required for '$Path'."
    }
    Write-Host "Signature verified successfully: $Path"
}

# Signs the complete linked binary with SHA-256 and a mandatory RFC 3161 SHA-256 timestamp.
function Sign-Binary {
    param (
        [Parameter(Mandatory)][string]$Path,
        [Parameter(Mandatory)]$Certificate,
        [Parameter(Mandatory)][string]$ToolPath,
        [Parameter(Mandatory)][ValidateNotNullOrEmpty()][string]$TimestampUrl
    )

    $signArguments = @("sign", "/sha1", $Certificate.Thumbprint, "/fd", "SHA256",
        "/tr", $TimestampUrl, "/td", "SHA256", "/v", $Path)

    Write-Host "Signing $([IO.Path]::GetFileName($Path))"
    & $ToolPath @signArguments
    if ($LASTEXITCODE -ne 0) {
        throw "Signing failed for '$Path'."
    }
    Confirm-BinarySignature -Path $Path -ToolPath $ToolPath
}

if (-not (Test-Path -LiteralPath $Path -PathType Leaf)) {
    throw "The binary to sign or verify does not exist: $Path"
}

if ([string]::IsNullOrWhiteSpace($TimestampServer)) {
    throw "Set the RFC 3161 timestamp server URL in SpaceFlight Project Properties > Signing > Timestamp server."
}

$certificate = Find-SignerCertificate -Name $SignerName -Thumbprint $CertificateThumbprint
$resolvedSignTool = Find-SignTool -RequestedPath $SignToolPath
$signature = Get-AuthenticodeSignature -LiteralPath $Path
if ($signature.Status -eq "Valid" -and
        $null -ne $signature.SignerCertificate -and
        $signature.SignerCertificate.Thumbprint -ieq $certificate.Thumbprint -and
        $null -ne $signature.TimeStamperCertificate) {
    Confirm-BinarySignature -Path $Path -ToolPath $resolvedSignTool
} elseif ($VerifyOnly) {
    throw "The SCR must have a valid, timestamped signature from the configured signer before it can be embedded in EXE: $Path"
} else {
    Sign-Binary -Path $Path -Certificate $certificate -ToolPath $resolvedSignTool -TimestampUrl $TimestampServer
}

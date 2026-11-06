<#
This is open-source software licensed under the terms of the MIT License.

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

Last modified for version 1.3.0.0
#>

param(
    [Parameter(Mandatory = $true)]
    [string]$Source,
    [Parameter(Mandatory = $true)]
    [string]$Output,
    [switch]$RawData,
    [string]$License,
    [string]$Notices,
    [string]$WebpLicense,
    [string]$Resource
)

$ErrorActionPreference = 'Stop'
$directory = Split-Path -Parent $Output
[IO.Directory]::CreateDirectory($directory) | Out-Null
$resourceCompilerLibraries = $env:LIB
try {
    $env:LIB = ''
    Add-Type -Path (Join-Path $PSScriptRoot 'ResourcePacker.cs') -ReferencedAssemblies 'System.dll', `
        'System.IO.Compression.dll'
} finally {
    $env:LIB = $resourceCompilerLibraries
}
[ResourcePacker]::Pack($Source, $Output, $RawData.IsPresent)

if ($License) {
    $encoding = New-Object Text.UTF8Encoding($false, $true)
    $licenseText = [IO.File]::ReadAllText($License, $encoding).Trim()
    foreach ($notice in @($Notices, $WebpLicense)) {
        if ($notice) {
            $licenseText += "`r`n`r`n`r`n" + [IO.File]::ReadAllText($notice, $encoding).Trim()
        }
    }
    [IO.File]::WriteAllText((Join-Path $directory 'license.utf8'), $licenseText, $encoding)
}

if ($Resource) {
    $resourceText = [IO.File]::ReadAllText($Resource, $encoding)
    [regex]$licenseResource = '(?m)^([ \t]*IDR_LICENSE[ \t]+RCDATA[ \t]+)"[^"\r\n]*"'
    if ($licenseResource.Matches($resourceText).Count -ne 1) {
        throw 'Expected exactly one IDR_LICENSE resource in the resource script.'
    }
    $resourceText = $licenseResource.Replace($resourceText, '$1"license.utf8"')
    [IO.File]::WriteAllText((Join-Path $directory ([IO.Path]::GetFileName($Resource))),
        $resourceText, $encoding)
}

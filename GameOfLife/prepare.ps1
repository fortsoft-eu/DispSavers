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
    [switch]$Patterns,
    [string]$License,
    [string]$Notices
)

$ErrorActionPreference = 'Stop'
$directory = Split-Path -Parent $Output
[IO.Directory]::CreateDirectory($directory) | Out-Null
$encoding = New-Object Text.UTF8Encoding($false, $true)
if ($Patterns) {
    [xml]$catalog = [IO.File]::ReadAllText($Source, $encoding)
    if ($catalog.DocumentElement.Name -ne 'LifePatterns') {
        throw 'Expected a LifePatterns XML catalog.'
    }
    $catalogPatterns = $catalog.DocumentElement.SelectNodes('Pattern')
    if ($catalogPatterns.Count -eq 0) {
        throw 'The LifePatterns XML catalog is empty.'
    }
    $data = New-Object Text.StringBuilder
    [void]$data.Append("LifePatterns`n")
    foreach ($pattern in $catalogPatterns) {
        $identity = $pattern.GetAttribute('id')
        $name = $pattern.GetAttribute('name')
        [uint32]$width = [Xml.XmlConvert]::ToUInt32($pattern.GetAttribute('width'))
        [uint32]$height = [Xml.XmlConvert]::ToUInt32($pattern.GetAttribute('height'))
        [bool]$repeatable = [Xml.XmlConvert]::ToBoolean($pattern.GetAttribute('repeatable'))
        $rle = [regex]::Replace($pattern.SelectSingleNode('Rle').InnerText, '\s', '')
        if (-not $identity -or -not $name -or $width -eq 0 -or $height -eq 0 -or -not $rle) {
            throw 'Incomplete pattern metadata or RLE in the LifePatterns XML catalog.'
        }
        $record = "{0}`t{1}`t{2}`t{3}`t{4}`n{5}`n" -f $identity, $name, $width, $height,
            [int]$repeatable, $rle
        [void]$data.Append($record)
    }
    $Source = Join-Path $directory 'LifePatterns.dat'
    [IO.File]::WriteAllText($Source, $data.ToString(), $encoding)
}
$resourceCompilerLibraries = $env:LIB
try {
    $env:LIB = ''
    Add-Type -Path (Join-Path $PSScriptRoot 'ResourcePacker.cs') -ReferencedAssemblies 'System.dll', `
        'System.IO.Compression.dll'
} finally {
    $env:LIB = $resourceCompilerLibraries
}
[ResourcePacker]::Pack($Source, $Output, $Patterns.IsPresent)

if ($License) {
    $licenseText = [IO.File]::ReadAllText($License, $encoding).Trim() + "`r`n`r`n`r`n"
    $licenseText += [IO.File]::ReadAllText($Notices, $encoding).Trim()
    [IO.File]::WriteAllText((Join-Path $directory 'license.utf8'), $licenseText, $encoding)
}

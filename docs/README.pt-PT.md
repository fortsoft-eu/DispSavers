# FlyingSolids

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · **Português** · [Norsk](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Suomi](README.fi-FI.md) · [Dansk](README.da-DK.md) · [Íslenska](README.is-IS.md) · [Türkçe](README.tr-TR.md)

O FlyingSolids é uma aplicação nativa Win32/x86 com Direct3D e uma proteção de ecrã do Windows que apresenta sólidos geométricos tridimensionais iluminados. Os sólidos movem-se e rodam de forma independente e ressaltam sem se atravessarem. As condições iniciais e as novas posições durante o voo provêm do gerador criptográfico do Windows; a leitura em blocos mantém reduzida a carga do processador.

## Funcionalidades

- **Observação do espaço** e **Voo pelo espaço** em linha reta
- Ativação independente da luz principal e da luz de preenchimento
- Cena independente em cada monitor selecionado
- Uma a dez cópias de cada sólido ativo
- Velocidade de objetos e câmara de 0 a 1600%; tamanho de 50 a 200%
- Superfícies brilhantes, iluminação, cores próprias e colisões
- Renderização ajustada à frequência de atualização de cada monitor
- Capturas PNG e gravação MP4 na aplicação autónoma
- Definições separadas para aplicação e proteção de ecrã
- 27 tipos de sólidos e interface em 17 idiomas

## Sólidos

O catálogo inclui poliedros, prismas regulares, pirâmides e cortes planos, cones e cilindros e respetivos cortes, um paraboloide de revolução fechado por um plano, sólidos derivados da esfera, elipsoides, um ovoide, um esferocilindro e um toro. A interface usa a terminologia geométrica consagrada em português europeu.

## Iluminação

As caixas `Luz principal` e `Luz de preenchimento` sob os controlos deslizantes da direita ativam ou desativam as duas luzes de forma independente em toda a cena. Por predefinição, `Luz principal` está ligada e `Luz de preenchimento` está desligada. As definições de iluminação são guardadas separadamente para a aplicação e a proteção de ecrã.

## Aplicação e proteção de ecrã

`FlyingSolids.exe` mantém uma única janela de controlo durante a animação. É possível selecionar vários monitores, alternar um com duplo clique ou desligá-los todos. Os PNG são guardados por predefinição em **Imagens**, os MP4 em **Vídeos**, usando **Documentos** como alternativa. O EXE instala ou desinstala a proteção de ecrã incorporada.

A aplicação só pode ter uma instância em execução. Um novo arranque restaura a janela de controlo minimizada, redesenha-a e coloca-a em primeiro plano.

Use Tab e Shift+Tab para passar entre controlos; Alt e a letra sublinhada ativam um comando. Esc fecha a janela ativa de Ajuda ou Acerca de; na janela de controlo, termina a aplicação.

As capturas e gravações usam o primeiro monitor de animação ativo, não uma imagem conjunta de todos os monitores. PNG usa Imagens, MP4 Vídeos; se essas pastas não existirem, usa-se Documentos. A gravação MP4 segue a frequência do monitor, até um máximo de 60 fotogramas por segundo.

`FlyingSolids.scr` tem definições próprias e não permite gravação. O modo de ecrã inteiro cria uma cena independente em cada monitor.

Ativar pré-visualização nas definições inicia uma pré-visualização independente em ecrã inteiro em todos os monitores. Usa as definições atuais, permite ajustes em tempo real e pode ser terminada. Qualquer tecla, movimento do rato ou clique termina a proteção em ecrã inteiro.

Esc nas definições equivale a Cancelar; na Ajuda ou em Acerca de, fecha apenas essa janela.

## Armazenamento

```text
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\Standalone
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\ScreenSaver
```

## Requisitos do sistema

Os sistemas Windows 7 a Windows 11 suportam todas as funcionalidades, incluindo capturas PNG e gravação MP4.

Windows Vista SP2: KB971512, KB2117917. A gravação MP4 não funciona no Vista na versão atual.

A apresentação requer Direct3D 11, não apenas um runtime DirectX mais antigo. A gravação MP4 requer componentes Media Foundation e um codificador H.264 disponíveis.

## Compilação

Abra `DispSavers.slnx`, selecione `Release | x86` e recompile a solução com MSVC v145 e um Windows SDK. São criados o EXE e o SCR. `PackageRelease.ps1` cria o único pacote `DispSavers-<version>-win32.zip` da solução, com os ficheiros e `license.txt` no subdiretório `FlyingSolids`. Não existe configuração x64.

## Licença

O FlyingSolids é disponibilizado sob a [licença MIT](../license.txt).

Copyright © Petr Červinka — FortSoft 2026

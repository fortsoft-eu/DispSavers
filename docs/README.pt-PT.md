# FlyingSolids

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · **Português** · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [Dansk](README.da-DK.md) · [Suomi](README.fi-FI.md) · [Íslenska](README.is-IS.md) · [Norsk (bokmål)](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Türkçe](README.tr-TR.md) · [Eesti](README.et-EE.md) · [Gaeilge](README.ga-IE.md) · [Lietuvių](README.lt-LT.md) · [Latviešu](README.lv-LV.md) · [Magyar](README.hu-HU.md) · [Malti](README.mt-MT.md) · [Nederlands](README.nl-NL.md) · [Română](README.ro-RO.md) · [Ελληνικά](README.el-GR.md) · [Bosanski](README.bs-Latn-BA.md) · [Hrvatski](README.hr-HR.md) · [Slovenščina](README.sl-SI.md) · [Crnogorski](README.cnr-Latn-ME.md) · [Беларуская](README.be-BY.md) · [Български](README.bg-BG.md) · [Македонски](README.mk-MK.md) · [Српски](README.sr-Cyrl-RS.md) · [Українська](README.uk-UA.md) · [Русский](README.ru-RU.md)

O FlyingSolids é uma aplicação nativa Win32/x86 com Direct3D e uma proteção de ecrã do Windows que apresenta sólidos geométricos tridimensionais iluminados. Os sólidos movem-se e rodam de forma independente e ressaltam sem se atravessarem.

A seleção das linhas determina os ecrãs a configurar e é independente das caixas que ativam as saídas de animação. Ctrl+A seleciona todos os ecrãs; Ctrl e Shift alteram a seleção. Todas as opções e controlos deslizantes da animação aplicam-se aos ecrãs selecionados. A seleção é guardada separadamente para EXE e SCR. Se todos estavam selecionados, os novos ecrãs também são incluídos. Valores diferentes entre os ecrãs selecionados são indicados por caixas de verificação indeterminadas e por um padrão pontilhado nos botões de opção, nas pegas dos controlos deslizantes e nos botões «Ativar tudo» e «Desativar tudo». As etiquetas dos controlos deslizantes apresentam um travessão em vez de um valor comum. Alterar uma opção ou clicar num controlo deslizante aplica esse valor a todos os ecrãs selecionados.

## Funcionalidades

- **Observação do espaço** e **Voo pelo espaço** em linha reta. Selecione um ou mais monitores na lista. O modo de câmara, os objetos, a iluminação, as velocidades, o tamanho e o número de cópias aplicam-se apenas aos monitores selecionados. Cada monitor guarda as suas próprias definições.
- Controlo independente das luzes principal, de preenchimento, ambiente e dos contornos
- Cena independente em cada monitor
- Uma a dez cópias de cada sólido ativo
- Velocidade de objetos e câmara de 0 a 1600%; tamanho de 50 a 200%
- Superfícies brilhantes, iluminação, cores próprias e colisões
- Renderização ajustada à frequência de atualização de cada monitor
- Capturas PNG e gravação MP4 na aplicação autónoma
- Definições separadas para aplicação e proteção de ecrã
- 30 tipos de sólidos e interface em 36 idiomas

## Sólidos

Cubo; Pirâmide quadrangular regular; Tronco de pirâmide quadrangular; Pirâmide quadrangular, corte oblíquo; Pirâmide quadrada, corte normal à base; Prisma triangular regular; Prisma pentagonal regular; Prisma hexagonal regular; Octaedro regular; Bipirâmide pentagonal; Cone circular reto; Tronco de cone; Cone truncado por um plano oblíquo; Cone, corte perpendicular à base; Cilindro circular reto; Cilindro oco; Cilindro oco com extremidades toroidais; Paraboloide de revolução fechado por plano; Esfera; Hemisfério; Segmento esférico; Segmento esférico maior; Segmento esférico de duas bases; Elipsoide triaxial; Esferoide prolato; Esferoide oblato; Ovoide; Esferocilindro; Disco arredondado (spheroplatelet); Toro.

## Iluminação

As caixas `Luz principal`, `Luz de preenchimento`, `Luz ambiente` e `Iluminação dos contornos` sob os controlos deslizantes controlam a iluminação dos monitores selecionados de forma independente. A luz ambiente fornece iluminação de base às superfícies e a iluminação dos contornos realça os seus limites. As definições são guardadas separadamente para a aplicação e a proteção de ecrã.

## Aplicação e proteção de ecrã

`FlyingSolids.exe` mantém uma única janela de controlo durante a animação. Ative ou desative as saídas de animação através das caixas dos ecrãs ou com um duplo clique nas respetivas linhas. O EXE instala ou desinstala a proteção de ecrã incorporada. A aplicação só pode ter uma instância em execução. Um novo arranque restaura a janela de controlo minimizada e coloca-a em primeiro plano. Use Tab e Shift+Tab para passar entre controlos; Alt e a letra sublinhada ativam um comando. Esc fecha a janela ativa de Ajuda ou Acerca de; na janela de controlo, termina a aplicação. As capturas e gravações usam o primeiro monitor de animação ativo, não uma imagem conjunta de todos os monitores. PNG usa Imagens, MP4 Vídeos; se essas pastas não existirem, usa-se Documentos. O botão Definições de gravação permite escolher Viewport ou TV. Viewport conserva as dimensões e a frequência de atualização do monitor de animação, até 60 fotogramas por segundo. TV oferece 1920 × 1080, 1440 × 1080 ou 1280 × 720 no formato 16:9, a 50, 25, 59.94 (60000/1001) ou 29.97 (30000/1001) fotogramas por segundo. A proporção da imagem é mantida; TV usa vídeo progressivo BT.709 com intervalo limitado e amostragem 4:2:0. A resolução e a frequência só estão disponíveis no modo TV. A janela Definições de gravação pode ser minimizada e não bloqueia as outras janelas da aplicação. OK guarda as escolhas para a próxima gravação MP4; Cancelar ou Esc descarta as alterações não confirmadas. A saída de animação do monitor gravado não pode ser desativada durante a gravação; as alterações aos outros monitores não a interrompem. Fechar a aplicação durante uma gravação exige confirmação, pois também termina a gravação. A pausa e o bloqueio da proteção de ecrã aplicam-se a toda a aplicação, independentemente dos ecrãs selecionados. Com o bloqueio ativo, a proteção de ecrã do Windows só é impedida enquanto existir animação visível e não pausada em pelo menos um ecrã. `FlyingSolids.scr` tem definições próprias e não permite gravação. O modo de ecrã inteiro cria uma cena independente em cada monitor. Ativar pré-visualização nas definições inicia uma pré-visualização independente em ecrã inteiro em todos os monitores. Usa as definições atuais, permite ajustes em tempo real e pode ser terminada. Qualquer tecla, movimento do rato ou clique termina a proteção em ecrã inteiro. Esc nas definições equivale a Cancelar; na Ajuda ou em Acerca de, fecha apenas essa janela.

## Armazenamento

```text
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\Standalone
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\ScreenSaver
```

## Requisitos do sistema

Os sistemas Windows 7 a Windows 11 suportam todas as funcionalidades, incluindo capturas PNG e gravação MP4. Para executar a aplicação no Windows Vista SP2, é necessário instalar as atualizações KB971512 e KB2117917. A gravação MP4 não funciona no Vista na versão atual. A apresentação requer Direct3D 11, não apenas um runtime DirectX mais antigo. A gravação MP4 requer componentes Media Foundation e um codificador H.264 disponíveis. A aplicação autónoma também pode ser executada no Linux através do Wine; a integração como proteção de ecrã está disponível apenas no Windows.

## Compilação

Abra `DispSavers.slnx` no Visual Studio com MSVC v145 e um Windows SDK. Selecione `Release | x86` e recompile a solução para criar `Release\FlyingSolids.exe` e `Release\FlyingSolids.scr`. Não existe configuração x64. Nas propriedades do projeto `FlyingSolids`, página `Signing`, indique o nome ou a impressão digital de um certificado válido de assinatura de código com chave privada no arquivo `Personal (My)` do utilizador atual. As definições aplicam-se ao EXE e ao SCR e são guardadas em `FlyingSolids.vcxproj.user`, ignorado pelo Git. O SignTool é encontrado automaticamente no PATH ou no Windows SDK. Se utilizar SimplySign, inicie sessão no SimplySign Desktop antes da compilação. Primeiro, o SCR é assinado e recebe um carimbo temporal RFC 3161 SHA-256 obrigatório do servidor de carimbos temporais configurado; depois é incorporado no EXE, que também é assinado e carimbado temporalmente. Indique o URL do servidor de carimbos temporais RFC 3161 no campo `Timestamp server`. Uma falha de assinatura, carimbo temporal ou verificação interrompe a compilação; os ficheiros com assinaturas válidas e carimbo temporal não são novamente assinados.

Execute `PackageRelease.ps1` sem parâmetros de assinatura para empacotar estes ficheiros compilados. O script utiliza cópias temporárias, não altera os ficheiros em `Release` e apenas verifica as assinaturas válidas existentes. Cria o único arquivo `DispSavers-<version>-win32.zip`, contendo `FlyingSolids\FlyingSolids.exe`, `FlyingSolids\FlyingSolids.scr`, `FlyingSolids\license.txt`, `FlightCorridor\FlightCorridor.exe`, `FlightCorridor\FlightCorridor.scr`, `FlightCorridor\license.txt`, `SpaceFlight\SpaceFlight.exe`, `SpaceFlight\SpaceFlight.scr` e `SpaceFlight\license.txt`. O ZIP anterior é removido no início da execução; uma falha de verificação impede a criação de um novo arquivo.

## Licença

O FlyingSolids é disponibilizado sob a [licença MIT](../license.txt). Copyright © Petr Červinka — FortSoft 2026

## FlightCorridor

O FlightCorridor oferece Voo entre quatro superfícies deformáveis e Voo através de um funil deformável. Atribua um único voo a cada monitor: selecione a respetiva linha e o botão de opção correspondente.

`Release\FlightCorridor.exe` · `Release\FlightCorridor.scr` · [FlightCorridor](../FlightCorridor/README.pt-PT.md)

## SpaceFlight

O SpaceFlight oferece «Superfície ondulante infinita» e «Voo de longa distância — superfície deformável». Atribua um único voo a cada monitor: selecione a respetiva linha e o botão de opção correspondente.

`Release\SpaceFlight.exe` · `Release\SpaceFlight.scr` · [SpaceFlight](../SpaceFlight/README.pt-PT.md)

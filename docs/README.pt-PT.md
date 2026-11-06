# DispSavers

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · **Português** · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [Dansk](README.da-DK.md) · [Suomi](README.fi-FI.md) · [Íslenska](README.is-IS.md) · [Norsk (bokmål)](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Türkçe](README.tr-TR.md) · [Eesti](README.et-EE.md) · [Gaeilge](README.ga-IE.md) · [Lietuvių](README.lt-LT.md) · [Latviešu](README.lv-LV.md) · [Magyar](README.hu-HU.md) · [Malti](README.mt-MT.md) · [Nederlands](README.nl-NL.md) · [Română](README.ro-RO.md) · [Ελληνικά](README.el-GR.md) · [Bosanski](README.bs-Latn-BA.md) · [Hrvatski](README.hr-HR.md) · [Slovenščina](README.sl-SI.md) · [Crnogorski](README.cnr-Latn-ME.md) · [Беларуская](README.be-BY.md) · [Български](README.bg-BG.md) · [Македонски](README.mk-MK.md) · [Српски](README.sr-Cyrl-RS.md) · [Українська](README.uk-UA.md) · [Русский](README.ru-RU.md)

## FlyingSolids

Animação acelerada por hardware de objetos 3D sólidos.

Selecione um ou mais monitores na lista. O modo de câmara, os objetos, a iluminação, as velocidades, o tamanho e o número de cópias aplicam-se apenas aos monitores selecionados. Cada monitor guarda as suas próprias definições. O FlyingSolids mostra sólidos 3D iluminados. Os controlos regulam a velocidade dos objetos e da câmara entre 0 e 1600%, uma a dez cópias e o tamanho entre 50 e 200%. Escolha Observação do espaço ou o Voo pelo espaço em linha reta e ative os sólidos pretendidos. As caixas Luz principal, Luz de preenchimento, Luz ambiente e Iluminação dos contornos sob os controlos deslizantes controlam a iluminação dos monitores selecionados de forma independente. A luz ambiente fornece iluminação de base às superfícies e a iluminação dos contornos realça os seus limites. As definições são guardadas separadamente para a aplicação e a proteção de ecrã.

`FlyingSolids.exe` · `FlyingSolids.scr`

## FlightCorridor

Voo acelerado por hardware através de um corredor e de um funil deformáveis.

FlightCorridor: Voo entre quatro superfícies deformáveis; Voo através de um funil deformável. Atribua uma única animação a cada ecrã. Textura alterna entre superfícies texturadas e modelo em arame. A rotação livre da câmara muda lentamente a direção da vista nas três dimensões. A opção «Pausas e inversões» acrescenta desacelerações, pausas e inversões aleatórias da rotação; o voo para a frente continua. A velocidade vai de 0 a 1600%. Cada ecrã tem uma cena aleatória independente, apresentada à sua própria frequência de atualização. A luz principal, a luz de preenchimento, a luz ambiente e a iluminação dos contornos podem ser ativadas separadamente nos monitores selecionados. A iluminação aplica-se apenas às superfícies com textura.

`FlightCorridor.exe` · `FlightCorridor.scr`

## SpaceFlight

Voo acelerado por hardware sobre superfícies ondulantes e deformáveis.

SpaceFlight: Superfície ondulante infinita; Voo de longa distância — superfície deformável; Voo pelo espaço deformado pela gravidade. Atribua uma única animação a cada ecrã. Textura alterna entre superfícies texturadas e modelo em arame. A rotação livre da câmara muda lentamente a direção da vista nas três dimensões. A opção «Pausas e inversões» acrescenta desacelerações, pausas e inversões aleatórias da rotação; o voo para a frente continua. A velocidade vai de 0 a 1600%. Cada ecrã tem uma cena aleatória independente, apresentada à sua própria frequência de atualização. A luz principal, a luz de preenchimento, a luz ambiente e a iluminação dos contornos podem ser ativadas separadamente nos monitores selecionados. A iluminação aplica-se apenas às superfícies com textura. As duas animações de superfícies oferecem Plano, Ondulação ou Funil. O funil atrai a câmara para o interior ao longo de uma espiral descendente. O voo pelo espaço deformado pela gravidade mostra uma grelha tridimensional de linhas. As opções de textura, forma da superfície e iluminação aplicam-se apenas às duas animações de superfícies.

`SpaceFlight.exe` · `SpaceFlight.scr`

## GameOfLife

O Jogo da Vida de Conway num mundo partilhado entre ecrãs.

### Regras

O Jogo da Vida de Conway usa B3/S23. Uma célula morta nasce com exatamente três vizinhas vivas; uma viva sobrevive com duas ou três. As oito vizinhas incluem diagonais. Todas mudam em simultâneo. As margens opostas ligam-se: esquerda à direita, superior à inferior.

### Ecrãs e mundo partilhado

As caixas no EXE ativam ecrãs; as definições aplicam-se ao mundo partilhado. Um único ecrã ativo contém o mundo inteiro. Ao escolher parte da disposição, eliminam-se linhas e colunas completamente vazias: os ecrãs esquerdo e direito unem-se ao desligar o central. As lacunas interiores que não podem ser eliminadas continuam na simulação. Selecionar todos os ecrãs, ou executar SCR, mantém o retângulo do ambiente de trabalho e os intervalos invisíveis. Cada ecrã mostra a sua região da mesma simulação.

### Estado inicial e padrões

O início predefinido é ruído aleatório com 25 % de células vivas. A densidade inicial 0–100 % aplica-se no próximo reinício. Apenas padrões conhecidos usa 4 106 padrões incluídos sem ruído e desativa a densidade. Escolha uma mistura ou um nome; as dimensões são em células. Escreva para procurar. Só são apresentados padrões que cabem inteiros. Os pequenos verificados repetem-se em cópias separadas; os grandes ou complexos surgem uma vez ao centro. Reduzir o mundo pode substituir uma escolha demasiado grande por uma mistura. Alterar modo ou padrão cria outra cena. Os reinícios mantêm a escolha; o catálogo funciona sem ligação.

### Células, grelha e cores

Sem grelha, o tamanho é 1–64 px. Mostrar grelha acrescenta uma margem de 1 px no espaçamento existente: o valor e o cursor diminuem um, ficando 1–63 utilizáveis. Desativar repõe o valor. O cursor mantém o intervalo e recua da extremidade indisponível; a caixa continua ativa. A cena mantém-se, exceto ao ativar a 1 px: o espaçamento passa a 2 px e a cena reinicia. Alterar tamanho ou ecrãs também recomeça. Mundos muito grandes podem exigir um mínimo superior. As cores das células, fundo e grelha mudam separadamente sem reinício. A cor aleatória das células vivas muda em cada reinício manual ou automático da cena. A cor guardada é preservada e regressa ao desativar esta opção. O mesmo comportamento pode ser ativado separadamente para o fundo e a grelha; ambas as novas opções estão inicialmente desativadas.

### Velocidade, pausa e reinício automático

A velocidade é 0–240 gerações/s, independente do refrescamento; 0 para a evolução. Pausa e Retomar mantêm o mundo. Reiniciar recomeça no modo escolhido. O reinício automático opcional deteta fases visíveis estáticas ou exatamente repetidas, incluindo osciladores. Compara gerações, não segundos; exclui zonas invisíveis. Os resultados assíncronos podem atrasar ligeiramente o reinício. Predefinições: espaçamento 8 px, 20 gerações/s, cor aleatória das células vivas e reinício automático ligados. A grelha está desativada por predefinição. A velocidade atingida depende do desempenho e do número de células. O reinício automático compara as regiões dos ecrãs ativos; os intervalos continuam a evoluir, mas não entram na comparação.

### Repor valores

A reposição define o tamanho apresentado como 8 px com ou sem grelha (espaçamento de 9 ou 8 px), a velocidade como 20 gerações/s, a densidade como 25 % e as três cores predefinidas. As outras escolhas são mantidas; um padrão que deixe de caber é substituído pela mistura. Só é criada uma nova cena se mudar o espaçamento ou a densidade no modo de ruído.

### Aplicação autónoma e gravação MP4

O EXE guarda definições continuamente e grava o primeiro ecrã ativo em MP4. Sugere Vídeos, ou Documentos como alternativa. Viewport usa dimensões e frequência do ecrã até 60 fotogramas/s. TV oferece 1920 × 1080, 1440 × 1080 ou 1280 × 720 em 16:9 a 50, 25, 59,94 (60000/1001) ou 29,97 (30000/1001) fotogramas/s. A proporção mantém-se; TV usa BT.709 progressivo de gama limitada e 4:2:0. A janela independente de definições pode ser minimizada. OK guarda para a próxima gravação; Cancelar ou Esc descarta alterações pendentes. O ecrã gravado não pode ser desligado; as outras saídas podem mudar. Sair durante a gravação exige confirmação. Com foco na animação, Espaço alterna a pausa, F9: Iniciar gravação; F10: Parar gravação. O cursor oculta-se após 1 segundo inativo e reaparece ao mover-se. Tab/Shift+Tab percorre controlos; Alt ativa comandos sublinhados. Esc fecha Ajuda/Acerca de ou sai na janela principal. Proteção de ecrã do Windows… abre as definições da proteção de ecrã do sistema.

### Instantâneo e gestão da proteção de ecrã no EXE

O instantâneo guarda um BMP/GIF/JPEG/PNG/TIFF/WebP do ecrã em gravação ou, caso contrário, do primeiro ativo, à sua resolução e sem reiniciar a cena. Sugere Imagens, ou Documentos como alternativa. Bloquear a proteção de ecrã durante a animação impede a sua ativação enquanto a animação estiver visível e sem pausa. Velocidade zero não é pausa. A instalação a partir do EXE extrai o SCR incluído e seleciona-o como proteção de ecrã do Windows. Instalar e desinstalar pode exigir autorização de administrador; a barra de estado indica a operação até ao fim. Se a remoção estiver bloqueada, feche a proteção em execução, as suas definições e a pré-visualização do Windows.

### Proteção de ecrã do Windows

GameOfLife.scr usa todos os ecrãs com definições separadas do EXE. Ativar pré-visualização inicia a animação de ecrã inteiro mantendo as definições abertas. A pequena pré-visualização Windows reduz o mundo completo. OK guarda; Cancelar ou Esc descarta alterações. Mover o rato ou premir uma tecla termina a proteção de ecrã inteiro. A gravação MP4 está disponível no EXE.

### Posição e estado das janelas

Ao fechar, são guardadas separadamente as posições das janelas principal e Acerca de; a Ajuda guarda também o tamanho e o estado normal ou maximizado anterior à minimização. Isto é independente da confirmação das definições da aplicação. Sair da aplicação fecha também Ajuda e Acerca de.

### Renderização e licenças dos padrões

A evolução e as comparações visíveis usam shaders Direct3D 11 na GPU; existe renderização por software se falhar a inicialização do hardware. Cada ecrã usa o regulador de fotogramas testado à sua frequência. MP4 requer Media Foundation e um codificador H.264. Os padrões vêm de LifeWiki (GFDL 1.2 ou posterior) e das coleções de domínio público de Alan Hensel. O código é MIT; avisos e licenças do catálogo são separados.

[Fontes dos padrões, licenças e pormenores de importação](../GameOfLife/LifePatternsLicense.txt)

`GameOfLife.exe` · `GameOfLife.scr`

## FlyingSolids · FlightCorridor · SpaceFlight

### MONITORES

A seleção das linhas determina os ecrãs a configurar e é independente das caixas que ativam as saídas de animação. Ctrl+A seleciona todos os ecrãs; Ctrl e Shift alteram a seleção. Todas as opções e controlos deslizantes da animação aplicam-se aos ecrãs selecionados. A seleção é guardada separadamente para EXE e SCR. Se todos estavam selecionados, os novos ecrãs também são incluídos. Valores diferentes entre os ecrãs selecionados são indicados por caixas de verificação indeterminadas e por um padrão pontilhado nos botões de opção, nas pegas dos controlos deslizantes e nos botões «Ativar tudo» e «Desativar tudo». As etiquetas dos controlos deslizantes apresentam um travessão em vez de um valor comum. Alterar uma opção ou clicar num controlo deslizante aplica esse valor a todos os ecrãs selecionados.

### CONTROLOS

Ative ou desative as saídas de animação através das caixas dos ecrãs ou com um duplo clique nas respetivas linhas. Cada monitor usa uma cena independente. Captura guarda BMP/GIF/JPEG/PNG/TIFF/WebP e o botão de gravação inicia ou termina MP4. Pausa para a animação. A aplicação também instala ou desinstala a proteção de ecrã incorporada. As definições são guardadas continuamente. A aplicação só pode ter uma instância em execução. Um novo arranque restaura a janela de controlo minimizada e coloca-a em primeiro plano. Use Tab e Shift+Tab para passar entre controlos; Alt e a letra sublinhada ativam um comando. Esc fecha a janela ativa de Ajuda ou Acerca de; na janela de controlo, termina a aplicação. A pausa e o bloqueio da proteção de ecrã aplicam-se a toda a aplicação, independentemente dos ecrãs selecionados. Com o bloqueio ativo, a proteção de ecrã do Windows só é impedida enquanto existir animação visível e não pausada em pelo menos um ecrã.

### CAPTURAS E GRAVAÇÃO

As capturas e gravações usam o primeiro monitor de animação ativo, não uma imagem conjunta de todos os monitores. BMP/GIF/JPEG/PNG/TIFF/WebP usa Imagens, MP4 Vídeos; se essas pastas não existirem, usa-se Documentos. O botão Definições de gravação permite escolher Viewport ou TV. Viewport conserva as dimensões e a frequência de atualização do monitor de animação, até 60 fotogramas por segundo. TV oferece 1920 × 1080, 1440 × 1080 ou 1280 × 720 no formato 16:9, a 50, 25, 59.94 (60000/1001) ou 29.97 (30000/1001) fotogramas por segundo. A proporção da imagem é mantida; TV usa vídeo progressivo BT.709 com intervalo limitado e amostragem 4:2:0. A resolução e a frequência só estão disponíveis no modo TV. A janela Definições de gravação pode ser minimizada e não bloqueia as outras janelas da aplicação. OK guarda as escolhas para a próxima gravação MP4; Cancelar ou Esc descarta as alterações não confirmadas. A saída de animação do monitor gravado não pode ser desativada durante a gravação; as alterações aos outros monitores não a interrompem. Fechar a aplicação durante uma gravação exige confirmação, pois também termina a gravação.

### PRÉ-VISUALIZAÇÃO E CONTROLOS

Ativar pré-visualização inicia uma pré-visualização em ecrã inteiro em todos os monitores e permite ajustes em tempo real. OK guarda as definições e Cancelar descarta-as. Esc ou o movimento do rato termina a proteção em ecrã inteiro. Use Tab e Shift+Tab para passar entre controlos; Alt e a letra sublinhada ativam um comando. Esc nas definições equivale a Cancelar; na Ajuda ou em Acerca de, fecha apenas essa janela.

### Requisitos do sistema

Os sistemas Windows 7 a Windows 11 suportam todas as funcionalidades, incluindo capturas BMP/GIF/JPEG/PNG/TIFF/WebP e gravação MP4. Para executar a aplicação no Windows Vista SP2, é necessário instalar as atualizações KB971512 e KB2117917. A gravação MP4 não funciona no Vista na versão atual. A apresentação requer Direct3D 11, não apenas um runtime DirectX mais antigo. A gravação MP4 requer componentes Media Foundation e um codificador H.264 disponíveis. A aplicação autónoma também pode ser executada no Linux através do Wine; a integração como proteção de ecrã está disponível apenas no Windows.

## Compilação

Abra `DispSavers.slnx` no Visual Studio com MSVC v145 e um Windows SDK. Selecione `Release | x86` e recompile a solução para criar `Release\FlyingSolids.exe`, `Release\FlightCorridor.exe`, `Release\GameOfLife.exe`, `Release\GameOfLife.scr`, `Release\SpaceFlight.exe` e `Release\FlyingSolids.scr`, `Release\FlightCorridor.scr`, `Release\SpaceFlight.scr`. Não existe configuração x64.

Execute `PackageRelease.ps1` sem parâmetros de assinatura para empacotar estes ficheiros compilados. O script utiliza cópias temporárias, não altera os ficheiros em `Release` e apenas verifica as assinaturas válidas existentes. Cria o único arquivo `DispSavers-<version>-win32.zip`, contendo `FlyingSolids\FlyingSolids.exe`, `FlyingSolids\FlyingSolids.scr`, `FlyingSolids\license.txt`, `FlightCorridor\FlightCorridor.exe`, `FlightCorridor\FlightCorridor.scr`, `FlightCorridor\license.txt`, `GameOfLife\GameOfLife.exe`, `GameOfLife\GameOfLife.scr`, `GameOfLife\license.txt`, `SpaceFlight\SpaceFlight.exe`, `SpaceFlight\SpaceFlight.scr` e `SpaceFlight\license.txt`. O ZIP anterior é removido no início da execução; uma falha de verificação impede a criação de um novo arquivo.

## Licença

O DispSavers é disponibilizado sob a [licença MIT](../license.txt). Copyright © Petr Červinka — FortSoft 2026

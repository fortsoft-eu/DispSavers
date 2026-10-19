# FlyingSolids

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · **Español** · [Italiano](README.it-IT.md) · [Português](README.pt-PT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [Dansk](README.da-DK.md) · [Suomi](README.fi-FI.md) · [Íslenska](README.is-IS.md) · [Norsk (bokmål)](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Türkçe](README.tr-TR.md) · [Eesti](README.et-EE.md) · [Gaeilge](README.ga-IE.md) · [Lietuvių](README.lt-LT.md) · [Latviešu](README.lv-LV.md) · [Magyar](README.hu-HU.md) · [Malti](README.mt-MT.md) · [Nederlands](README.nl-NL.md) · [Română](README.ro-RO.md) · [Ελληνικά](README.el-GR.md) · [Bosanski](README.bs-Latn-BA.md) · [Hrvatski](README.hr-HR.md) · [Slovenščina](README.sl-SI.md) · [Crnogorski](README.cnr-Latn-ME.md) · [Беларуская](README.be-BY.md) · [Български](README.bg-BG.md) · [Македонски](README.mk-MK.md) · [Српски](README.sr-Cyrl-RS.md) · [Українська](README.uk-UA.md) · [Русский](README.ru-RU.md)

FlyingSolids es una aplicación nativa Win32/x86 con Direct3D y un salvapantallas de Windows que muestra sólidos geométricos tridimensionales iluminados. Los sólidos se mueven y giran de forma independiente y rebotan sin atravesarse.

La selección de filas determina qué pantallas se están configurando; es independiente de las casillas que activan las salidas de animación. Ctrl+A selecciona todas; Ctrl y Mayús modifican la selección. Todas las opciones y los controles deslizantes de animación se aplican a las pantallas seleccionadas. La selección se recuerda por separado para EXE y SCR. Si estaban seleccionadas todas, se incluyen también las nuevas.

## Características

- **Observación del espacio** y **Vuelo por el espacio** en línea recta. Seleccione una o varias pantallas en la lista. El modo de cámara, los objetos, la iluminación, las velocidades, el tamaño y el número de copias se aplican solo a las pantallas seleccionadas. Cada pantalla guarda sus propios ajustes.
- Control independiente de la luz principal, de relleno, ambiental y de contornos
- Una escena independiente por cada monitor seleccionado
- De una a diez copias de cada sólido activado
- Velocidad de objetos y cámara del 0 al 1600 %; tamaño del 50 al 200 %
- Superficies brillantes, iluminación, colores individuales y colisiones
- Renderizado adaptado a la frecuencia de actualización de cada monitor
- Capturas PNG y grabación MP4 en la aplicación independiente
- Configuraciones separadas para aplicación y salvapantallas
- 30 tipos de sólidos e interfaz en 36 idiomas

## Sólidos

Cubo; Pirámide cuadrangular regular; Tronco de pirámide cuadrangular; Pirámide cuadrangular, corte oblicuo; Pirámide cuadrada, corte normal a la base; Prisma triangular regular; Prisma pentagonal regular; Prisma hexagonal regular; Octaedro regular; Bipirámide pentagonal; Cono circular recto; Tronco de cono; Cono truncado por un plano oblicuo; Cono, corte perpendicular a la base; Cilindro circular recto; Cilindro hueco; Cilindro hueco con extremos toroidales; Paraboloide de revolución cerrado por plano; Esfera; Hemisferio; Segmento esférico; Segmento esférico mayor; Segmento esférico de dos bases; Elipsoide triaxial; Esferoide prolato; Esferoide oblato; Ovoide; Esferocilindro; Disco redondeado (spheroplatelet); Toro.

## Iluminación

Las casillas `Luz principal`, `Luz de relleno`, `Luz ambiental` e `Iluminación de contornos` bajo los controles deslizantes controlan de forma independiente la iluminación de toda la escena. La luz ambiental aporta iluminación básica a las superficies y la iluminación de contornos resalta sus bordes. Los ajustes se guardan por separado para la aplicación y el salvapantallas.

## Aplicación y salvapantallas

`FlyingSolids.exe` mantiene una única ventana de control mientras se ejecuta la animación. Es posible seleccionar varios monitores, alternar uno con doble clic o desconectarlos todos. El EXE instala o desinstala el salvapantallas que lleva incorporado. La aplicación solo permite una instancia. Al volver a iniciarla, restaura la ventana de control minimizada y la trae al primer plano. Use Tab y Mayús+Tab para desplazarse entre controles; Alt y la letra subrayada activan una opción. Esc cierra la ventana activa de Ayuda o Acerca de; en la ventana de control, sale de la aplicación. Las capturas y grabaciones usan el primer monitor de animación activo, no una imagen conjunta de todos los monitores. PNG usa Imágenes y MP4 Vídeos; si no existen esas carpetas, se usa Documentos. El botón Ajustes de grabación permite elegir Viewport o TV. Viewport conserva las dimensiones y la frecuencia de actualización del monitor de animación, hasta 60 fotogramas por segundo. TV ofrece 1920 × 1080, 1440 × 1080 o 1280 × 720 en formato 16:9, a 50, 25, 59.94 (60000/1001) o 29.97 (30000/1001) fotogramas por segundo. Se conserva la relación de aspecto; TV usa vídeo progresivo BT.709 de rango limitado y submuestreo 4:2:0. La resolución y la frecuencia solo están disponibles en modo TV. La ventana Ajustes de grabación se puede minimizar y no bloquea las demás ventanas de la aplicación. Aceptar guarda las opciones para la próxima grabación MP4; Cancelar o Esc descarta los cambios sin confirmar. El monitor grabado no se puede desmarcar durante la grabación; cambiar otros monitores no la detiene. Cerrar la aplicación durante una grabación requiere confirmación porque también detiene la grabación. Bloquear salvapantallas durante la animación impide que se inicie el salvapantallas de Windows solo mientras la animación está realmente visible y no está en pausa. `FlyingSolids.scr` tiene su propio cuadro de configuración, sin grabación. En pantalla completa crea una escena independiente en cada monitor. Activar vista previa en la configuración inicia una vista previa independiente a pantalla completa en todos los monitores. Usa los ajustes actuales, permite cambios en tiempo real y se puede detener. Cualquier tecla, un movimiento del ratón o un clic cierra el salvapantallas a pantalla completa. Esc en la configuración equivale a Cancelar; en Ayuda o Acerca de, cierra únicamente esa ventana.

## Almacenamiento

```text
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\Standalone
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\ScreenSaver
```

## Requisitos del sistema

Windows 7 a Windows 11 admiten todas las funciones, incluidas las capturas PNG y la grabación MP4. Para ejecutar la aplicación en Windows Vista SP2, es necesario instalar las actualizaciones KB971512 y KB2117917. La grabación MP4 no funciona en Vista en la versión actual. La representación requiere Direct3D 11, no solo un entorno de ejecución antiguo de DirectX. La grabación MP4 requiere componentes de Media Foundation y un codificador H.264 disponibles.

## Compilación

Abra `DispSavers.slnx` en Visual Studio con MSVC v145 y un SDK de Windows. Seleccione `Release | x86` y recompile la solución para generar `Release\FlyingSolids.exe` y `Release\FlyingSolids.scr`. No hay configuración x64. En las propiedades del proyecto `FlyingSolids`, página `Signing`, indique el nombre o la huella de un certificado válido de firma de código con clave privada en el almacén `Personal (My)` del usuario actual. Los ajustes se aplican al EXE y al SCR y se guardan en `FlyingSolids.vcxproj.user`, ignorado por Git. SignTool se busca automáticamente en PATH o en el SDK de Windows. Si usa SimplySign, inicie sesión en SimplySign Desktop antes de compilar. Primero se firma el SCR y se añade un sello de tiempo RFC 3161 SHA-256 obligatorio del servidor de sellado de tiempo configurado; después se incorpora al EXE, que también se firma y recibe un sello de tiempo. Indique la URL del servidor de sellado de tiempo RFC 3161 en el campo `Timestamp server`. Cualquier error de firma, sellado de tiempo o verificación detiene la compilación; los archivos con firmas válidas y sello de tiempo no se vuelven a firmar.

Ejecute `PackageRelease.ps1` sin parámetros de firma para empaquetar los archivos compilados. El script utiliza copias temporales, no modifica los archivos de `Release` y solo verifica las firmas válidas existentes. Crea el único archivo `DispSavers-<version>-win32.zip` con `FlyingSolids\FlyingSolids.exe`, `FlyingSolids\FlyingSolids.scr`, `FlyingSolids\license.txt`, `FlightCorridor\FlightCorridor.exe`, `FlightCorridor\FlightCorridor.scr`, `FlightCorridor\license.txt`, `SpaceFlight\SpaceFlight.exe`, `SpaceFlight\SpaceFlight.scr` y `SpaceFlight\license.txt`. El ZIP anterior se elimina al comenzar; un error de verificación impide crear un archivo nuevo.

## Licencia

FlyingSolids se distribuye bajo la [licencia MIT](../license.txt). Copyright © Petr Červinka — FortSoft 2026

## FlightCorridor

FlightCorridor ofrece Vuelo entre cuatro superficies deformables y Vuelo por un embudo deformable. Asigne exactamente un vuelo a cada monitor: seleccione su fila y el botón de opción correspondiente.

`Release\FlightCorridor.exe` · `Release\FlightCorridor.scr` · [FlightCorridor](../FlightCorridor/README.es-ES.md)

## SpaceFlight

SpaceFlight ofrece „Superficie ondulante infinita“ y „Vuelo de larga distancia — superficie deformable“. Asigne exactamente un vuelo a cada monitor: seleccione su fila y el botón de opción correspondiente.

`Release\SpaceFlight.exe` · `Release\SpaceFlight.scr` · [SpaceFlight](../SpaceFlight/README.es-ES.md)

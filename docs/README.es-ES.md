# FlyingSolids

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · **Español** · [Italiano](README.it-IT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Português](README.pt-PT.md) · [Norsk](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Suomi](README.fi-FI.md) · [Dansk](README.da-DK.md) · [Íslenska](README.is-IS.md) · [Türkçe](README.tr-TR.md)

FlyingSolids es una aplicación nativa Win32/x86 con Direct3D y un salvapantallas de Windows que muestra sólidos geométricos tridimensionales iluminados. Los sólidos se mueven y giran de forma independiente y rebotan sin atravesarse. Las condiciones iniciales y las posiciones recicladas durante el vuelo proceden del generador criptográfico de Windows y se almacenan en bloques para reducir la carga de CPU.

## Características

- **Observación del espacio** y **Vuelo por el espacio** en línea recta
- Activación independiente de la luz principal y la luz de relleno
- Una escena independiente por cada monitor seleccionado
- De una a diez copias de cada sólido activado
- Velocidad de objetos y cámara del 0 al 1600 %; tamaño del 50 al 200 %
- Superficies brillantes, iluminación, colores individuales y colisiones
- Renderizado adaptado a la frecuencia de actualización de cada monitor
- Capturas PNG y grabación MP4 en la aplicación independiente
- Configuraciones separadas para aplicación y salvapantallas
- 27 tipos de sólidos e interfaz en 17 idiomas

## Sólidos

El catálogo incluye poliedros, prismas regulares, pirámides y sus cortes planos, conos y cilindros y sus cortes planos, un paraboloide de revolución cerrado por un plano, sólidos derivados de la esfera, elipsoides, un ovoide, un esferocilindro y un toro. La interfaz usa la terminología geométrica especializada en español.

## Iluminación

Las casillas `Luz principal` y `Luz de relleno` bajo los controles deslizantes de la derecha activan o desactivan las dos luces de forma independiente para toda la escena. De forma predeterminada, `Luz principal` está activada y `Luz de relleno` está desactivada. Los ajustes de iluminación se guardan por separado para la aplicación y el salvapantallas.

## Aplicación y salvapantallas

`FlyingSolids.exe` mantiene una única ventana de control mientras se ejecuta la animación. Es posible seleccionar varios monitores, alternar uno con doble clic o desconectarlos todos. Los PNG se guardan por defecto en **Imágenes** y los MP4 en **Vídeos**; **Documentos** es la alternativa. El EXE instala o desinstala el salvapantallas que lleva incorporado.

La aplicación solo permite una instancia. Al volver a iniciarla, restaura la ventana de control minimizada, la redibuja y la trae al primer plano.

Use Tab y Mayús+Tab para desplazarse entre controles; Alt y la letra subrayada activan una opción. Esc cierra la ventana activa de Ayuda o Acerca de; en la ventana de control, sale de la aplicación.

Las capturas y grabaciones usan el primer monitor de animación activo, no una imagen conjunta de todos los monitores. PNG usa Imágenes y MP4 Vídeos; si no existen esas carpetas, se usa Documentos. La grabación MP4 sigue la frecuencia del monitor, con un máximo de 60 fotogramas por segundo.

`FlyingSolids.scr` tiene su propio cuadro de configuración, sin grabación. En pantalla completa crea una escena independiente en cada monitor.

Activar vista previa en la configuración inicia una vista previa independiente a pantalla completa en todos los monitores. Usa los ajustes actuales, permite cambios en tiempo real y se puede detener. Cualquier tecla, un movimiento del ratón o un clic cierra el salvapantallas a pantalla completa.

Esc en la configuración equivale a Cancelar; en Ayuda o Acerca de, cierra únicamente esa ventana.

## Almacenamiento

```text
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\Standalone
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\ScreenSaver
```

## Requisitos del sistema

Windows 7 a Windows 11 admiten todas las funciones, incluidas las capturas PNG y la grabación MP4.

Windows Vista SP2: KB971512, KB2117917. La grabación MP4 no funciona en Vista en la versión actual.

La representación requiere Direct3D 11, no solo un entorno de ejecución antiguo de DirectX. La grabación MP4 requiere componentes de Media Foundation y un codificador H.264 disponibles.

## Compilación

Abra `DispSavers.slnx`, seleccione `Release | x86` y recompile la solución con MSVC v145 y un SDK de Windows. Se generan el EXE y el SCR. `PackageRelease.ps1` crea el único paquete `DispSavers-<version>-win32.zip` de la solución, con los archivos y `license.txt` en el subdirectorio `FlyingSolids`. No hay configuración x64.

## Licencia

FlyingSolids se distribuye bajo la [licencia MIT](../license.txt).

Copyright © Petr Červinka — FortSoft 2026

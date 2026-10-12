# FlyingSolids

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · **Polski** · [Slovenčina](README.sk-SK.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Português](README.pt-PT.md) · [Norsk](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Suomi](README.fi-FI.md) · [Dansk](README.da-DK.md) · [Íslenska](README.is-IS.md) · [Türkçe](README.tr-TR.md)

FlyingSolids to natywna aplikacja Win32/x86 korzystająca z Direct3D oraz wygaszacz ekranu Windows. Wyświetla oświetlone, pełne bryły geometryczne 3D. Bryły poruszają się i obracają niezależnie oraz odbijają się bez przenikania. Warunki początkowe i ponownie wyznaczane pozycje w locie pochodzą z kryptograficznego generatora Windows; buforowanie ogranicza obciążenie procesora.

## Funkcje

- **Obserwacja przestrzeni** i prostoliniowy **Przelot przez przestrzeń**
- Niezależne włączanie światła głównego i wypełniającego
- Niezależna scena na każdym wybranym monitorze
- Od jednej do dziesięciu kopii każdej włączonej bryły
- Prędkość obiektów i kamery 0–1600%, rozmiar 50–200%
- Błyszczące oświetlenie, osobne kolory i obsługa zderzeń
- Renderowanie dopasowane do częstotliwości odświeżania monitorów
- Zrzuty PNG i nagrywanie MP4 w aplikacji samodzielnej
- Oddzielne ustawienia aplikacji i wygaszacza
- 30 rodzajów brył oraz interfejs w 17 językach

## Bryły

Katalog obejmuje wielościany, graniastosłupy prawidłowe, ostrosłupy i ich przekroje płaskie, stożki i walce oraz ich przekroje, paraboloidę obrotową zamkniętą płaszczyzną, bryły pochodne kuli, elipsoidy, owoidę, sferocylinder i torus. Interfejs stosuje uznaną polską terminologię geometryczną.

- Sferoida wydłużona ma jedną dłuższą półoś i dwie jednakowe krótsze półosie.
- Zaokrąglony dysk (spheroplatelet) ma dwie płaskie powierzchnie kołowe i gładko zaokrąglony brzeg; jego średnica jest nieco większa niż średnica warstwy kulistej, a grubość jest o połowę mniejsza.
- Walec pusty z toroidalnymi końcami ma zewnętrzną i wewnętrzną powierzchnię walcową połączone półtorusami, które w przekroju osiowym tworzą dokładne półokręgi.

## Oświetlenie

Pola wyboru `Światło główne` i `Światło wypełniające` pod prawymi suwakami niezależnie włączają lub wyłączają oba światła dla całej sceny. Domyślnie `Światło główne` jest włączone, a `Światło wypełniające` wyłączone. Ustawienia oświetlenia są zapisywane osobno dla aplikacji i wygaszacza ekranu.

## Aplikacja i wygaszacz

`FlyingSolids.exe` pozostawia jedno okno sterowania podczas animacji. Można zaznaczyć kilka monitorów, przełączać monitor podwójnym kliknięciem albo odłączyć wszystkie. Pliki PNG trafiają domyślnie do **Obrazy**, MP4 do **Wideo**, a katalogiem zastępczym są **Dokumenty**. EXE instaluje i odinstalowuje wbudowany wygaszacz.

Aplikacja działa tylko w jednej instancji. Kolejne uruchomienie przywraca zminimalizowane okno sterowania, odświeża je i przenosi na pierwszy plan.

Klawisze Tab i Shift+Tab przełączają między kontrolkami; Alt i podkreślona litera wywołują polecenie. Esc zamyka aktywne okno Pomocy lub O programie; w oknie sterowania kończy działanie aplikacji.

Zrzuty i nagrania obejmują pierwszy aktywny monitor animacji, a nie wspólny obraz wszystkich monitorów. PNG używa folderu Obrazy, MP4 folderu Wideo; jeśli ich nie ma, używane są Dokumenty. Nagranie MP4 odpowiada częstotliwości monitora, najwyżej jednak 60 klatkom na sekundę.

`FlyingSolids.scr` ma własne ustawienia bez nagrywania. Tryb pełnoekranowy uruchamia niezależną scenę na każdym monitorze.

Włącz podgląd w ustawieniach uruchamia osobny podgląd pełnoekranowy na wszystkich monitorach. Używa bieżących ustawień, pozwala zmieniać je na bieżąco i można go zatrzymać. Dowolny klawisz, ruch myszy lub kliknięcie kończy wygaszacz pełnoekranowy.

Esc w ustawieniach odpowiada przyciskowi Anuluj; w Pomocy lub O programie zamyka tylko to okno.

## Ustawienia

```text
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\Standalone
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\ScreenSaver
```

## Wymagania systemowe

Systemy od Windows 7 do Windows 11 obsługują wszystkie funkcje, w tym zrzuty PNG i nagrywanie MP4.

Do uruchomienia aplikacji w systemie Windows Vista SP2 konieczne jest zainstalowanie aktualizacji KB971512 i KB2117917. Nagrywanie MP4 nie działa w Vista w obecnej wersji.

Wyświetlanie wymaga Direct3D 11, a nie tylko starszego środowiska DirectX. Nagrywanie MP4 wymaga dostępnych składników Media Foundation i kodera H.264.

## Kompilowanie

Otwórz `DispSavers.slnx`, wybierz `Release | x86` i przebuduj rozwiązanie za pomocą MSVC v145 oraz Windows SDK. Powstaną pliki EXE i SCR. `PackageRelease.ps1` tworzy jeden pakiet rozwiązania `DispSavers-<version>-win32.zip`, zawierający pliki i `license.txt` w podkatalogu `FlyingSolids`. Konfiguracja x64 nie jest dostępna.

## Licencja

FlyingSolids jest udostępniany na [licencji MIT](../license.txt).

Copyright © Petr Červinka — FortSoft 2026

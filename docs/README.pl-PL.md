# FlyingSolids

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · **Polski** · [Slovenčina](README.sk-SK.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Português](README.pt-PT.md) · [Norsk](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Suomi](README.fi-FI.md) · [Dansk](README.da-DK.md) · [Íslenska](README.is-IS.md) · [Türkçe](README.tr-TR.md)

FlyingSolids to natywna aplikacja Win32/x86 korzystająca z Direct3D oraz wygaszacz ekranu Windows. Wyświetla oświetlone, pełne bryły geometryczne 3D. Bryły poruszają się i obracają niezależnie oraz odbijają się bez przenikania.

## Funkcje

- **Obserwacja przestrzeni** i prostoliniowy **Przelot przez przestrzeń**
- Niezależne sterowanie światłem głównym, wypełniającym, otoczenia i oświetleniem konturów
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

## Oświetlenie

Pola wyboru `Światło główne`, `Światło wypełniające`, `Światło otoczenia` i `Oświetlenie konturów` pod suwakami niezależnie sterują oświetleniem całej sceny. Światło otoczenia zapewnia podstawową jasność powierzchni, a oświetlenie konturów podkreśla krawędzie. Domyślnie światło główne, światło otoczenia i oświetlenie konturów są włączone, a światło wypełniające jest wyłączone. Ustawienia są zapisywane osobno dla aplikacji i wygaszacza ekranu.

## Aplikacja i wygaszacz

`FlyingSolids.exe` pozostawia jedno okno sterowania podczas animacji. Można zaznaczyć kilka monitorów, przełączać monitor podwójnym kliknięciem albo odłączyć wszystkie. EXE instaluje i odinstalowuje wbudowany wygaszacz. Aplikacja działa tylko w jednej instancji. Kolejne uruchomienie przywraca zminimalizowane okno sterowania i przenosi na pierwszy plan. Klawisze Tab i Shift+Tab przełączają między kontrolkami; Alt i podkreślona litera wywołują polecenie. Esc zamyka aktywne okno Pomocy lub O programie; w oknie sterowania kończy działanie aplikacji. Zrzuty i nagrania obejmują pierwszy aktywny monitor animacji, a nie wspólny obraz wszystkich monitorów. PNG używa folderu Obrazy, MP4 folderu Wideo; jeśli ich nie ma, używane są Dokumenty. Przycisk Ustawienia nagrywania pozwala wybrać Viewport lub TV. Viewport zachowuje rozmiar i częstotliwość odświeżania monitora animacji, do 60 klatek na sekundę. TV oferuje 1920 × 1080, 1440 × 1080 lub 1280 × 720 w formacie 16:9, z 50, 25, 59.94 (60000/1001) lub 29.97 (30000/1001) klatkami na sekundę. Proporcje obrazu są zachowane; TV używa progresywnego obrazu BT.709 z ograniczonym zakresem i próbkowaniem 4:2:0. Rozdzielczość i liczba klatek są dostępne tylko w trybie TV. Okno Ustawienia nagrywania można zminimalizować i nie blokuje ono innych okien aplikacji. OK zapisuje wybór dla następnego nagrania MP4; Anuluj lub Esc odrzuca niepotwierdzone zmiany. Podczas nagrywania nie można odznaczyć nagrywanego monitora; zmiany pozostałych monitorów nie przerywają nagrania. Zamknięcie aplikacji podczas nagrywania wymaga potwierdzenia, ponieważ kończy również nagranie. Blokuj wygaszacz podczas animacji zapobiega uruchomieniu wygaszacza Windows tylko wtedy, gdy animacja jest rzeczywiście widoczna i nie jest wstrzymana. `FlyingSolids.scr` ma własne ustawienia bez nagrywania. Tryb pełnoekranowy uruchamia niezależną scenę na każdym monitorze. Włącz podgląd w ustawieniach uruchamia osobny podgląd pełnoekranowy na wszystkich monitorach. Używa bieżących ustawień, pozwala zmieniać je na bieżąco i można go zatrzymać. Dowolny klawisz, ruch myszy lub kliknięcie kończy wygaszacz pełnoekranowy. Esc w ustawieniach odpowiada przyciskowi Anuluj; w Pomocy lub O programie zamyka tylko to okno.

## Ustawienia

```text
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\Standalone
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\ScreenSaver
```

## Wymagania systemowe

Systemy od Windows 7 do Windows 11 obsługują wszystkie funkcje, w tym zrzuty PNG i nagrywanie MP4. Do uruchomienia aplikacji w systemie Windows Vista SP2 konieczne jest zainstalowanie aktualizacji KB971512 i KB2117917. Nagrywanie MP4 nie działa w Vista w obecnej wersji. Wyświetlanie wymaga Direct3D 11, a nie tylko starszego środowiska DirectX. Nagrywanie MP4 wymaga dostępnych składników Media Foundation i kodera H.264.

## Kompilowanie

Otwórz `DispSavers.slnx` w Visual Studio z MSVC v145 i Windows SDK. Wybierz `Release | x86` i przebuduj rozwiązanie, aby utworzyć `Release\FlyingSolids.exe` oraz `Release\FlyingSolids.scr`. Konfiguracja x64 nie jest dostępna. Podpisywanie jest domyślnie włączone dla Release i Debug. We właściwościach projektu `FlyingSolids`, na stronie `Signing`, podaj nazwę lub odcisk ważnego certyfikatu podpisywania kodu z kluczem prywatnym w magazynie `Personal (My)` bieżącego użytkownika. Ustawienia dotyczą EXE i SCR i są zapisywane w pliku `FlyingSolids.vcxproj.user`, ignorowanym przez Git. SignTool jest automatycznie wyszukiwany w PATH lub Windows SDK. Jeśli korzystasz z SimplySign, przed kompilacją zaloguj się do SimplySign Desktop. Najpierw podpisywany jest SCR i dodawany jest obowiązkowy znacznik czasu RFC 3161 SHA-256 z ustawionego serwera znaczników czasu, następnie SCR jest osadzany w EXE, który również otrzymuje podpis i znacznik czasu. W polu `Timestamp server` podaj adres URL serwera znaczników czasu RFC 3161. Błąd podpisywania, znacznika czasu lub weryfikacji przerywa kompilację; pliki z prawidłowym podpisem i znacznikiem czasu nie są podpisywane ponownie.

Uruchom `PackageRelease.ps1` bez parametrów podpisywania, aby spakować zbudowane pliki. Skrypt używa kopii tymczasowych, nie zmienia plików w `Release` i jedynie weryfikuje istniejące prawidłowe podpisy. Tworzy jeden plik `DispSavers-<version>-win32.zip` zawierający `FlyingSolids\FlyingSolids.exe`, `FlyingSolids\FlyingSolids.scr` oraz `FlyingSolids\license.txt`. Poprzedni ZIP jest usuwany na początku uruchomienia; błąd weryfikacji uniemożliwia utworzenie nowego archiwum.

## Licencja

FlyingSolids jest udostępniany na [licencji MIT](../license.txt). Copyright © Petr Červinka — FortSoft 2026

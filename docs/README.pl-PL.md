# DispSavers

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Português](README.pt-PT.md) · **Polski** · [Slovenčina](README.sk-SK.md) · [Dansk](README.da-DK.md) · [Suomi](README.fi-FI.md) · [Íslenska](README.is-IS.md) · [Norsk (bokmål)](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Türkçe](README.tr-TR.md) · [Eesti](README.et-EE.md) · [Gaeilge](README.ga-IE.md) · [Lietuvių](README.lt-LT.md) · [Latviešu](README.lv-LV.md) · [Magyar](README.hu-HU.md) · [Malti](README.mt-MT.md) · [Nederlands](README.nl-NL.md) · [Română](README.ro-RO.md) · [Ελληνικά](README.el-GR.md) · [Bosanski](README.bs-Latn-BA.md) · [Hrvatski](README.hr-HR.md) · [Slovenščina](README.sl-SI.md) · [Crnogorski](README.cnr-Latn-ME.md) · [Беларуская](README.be-BY.md) · [Български](README.bg-BG.md) · [Македонски](README.mk-MK.md) · [Српски](README.sr-Cyrl-RS.md) · [Українська](README.uk-UA.md) · [Русский](README.ru-RU.md)

## FlyingSolids

Sprzętowo przyspieszana animacja pełnych obiektów 3D.

Zaznacz jeden lub więcej monitorów na liście. Tryb kamery, wybór brył, oświetlenie, prędkości, rozmiar i liczba kopii dotyczą tylko zaznaczonych monitorów. Każdy monitor zapamiętuje własne ustawienia. FlyingSolids wyświetla oświetlone pełne bryły 3D. Suwaki ustawiają prędkość obiektów i kamery od 0 do 1600%, od jednej do dziesięciu kopii i rozmiar od 50 do 200%. Wybierz Obserwację przestrzeni lub prostoliniowy Przelot przez przestrzeń i włącz potrzebne bryły. Pola wyboru Światło główne, Światło wypełniające, Światło otoczenia i Oświetlenie konturów pod suwakami niezależnie sterują oświetleniem zaznaczonych monitorów. Światło otoczenia zapewnia podstawową jasność powierzchni, a oświetlenie konturów podkreśla krawędzie. Ustawienia są zapisywane osobno dla aplikacji i wygaszacza ekranu.

`FlyingSolids.exe` · `FlyingSolids.scr`

## FlightCorridor

Sprzętowo przyspieszany przelot przez zmienny korytarz i lejek.

FlightCorridor: Przelot między czterema zmiennymi powierzchniami; Przelot przez zmienny lejek. Każdemu monitorowi przypisz dokładnie jedną animację. Tekstura przełącza powierzchnie z teksturą i model szkieletowy. Swobodne obracanie kamery powoli zmienia kierunek widoku we wszystkich trzech wymiarach. Przerwy i nawroty dodają losowe zwalnianie, pauzy i odwracanie obrotu; lot do przodu trwa nadal. Prędkość wynosi 0–1600%. Każdy monitor ma niezależną losową scenę wyświetlaną z własną częstotliwością odświeżania. Światło główne, światło wypełniające, światło otoczenia i oświetlenie konturów można przełączać niezależnie dla zaznaczonych monitorów. Oświetlenie dotyczy tylko powierzchni z teksturą.

`FlightCorridor.exe` · `FlightCorridor.scr`

## SpaceFlight

Sprzętowo przyspieszany lot nad falującymi i zmiennymi powierzchniami.

SpaceFlight: Nieskończona falująca powierzchnia; Lot dalekodystansowy — zmienna powierzchnia; Lot przez przestrzeń zakrzywioną grawitacyjnie. Każdemu monitorowi przypisz dokładnie jedną animację. Tekstura przełącza powierzchnie z teksturą i model szkieletowy. Swobodne obracanie kamery powoli zmienia kierunek widoku we wszystkich trzech wymiarach. Przerwy i nawroty dodają losowe zwalnianie, pauzy i odwracanie obrotu; lot do przodu trwa nadal. Prędkość wynosi 0–1600%. Każdy monitor ma niezależną losową scenę wyświetlaną z własną częstotliwością odświeżania. Światło główne, światło wypełniające, światło otoczenia i oświetlenie konturów można przełączać niezależnie dla zaznaczonych monitorów. Oświetlenie dotyczy tylko powierzchni z teksturą. Obie animacje powierzchni oferują płaszczyznę, falowanie lub lej. Lej wciąga kamerę do środka po opadającej spirali. Lot przez przestrzeń zakrzywioną grawitacyjnie przedstawia trójwymiarową siatkę szkieletową. Opcje tekstury, kształtu powierzchni i oświetlenia dotyczą tylko dwóch animacji powierzchni.

`SpaceFlight.exe` · `SpaceFlight.scr`

## MONITORY

Zaznaczenie wierszy określa konfigurowane monitory i jest niezależne od pól wyboru włączających wyjścia animacji. Ctrl+A zaznacza wszystkie monitory; Ctrl i Shift zmieniają zaznaczenie. Wszystkie opcje i suwaki animacji dotyczą zaznaczonych monitorów. Zaznaczenie jest zapamiętywane osobno dla EXE i SCR. Jeśli zaznaczone były wszystkie monitory, nowe również zostaną zaznaczone. Różne wartości na zaznaczonych monitorach są sygnalizowane nieokreślonym stanem pól wyboru i kropkowaniem przycisków opcji, uchwytów suwaków oraz przycisków „Włącz wszystko” i „Wyłącz wszystko”. Etykiety suwaków pokazują kreskę zamiast wspólnej wartości. Zmiana opcji lub kliknięcie suwaka ustawia tę wartość na wszystkich zaznaczonych monitorach.

## OBSŁUGA

Wyjścia animacji można włączać i wyłączać polami wyboru przy monitorach lub podwójnym kliknięciem ich wierszy. Każdy monitor ma niezależną scenę. Zrzut zapisuje PNG, a przycisk nagrywania rozpoczyna lub kończy MP4. Wstrzymaj zatrzymuje animację. Aplikacja instaluje i odinstalowuje również wbudowany wygaszacz. Ustawienia są zapisywane na bieżąco. Aplikacja działa tylko w jednej instancji. Kolejne uruchomienie przywraca zminimalizowane okno sterowania i przenosi je na pierwszy plan. Klawisze Tab i Shift+Tab przełączają między kontrolkami; Alt i podkreślona litera wywołują polecenie. Esc zamyka aktywne okno Pomocy lub O programie; w oknie sterowania kończy działanie aplikacji. Wstrzymanie i blokowanie wygaszacza dotyczą całej aplikacji, niezależnie od zaznaczenia monitorów. Gdy blokowanie jest włączone, wygaszacz Windows jest powstrzymywany tylko wtedy, gdy na co najmniej jednym monitorze jest widoczna niewstrzymana animacja.

## ZRZUTY EKRANU I NAGRYWANIE

Zrzuty i nagrania obejmują pierwszy aktywny monitor animacji, a nie wspólny obraz wszystkich monitorów. PNG używa folderu Obrazy, MP4 folderu Wideo; jeśli ich nie ma, używane są Dokumenty. Przycisk Ustawienia nagrywania pozwala wybrać Viewport lub TV. Viewport zachowuje rozmiar i częstotliwość odświeżania monitora animacji, do 60 klatek na sekundę. TV oferuje 1920 × 1080, 1440 × 1080 lub 1280 × 720 w formacie 16:9, z 50, 25, 59.94 (60000/1001) lub 29.97 (30000/1001) klatkami na sekundę. Proporcje obrazu są zachowane; TV używa progresywnego obrazu BT.709 z ograniczonym zakresem i próbkowaniem 4:2:0. Rozdzielczość i liczba klatek są dostępne tylko w trybie TV. Okno Ustawienia nagrywania można zminimalizować i nie blokuje ono innych okien aplikacji. OK zapisuje wybór dla następnego nagrania MP4; Anuluj lub Esc odrzuca niepotwierdzone zmiany. Podczas nagrywania nie można wyłączyć wyjścia animacji nagrywanego monitora; zmiany pozostałych monitorów nie przerywają nagrania. Zamknięcie aplikacji podczas nagrywania wymaga potwierdzenia, ponieważ kończy również nagranie.

## PODGLĄD I OBSŁUGA

Włącz podgląd uruchamia podgląd pełnoekranowy na wszystkich monitorach. Okno ustawień pozostaje otwarte, umożliwiając zmiany na bieżąco. OK zapisuje ustawienia, a Anuluj je odrzuca. Esc lub ruch myszy kończy tryb pełnoekranowy. Klawisze Tab i Shift+Tab przełączają między kontrolkami; Alt i podkreślona litera wywołują polecenie. Esc w ustawieniach odpowiada przyciskowi Anuluj; w Pomocy lub O programie zamyka tylko to okno.

## Wymagania systemowe

Systemy od Windows 7 do Windows 11 obsługują wszystkie funkcje, w tym zrzuty PNG i nagrywanie MP4. Do uruchomienia aplikacji w systemie Windows Vista SP2 konieczne jest zainstalowanie aktualizacji KB971512 i KB2117917. Nagrywanie MP4 nie działa w Vista w obecnej wersji. Wyświetlanie wymaga Direct3D 11, a nie tylko starszego środowiska DirectX. Nagrywanie MP4 wymaga dostępnych składników Media Foundation i kodera H.264. Samodzielna aplikacja może również działać w systemie Linux za pośrednictwem Wine; integracja jako wygaszacz ekranu jest dostępna tylko w systemie Windows.

## Kompilowanie

Otwórz `DispSavers.slnx` w Visual Studio z MSVC v145 i Windows SDK. Wybierz `Release | x86` i przebuduj rozwiązanie, aby utworzyć `Release\FlyingSolids.exe`, `Release\FlightCorridor.exe`, `Release\SpaceFlight.exe` oraz `Release\FlyingSolids.scr`, `Release\FlightCorridor.scr`, `Release\SpaceFlight.scr`. Konfiguracja x64 nie jest dostępna.

Uruchom `PackageRelease.ps1` bez parametrów podpisywania, aby spakować zbudowane pliki. Skrypt używa kopii tymczasowych, nie zmienia plików w `Release` i jedynie weryfikuje istniejące prawidłowe podpisy. Tworzy jeden plik `DispSavers-<version>-win32.zip` zawierający `FlyingSolids\FlyingSolids.exe`, `FlyingSolids\FlyingSolids.scr`, `FlyingSolids\license.txt`, `FlightCorridor\FlightCorridor.exe`, `FlightCorridor\FlightCorridor.scr`, `FlightCorridor\license.txt`, `SpaceFlight\SpaceFlight.exe`, `SpaceFlight\SpaceFlight.scr` oraz `SpaceFlight\license.txt`. Poprzedni ZIP jest usuwany na początku uruchomienia; błąd weryfikacji uniemożliwia utworzenie nowego archiwum.

## Licencja

DispSavers jest udostępniany na [licencji MIT](../license.txt). Copyright © Petr Červinka — FortSoft 2026

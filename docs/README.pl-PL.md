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

## GameOfLife

Gra w życie Conwaya we wspólnym świecie na wielu monitorach.

### Zasady

Gra w życie Conwaya używa B3/S23. Martwa komórka ożywa przy dokładnie trzech żywych sąsiadach; żywa przeżywa przy dwóch lub trzech. Ośmiu sąsiadów obejmuje przekątne. Wszystkie komórki zmieniają się jednocześnie. Przeciwległe krawędzie łączą się: lewa z prawą, górna z dolną.

### Monitory i wspólny świat

Pola w EXE włączają monitory; ustawienia dotyczą wspólnego świata. Jeden włączony monitor zawiera cały świat. Przy częściowym wyborze usuwane są całkowicie puste wiersze i kolumny: lewy i prawy monitor łączą się po wyłączeniu środkowego. Niemożliwe do usunięcia wewnętrzne luki nadal uczestniczą w symulacji. Wybranie wszystkich monitorów lub uruchomienie SCR zachowuje prostokąt pulpitu z niewidocznymi przerwami. Każdy monitor pokazuje swój fragment tej samej gry.

### Stan początkowy i wzorce

Domyślny początek to losowy szum z 25 % żywych komórek. Gęstość początkowa 0–100 % działa przy następnym restarcie. Tylko znane wzorce używa 4 106 dołączonych wzorców bez szumu i wyłącza gęstość. Wybierz mieszankę lub nazwany wzorzec; wymiary podano w komórkach. Wpisuj nazwę, aby szukać. Lista zawiera tylko wzorce mieszczące się w całości. Małe sprawdzone wzorce powtarzają się w oddzielnych kopiach, duże lub złożone pojawiają się raz na środku. Zmniejszenie świata może zastąpić zbyt duży wybór mieszanką. Zmiana trybu lub wzorca tworzy nową scenę. Restarty zachowują wybór; katalog działa bez internetu.

### Komórki, siatka i kolory

Bez siatki rozmiar wynosi 1–64 px. Pokaż siatkę dodaje krawędź 1 px wewnątrz obecnego odstępu: wskazanie i suwak zmniejszają się o jeden, dostępne jest 1–63. Wyłączenie przywraca wartość. Suwak zachowuje zakres i cofa się z niedostępnego końca; pole pozostaje aktywne. Przełączanie zachowuje scenę, poza włączeniem przy 1 px: odstęp rośnie do 2 px i scena zaczyna się od nowa. Zmiana rozmiaru lub monitorów także tworzy nową scenę. Bardzo duży świat może wymagać większego minimum. Kolory komórek, tła i siatki zmieniają się osobno bez restartu. Losowy kolor żywych komórek zmienia się przy każdym ręcznym lub automatycznym restarcie sceny. Zapisany kolor pozostaje zachowany i wraca po wyłączeniu tej opcji. To samo działanie można włączyć osobno dla tła i siatki; obie nowe opcje są domyślnie wyłączone.

### Prędkość, pauza i automatyczny restart

Prędkość wynosi 0–240 pokoleń/s, niezależnie od odświeżania; 0 zatrzymuje rozwój. Pauza i Wznów zachowują świat. Restart rozpoczyna wybrany tryb od nowa. Opcjonalny automatyczny restart wykrywa nieruchome lub dokładnie powtarzające się widoczne fazy, także oscylatory. Porównuje pokolenia, nie sekundy; pomija niewidoczne obszary. Wyniki asynchroniczne mogą nieco opóźnić restart. Domyślnie: odstęp 8 px, 20 pokoleń/s, losowy kolor żywych komórek i automatyczny restart włączone. Siatka jest domyślnie wyłączona. Osiągana prędkość zależy od wydajności i liczby komórek. Automatyczny restart porównuje obszary włączonych monitorów; luki między nimi nadal ewoluują, lecz nie są porównywane.

### Przywróć wartości

Przywracanie ustawia wyświetlany rozmiar komórki na 8 px z siatką lub bez niej (odstęp 9 lub 8 px), prędkość na 20 pokoleń/s, gęstość na 25 % i trzy domyślne kolory. Pozostałe opcje są zachowane; wzorzec, który się nie mieści, zastępuje mieszanka. Nowa scena powstaje tylko po zmianie odstępu lub gęstości w trybie szumu.

### Samodzielna aplikacja i nagrywanie MP4

EXE zapisuje ustawienia na bieżąco i nagrywa pierwszy aktywny monitor do MP4. Proponuje folder Wideo, zastępczo Dokumenty. Viewport używa wymiarów i odświeżania monitora do 60 klatek/s. TV oferuje 1920 × 1080, 1440 × 1080 lub 1280 × 720 w 16:9 przy 50, 25, 59,94 (60000/1001) lub 29,97 (30000/1001) klatkach/s. Proporcje są zachowane; TV używa progresywnego BT.709, ograniczonego zakresu i 4:2:0. Niezależne okno ustawień można zminimalizować. OK zapisuje opcje dla następnego nagrania; Anuluj lub Esc odrzuca niezatwierdzone zmiany. Nagrywanego monitora nie można wyłączyć; pozostałe wyjścia można zmieniać. Zakończenie podczas nagrywania wymaga potwierdzenia. Przy aktywnej animacji Spacja przełącza pauzę, F9: Rozpocznij nagrywanie; F10: Zatrzymaj nagrywanie. Kursor znika po 1 sekundzie bezruchu i wraca po poruszeniu. Tab/Shift+Tab przechodzi między kontrolkami, Alt wybiera podkreślone polecenia. Esc zamyka Pomoc/Informacje lub kończy aplikację z głównego okna. Wygaszacz ekranu Windows… otwiera systemowe ustawienia wygaszacza ekranu.

### Zdjęcie i zarządzanie wygaszaczem w EXE

Zdjęcie zapisuje PNG nagrywanego monitora, a w pozostałych przypadkach pierwszego aktywnego, w jego rozdzielczości i bez restartu sceny. Proponowany jest folder Obrazy, zastępczo Dokumenty. Blokowanie wygaszacza podczas animacji zapobiega jego uruchomieniu, gdy animacja jest widoczna i nie jest wstrzymana. Prędkość zero nie oznacza pauzy. Instalacja z EXE rozpakowuje dołączony SCR i wybiera go jako wygaszacz Windows. Instalacja i odinstalowanie mogą wymagać zgody administratora; pasek stanu pokazuje operację aż do zakończenia. Jeśli usuwanie jest zablokowane, zamknij działający wygaszacz, jego ustawienia i podgląd Windows.

### Wygaszacz ekranu Windows

GameOfLife.scr używa wszystkich monitorów i ustawień oddzielnych od EXE. Włącz podgląd uruchamia pełny ekran przy otwartych ustawieniach. Mały podgląd Windows skaluje cały świat. OK zapisuje; Anuluj lub Esc odrzuca zmiany. Ruch myszy lub klawisz kończy pełnoekranowy wygaszacz. Nagrywanie MP4 jest dostępne w EXE.

### Położenie i stan okien

Przy zamykaniu osobno zapisywane są pozycje okna głównego i Informacje; dla Pomocy także rozmiar oraz stan normalny lub zmaksymalizowany sprzed minimalizacji. Nie zależy to od zatwierdzania ustawień aplikacji. Zakończenie aplikacji zamyka też Pomoc i Informacje.

### Renderowanie i licencje wzorców

Rozwój i porównania widocznych stanów wykonują shadery Direct3D 11 na GPU; po nieudanej inicjalizacji sprzętowej dostępne jest renderowanie programowe. Każdy monitor używa sprawdzonego regulatora klatek przy własnym odświeżaniu. MP4 wymaga Media Foundation i kodera H.264. Wzorce pochodzą z LifeWiki (GFDL 1.2 lub nowsza) i publicznych zbiorów Alana Hensela w domenie publicznej. Kod ma licencję MIT; informacje i licencje katalogu są oddzielne.

[Źródła wzorców, licencje i szczegóły importu](../GameOfLife/LifePatternsLicense.txt)

`GameOfLife.exe` · `GameOfLife.scr`

## FlyingSolids · FlightCorridor · SpaceFlight

### MONITORY

Zaznaczenie wierszy określa konfigurowane monitory i jest niezależne od pól wyboru włączających wyjścia animacji. Ctrl+A zaznacza wszystkie monitory; Ctrl i Shift zmieniają zaznaczenie. Wszystkie opcje i suwaki animacji dotyczą zaznaczonych monitorów. Zaznaczenie jest zapamiętywane osobno dla EXE i SCR. Jeśli zaznaczone były wszystkie monitory, nowe również zostaną zaznaczone. Różne wartości na zaznaczonych monitorach są sygnalizowane nieokreślonym stanem pól wyboru i kropkowaniem przycisków opcji, uchwytów suwaków oraz przycisków „Włącz wszystko” i „Wyłącz wszystko”. Etykiety suwaków pokazują kreskę zamiast wspólnej wartości. Zmiana opcji lub kliknięcie suwaka ustawia tę wartość na wszystkich zaznaczonych monitorach.

### OBSŁUGA

Wyjścia animacji można włączać i wyłączać polami wyboru przy monitorach lub podwójnym kliknięciem ich wierszy. Każdy monitor ma niezależną scenę. Zrzut zapisuje PNG, a przycisk nagrywania rozpoczyna lub kończy MP4. Wstrzymaj zatrzymuje animację. Aplikacja instaluje i odinstalowuje również wbudowany wygaszacz. Ustawienia są zapisywane na bieżąco. Aplikacja działa tylko w jednej instancji. Kolejne uruchomienie przywraca zminimalizowane okno sterowania i przenosi je na pierwszy plan. Klawisze Tab i Shift+Tab przełączają między kontrolkami; Alt i podkreślona litera wywołują polecenie. Esc zamyka aktywne okno Pomocy lub O programie; w oknie sterowania kończy działanie aplikacji. Wstrzymanie i blokowanie wygaszacza dotyczą całej aplikacji, niezależnie od zaznaczenia monitorów. Gdy blokowanie jest włączone, wygaszacz Windows jest powstrzymywany tylko wtedy, gdy na co najmniej jednym monitorze jest widoczna niewstrzymana animacja.

### ZRZUTY EKRANU I NAGRYWANIE

Zrzuty i nagrania obejmują pierwszy aktywny monitor animacji, a nie wspólny obraz wszystkich monitorów. PNG używa folderu Obrazy, MP4 folderu Wideo; jeśli ich nie ma, używane są Dokumenty. Przycisk Ustawienia nagrywania pozwala wybrać Viewport lub TV. Viewport zachowuje rozmiar i częstotliwość odświeżania monitora animacji, do 60 klatek na sekundę. TV oferuje 1920 × 1080, 1440 × 1080 lub 1280 × 720 w formacie 16:9, z 50, 25, 59.94 (60000/1001) lub 29.97 (30000/1001) klatkami na sekundę. Proporcje obrazu są zachowane; TV używa progresywnego obrazu BT.709 z ograniczonym zakresem i próbkowaniem 4:2:0. Rozdzielczość i liczba klatek są dostępne tylko w trybie TV. Okno Ustawienia nagrywania można zminimalizować i nie blokuje ono innych okien aplikacji. OK zapisuje wybór dla następnego nagrania MP4; Anuluj lub Esc odrzuca niepotwierdzone zmiany. Podczas nagrywania nie można wyłączyć wyjścia animacji nagrywanego monitora; zmiany pozostałych monitorów nie przerywają nagrania. Zamknięcie aplikacji podczas nagrywania wymaga potwierdzenia, ponieważ kończy również nagranie.

### PODGLĄD I OBSŁUGA

Włącz podgląd uruchamia podgląd pełnoekranowy na wszystkich monitorach. Okno ustawień pozostaje otwarte, umożliwiając zmiany na bieżąco. OK zapisuje ustawienia, a Anuluj je odrzuca. Esc lub ruch myszy kończy tryb pełnoekranowy. Klawisze Tab i Shift+Tab przełączają między kontrolkami; Alt i podkreślona litera wywołują polecenie. Esc w ustawieniach odpowiada przyciskowi Anuluj; w Pomocy lub O programie zamyka tylko to okno.

### Wymagania systemowe

Systemy od Windows 7 do Windows 11 obsługują wszystkie funkcje, w tym zrzuty PNG i nagrywanie MP4. Do uruchomienia aplikacji w systemie Windows Vista SP2 konieczne jest zainstalowanie aktualizacji KB971512 i KB2117917. Nagrywanie MP4 nie działa w Vista w obecnej wersji. Wyświetlanie wymaga Direct3D 11, a nie tylko starszego środowiska DirectX. Nagrywanie MP4 wymaga dostępnych składników Media Foundation i kodera H.264. Samodzielna aplikacja może również działać w systemie Linux za pośrednictwem Wine; integracja jako wygaszacz ekranu jest dostępna tylko w systemie Windows.

## Kompilowanie

Otwórz `DispSavers.slnx` w Visual Studio z MSVC v145 i Windows SDK. Wybierz `Release | x86` i przebuduj rozwiązanie, aby utworzyć `Release\FlyingSolids.exe`, `Release\FlightCorridor.exe`, `Release\GameOfLife.exe`, `Release\GameOfLife.scr`, `Release\SpaceFlight.exe` oraz `Release\FlyingSolids.scr`, `Release\FlightCorridor.scr`, `Release\SpaceFlight.scr`. Konfiguracja x64 nie jest dostępna.

Uruchom `PackageRelease.ps1` bez parametrów podpisywania, aby spakować zbudowane pliki. Skrypt używa kopii tymczasowych, nie zmienia plików w `Release` i jedynie weryfikuje istniejące prawidłowe podpisy. Tworzy jeden plik `DispSavers-<version>-win32.zip` zawierający `FlyingSolids\FlyingSolids.exe`, `FlyingSolids\FlyingSolids.scr`, `FlyingSolids\license.txt`, `FlightCorridor\FlightCorridor.exe`, `FlightCorridor\FlightCorridor.scr`, `FlightCorridor\license.txt`, `GameOfLife\GameOfLife.exe`, `GameOfLife\GameOfLife.scr`, `GameOfLife\license.txt`, `SpaceFlight\SpaceFlight.exe`, `SpaceFlight\SpaceFlight.scr` oraz `SpaceFlight\license.txt`. Poprzedni ZIP jest usuwany na początku uruchomienia; błąd weryfikacji uniemożliwia utworzenie nowego archiwum.

## Licencja

DispSavers jest udostępniany na [licencji MIT](../license.txt). Copyright © Petr Červinka — FortSoft 2026

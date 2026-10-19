# FlightCorridor

[Čeština](README.cs-CZ.md) · [English (US)](README.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Português](README.pt-PT.md) · **Polski** · [Slovenčina](README.sk-SK.md) · [Dansk](README.da-DK.md) · [Suomi](README.fi-FI.md) · [Íslenska](README.is-IS.md) · [Norsk (bokmål)](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Türkçe](README.tr-TR.md) · [Eesti](README.et-EE.md) · [Gaeilge](README.ga-IE.md) · [Lietuvių](README.lt-LT.md) · [Latviešu](README.lv-LV.md) · [Magyar](README.hu-HU.md) · [Malti](README.mt-MT.md) · [Nederlands](README.nl-NL.md) · [Română](README.ro-RO.md) · [Ελληνικά](README.el-GR.md) · [Bosanski](README.bs-Latn-BA.md) · [Hrvatski](README.hr-HR.md) · [Slovenščina](README.sl-SI.md) · [Crnogorski](README.cnr-Latn-ME.md) · [Беларуская](README.be-BY.md) · [Български](README.bg-BG.md) · [Македонски](README.mk-MK.md) · [Српски](README.sr-Cyrl-RS.md) · [Українська](README.uk-UA.md) · [Русский](README.ru-RU.md)

FlightCorridor: Przelot między czterema zmiennymi powierzchniami; Przelot przez zmienny lejek. Każdemu monitorowi przypisz dokładnie jedną animację. Tekstura przełącza powierzchnie z teksturą i model szkieletowy. Swobodne obracanie kamery powoli zmienia kierunek widoku we wszystkich trzech wymiarach. Zatrzymania i zmiany kierunku dodają losowe zwalnianie, pauzy i odwracanie obrotu; lot do przodu trwa nadal. Prędkość wynosi 0–1600%. Każdy monitor ma niezależną losową scenę wyświetlaną z własną częstotliwością odświeżania.

Zaznaczenie wierszy określa konfigurowane monitory i jest niezależne od pól wyboru włączających wyjścia animacji. Ctrl+A zaznacza wszystkie monitory; Ctrl i Shift zmieniają zaznaczenie. Wszystkie opcje i suwaki animacji dotyczą zaznaczonych monitorów. Zaznaczenie jest zapamiętywane osobno dla EXE i SCR. Jeśli zaznaczone były wszystkie monitory, nowe również zostaną zaznaczone.

## Aplikacja

`FlightCorridor.exe`

Na liście można zaznaczyć wiele monitorów; podwójne kliknięcie przełącza animację na monitorze, można też odznaczyć wszystkie. Każdy monitor ma niezależną scenę. Zrzut zapisuje PNG, a przycisk nagrywania rozpoczyna lub kończy MP4. Wstrzymaj zatrzymuje animację. Aplikacja instaluje i odinstalowuje również wbudowany wygaszacz. Ustawienia są zapisywane na bieżąco. Aplikacja działa tylko w jednej instancji. Kolejne uruchomienie przywraca zminimalizowane okno sterowania i przenosi na pierwszy plan. Klawisze Tab i Shift+Tab przełączają między kontrolkami; Alt i podkreślona litera wywołują polecenie. Esc zamyka aktywne okno Pomocy lub O programie; w oknie sterowania kończy działanie aplikacji. Blokuj wygaszacz podczas animacji zapobiega uruchomieniu wygaszacza Windows tylko wtedy, gdy animacja jest rzeczywiście widoczna i nie jest wstrzymana.

Zrzuty i nagrania obejmują pierwszy aktywny monitor animacji, a nie wspólny obraz wszystkich monitorów. PNG używa folderu Obrazy, MP4 folderu Wideo; jeśli ich nie ma, używane są Dokumenty. Przycisk Ustawienia nagrywania pozwala wybrać Viewport lub TV. Viewport zachowuje rozmiar i częstotliwość odświeżania monitora animacji, do 60 klatek na sekundę. TV oferuje 1920 × 1080, 1440 × 1080 lub 1280 × 720 w formacie 16:9, z 50, 25, 59.94 (60000/1001) lub 29.97 (30000/1001) klatkami na sekundę. Proporcje obrazu są zachowane; TV używa progresywnego obrazu BT.709 z ograniczonym zakresem i próbkowaniem 4:2:0. Rozdzielczość i liczba klatek są dostępne tylko w trybie TV. Okno Ustawienia nagrywania można zminimalizować i nie blokuje ono innych okien aplikacji. OK zapisuje wybór dla następnego nagrania MP4; Anuluj lub Esc odrzuca niepotwierdzone zmiany. Podczas nagrywania nie można odznaczyć nagrywanego monitora; zmiany pozostałych monitorów nie przerywają nagrania. Zamknięcie aplikacji podczas nagrywania wymaga potwierdzenia, ponieważ kończy również nagranie.

Systemy od Windows 7 do Windows 11 obsługują wszystkie funkcje, w tym zrzuty PNG i nagrywanie MP4. Do uruchomienia aplikacji w systemie Windows Vista SP2 konieczne jest zainstalowanie aktualizacji KB971512 i KB2117917. Nagrywanie MP4 nie działa w Vista w obecnej wersji.

## Wygaszacz ekranu

`FlightCorridor.scr`

Włącz podgląd uruchamia podgląd pełnoekranowy na wszystkich monitorach. Okno ustawień pozostaje otwarte, umożliwiając zmiany na bieżąco. OK zapisuje ustawienia, a Anuluj je odrzuca. Esc lub ruch myszy kończy tryb pełnoekranowy. Klawisze Tab i Shift+Tab przełączają między kontrolkami; Alt i podkreślona litera wywołują polecenie. Esc w ustawieniach odpowiada przyciskowi Anuluj; w Pomocy lub O programie zamyka tylko to okno.

Obsługiwane są systemy od Windows 7 do Windows 11. Do uruchomienia aplikacji w systemie Windows Vista SP2 konieczne jest zainstalowanie aktualizacji KB971512 i KB2117917.

## Kompilacja

Otwórz `DispSavers.slnx` w Visual Studio z MSVC v145 i Windows SDK. Wybierz `Release | x86` i przebuduj rozwiązanie, aby utworzyć `Release\FlightCorridor.exe` oraz `Release\FlightCorridor.scr`. Konfiguracja x64 nie jest dostępna. We właściwościach projektu `FlightCorridor`, na stronie `Signing`, podaj nazwę lub odcisk ważnego certyfikatu podpisywania kodu z kluczem prywatnym w magazynie `Personal (My)` bieżącego użytkownika. Ustawienia dotyczą EXE i SCR i są zapisywane w pliku `FlightCorridor.vcxproj.user`, ignorowanym przez Git. SignTool jest automatycznie wyszukiwany w PATH lub Windows SDK. Jeśli korzystasz z SimplySign, przed kompilacją zaloguj się do SimplySign Desktop. Najpierw podpisywany jest SCR i dodawany jest obowiązkowy znacznik czasu RFC 3161 SHA-256 z ustawionego serwera znaczników czasu, następnie SCR jest osadzany w EXE, który również otrzymuje podpis i znacznik czasu. W polu `Timestamp server` podaj adres URL serwera znaczników czasu RFC 3161. Błąd podpisywania, znacznika czasu lub weryfikacji przerywa kompilację; pliki z prawidłowym podpisem i znacznikiem czasu nie są podpisywane ponownie.

[MIT License](license.txt) — Copyright © Petr Červinka — FortSoft 2026

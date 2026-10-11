# FlyingSolids

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Português](README.pt-PT.md) · [Norsk](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Suomi](README.fi-FI.md) · [Dansk](README.da-DK.md) · [Íslenska](README.is-IS.md) · **Türkçe**

FlyingSolids, aydınlatılmış katı üç boyutlu geometrik nesneler gösteren yerel bir Win32/x86 Direct3D uygulaması ve Windows ekran koruyucusudur. Nesneler bağımsız olarak hareket eder ve döner; birbirlerinin içinden geçmeden çarpışır. Başlangıç koşulları ile uçuşta yeniden kullanılan konumlar Windows’un kriptografik rastgele sayı üretecinden alınır ve işlemci yükünü düşük tutmak için bloklar hâlinde arabelleğe alınır.

## Özellikler

- **Uzayı gözlemleme** ve doğrusal **Uzayda uçuş** kipleri
- Ana ışık ve dolgu ışığı birbirinden bağımsız olarak açılıp kapatılabilir
- Seçilen her monitörde bağımsız sahne
- Etkin nesne başına bir ile on kopya
- Nesne ve kamera hızı %0–1600; nesne boyutu %50–200
- Parlak aydınlatma, ayrı renkler ve çarpışma çözümü
- Her monitörün yenileme hızına uyumlu görüntü oluşturma
- Bağımsız uygulamada PNG görüntüsü ve MP4 kaydı
- Uygulama ile ekran koruyucu için ayrı ayarlar
- 27 katı cisim türü ve 17 dilde arayüz

## Katı cisimler

Katalogda çokyüzlüler, düzgün prizmalar, piramitler ve düzlemsel kesitleri, koniler ve silindirler ve bunların kesitleri, düzlemle kapatılmış dönel paraboloit, küreden türetilen cisimler, elipsoitler, ovoit, sferosilindir ve torus bulunur. Arayüz yerleşik Türkçe geometri terimlerini kullanır.

## Aydınlatma

Sağdaki kaydırıcıların altındaki `Ana ışık` ve `Dolgu ışığı` onay kutuları, tüm sahne için iki ışığı birbirinden bağımsız olarak açar veya kapatır. Varsayılan olarak `Ana ışık` açık, `Dolgu ışığı` kapalıdır. Aydınlatma ayarları uygulama ve ekran koruyucu için ayrı ayrı kaydedilir.

## Uygulama ve ekran koruyucu

`FlyingSolids.exe`, animasyon sırasında tek denetim penceresini açık tutar. Birden çok monitör seçilebilir, satıra çift tıklayarak bir monitör açılıp kapatılabilir veya tümü ayrılabilir. PNG dosyaları varsayılan olarak **Resimler**, MP4 dosyaları **Videolar** klasörüne; bunlar yoksa **Belgeler** klasörüne kaydedilir. EXE, gömülü ekran koruyucuyu kurabilir ve kaldırabilir.

Uygulamanın aynı anda yalnızca bir örneği çalışabilir. Yeniden başlatılması, simge durumuna küçültülmüş denetim penceresini geri yükler, yeniden çizer ve ön plana getirir.

Denetimler arasında Tab ve Shift+Tab ile ilerleyin; Alt ve altı çizili harf bir komutu etkinleştirir. Esc, etkin Yardım veya Hakkında penceresini kapatır; denetim penceresinde uygulamadan çıkar.

Anlık görüntüler ve kayıtlar, tüm monitörlerin birleşik görüntüsünü değil, ilk etkin animasyon monitörünü kullanır. PNG Resimler, MP4 Videolar klasörünü kullanır; bu klasörler yoksa Belgeler kullanılır. MP4 kaydı monitörün yenileme hızını izler, ancak saniyede en fazla 60 karedir.

`FlyingSolids.scr` kayıt özelliği içermeyen ayrı ayarlara sahiptir. Tam ekran kipinde her monitörde bağımsız sahne açılır.

Ayarlardaki Önizlemeyi aç, tüm monitörlerde ayrı bir tam ekran önizleme başlatır. Geçerli ayarları kullanır, anlık değişikliklere izin verir ve tekrar durdurulabilir. Tam ekran koruyucudan herhangi bir tuş, fare hareketi veya fare tıklamasıyla çıkılır.

Ayarlarda Esc, İptal ile aynı işlevi görür; Yardım veya Hakkında penceresinde yalnızca o pencereyi kapatır.

## Ayarların saklanması

```text
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\Standalone
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\ScreenSaver
```

## Sistem gereksinimleri

Windows 7 ile Windows 11 arasındaki sürümler, PNG anlık görüntüler ve MP4 kaydı dâhil tüm özellikleri destekler.

Windows Vista SP2: KB971512, KB2117917. Geçerli sürümde MP4 kaydı Vista'da çalışmaz.

Görüntüleme, yalnızca eski bir DirectX çalışma zamanı değil, Direct3D 11 gerektirir. MP4 kaydı, kullanılabilir Media Foundation bileşenleri ve bir H.264 kodlayıcı gerektirir.

## Derleme

`DispSavers.slnx` dosyasını açın, `Release | x86` seçin ve çözümü MSVC v145 ile Windows SDK kullanarak yeniden derleyin. EXE ve SCR birlikte oluşturulur. `PackageRelease.ps1`, dosyaları ve `license.txt` öğesini `FlyingSolids` alt dizinine yerleştirerek çözümün tek `DispSavers-<version>-win32.zip` paketini oluşturur. x64 yapılandırması yoktur.

## Lisans

FlyingSolids [MIT Lisansı](../license.txt) ile sunulur.

Copyright © Petr Červinka — FortSoft 2026

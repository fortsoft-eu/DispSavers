# FlyingSolids

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Português](README.pt-PT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [Dansk](README.da-DK.md) · [Suomi](README.fi-FI.md) · [Íslenska](README.is-IS.md) · [Norsk (bokmål)](README.nb-NO.md) · [Svenska](README.sv-SE.md) · **Türkçe** · [Eesti](README.et-EE.md) · [Gaeilge](README.ga-IE.md) · [Lietuvių](README.lt-LT.md) · [Latviešu](README.lv-LV.md) · [Magyar](README.hu-HU.md) · [Malti](README.mt-MT.md) · [Nederlands](README.nl-NL.md) · [Română](README.ro-RO.md) · [Ελληνικά](README.el-GR.md) · [Bosanski](README.bs-Latn-BA.md) · [Hrvatski](README.hr-HR.md) · [Slovenščina](README.sl-SI.md) · [Crnogorski](README.cnr-Latn-ME.md) · [Беларуская](README.be-BY.md) · [Български](README.bg-BG.md) · [Македонски](README.mk-MK.md) · [Српски](README.sr-Cyrl-RS.md) · [Українська](README.uk-UA.md) · [Русский](README.ru-RU.md)

FlyingSolids, aydınlatılmış katı üç boyutlu geometrik nesneler gösteren yerel bir Win32/x86 Direct3D uygulaması ve Windows ekran koruyucusudur. Nesneler bağımsız olarak hareket eder ve döner; birbirlerinin içinden geçmeden çarpışır.

Satır seçimi, hangi ekranların düzenlendiğini belirler; animasyon çıkışlarını açan onay kutularından ayrıdır. Ctrl+A tüm ekranları seçer; Ctrl ve Shift seçimi değiştirir. Tüm animasyon seçenekleri ve kaydırıcılar seçili ekranlara uygulanır. Seçim EXE ve SCR için ayrı saklanır. Tüm ekranlar seçiliyse sonradan bağlanan ekranlar da seçime katılır.

## Özellikler

- **Uzayı gözlemleme** ve doğrusal **Uzayda uçuş** kipleri. Listeden bir veya daha fazla ekran seçin. Kamera modu, nesneler, aydınlatma, hızlar, boyut ve kopya sayısı yalnızca seçili ekranlara uygulanır. Her ekran kendi ayarlarını hatırlar.
- Ana ışık, dolgu ışığı, ortam ışığı ve kenar aydınlatmasının bağımsız kontrolü
- Seçilen her monitörde bağımsız sahne
- Etkin nesne başına bir ile on kopya
- Nesne ve kamera hızı %0–1600; nesne boyutu %50–200
- Parlak aydınlatma, ayrı renkler ve çarpışma çözümü
- Her monitörün yenileme hızına uyumlu görüntü oluşturma
- Bağımsız uygulamada PNG görüntüsü ve MP4 kaydı
- Uygulama ile ekran koruyucu için ayrı ayarlar
- 30 katı cisim türü ve 36 dilde arayüz

## Katı cisimler

Küp; Düzgün kare piramit; Kesik kare piramit; Eğik düzlemle kesilmiş kare piramit; Tabana dik düzlemle kesilmiş kare piramit; Düzgün üçgen prizma; Düzgün beşgen prizma; Düzgün altıgen prizma; Düzgün oktahedron; Beşgen çift piramit; Dik dairesel koni; Kesik koni; Eğik düzlemle kesilmiş koni; Tabana dik düzlemle kesilmiş koni; Dik dairesel silindir; İçi boş silindir; Toroidal uçlu içi boş silindir; Düzlemle kapatılmış dönel paraboloit; Küre; Yarım küre; Küre parçası; Büyük küre parçası; Küre tabakası; Üç eksenli elipsoit; Prolat sferoit; Basık sferoit; Ovoit; Sferosilindir; Yuvarlatılmış disk (spheroplatelet); Torus.

## Aydınlatma

Kaydırıcıların altındaki `Ana ışık`, `Dolgu ışığı`, `Ortam ışığı` ve `Kenar aydınlatması` onay kutuları tüm sahnenin aydınlatmasını birbirinden bağımsız olarak kontrol eder. Ortam ışığı yüzeylere temel aydınlatma sağlar, kenar aydınlatması ise kenarları vurgular. Ayarlar uygulama ve ekran koruyucu için ayrı ayrı kaydedilir.

## Uygulama ve ekran koruyucu

`FlyingSolids.exe`, animasyon sırasında tek denetim penceresini açık tutar. Birden çok monitör seçilebilir, satıra çift tıklayarak bir monitör açılıp kapatılabilir veya tümü ayrılabilir. EXE, gömülü ekran koruyucuyu kurabilir ve kaldırabilir. Uygulamanın aynı anda yalnızca bir örneği çalışabilir. Yeniden başlatılması, simge durumuna küçültülmüş denetim penceresini geri yükler ve ön plana getirir. Denetimler arasında Tab ve Shift+Tab ile ilerleyin; Alt ve altı çizili harf bir komutu etkinleştirir. Esc, etkin Yardım veya Hakkında penceresini kapatır; denetim penceresinde uygulamadan çıkar. Anlık görüntüler ve kayıtlar, tüm monitörlerin birleşik görüntüsünü değil, ilk etkin animasyon monitörünü kullanır. PNG Resimler, MP4 Videolar klasörünü kullanır; bu klasörler yoksa Belgeler kullanılır. Kayıt ayarları düğmesi Viewport veya TV seçimini açar. Viewport, animasyon monitörünün boyutlarını ve yenileme hızını saniyede en fazla 60 kareyle korur. TV, 16:9 oranında 1920 × 1080, 1440 × 1080 veya 1280 × 720 çözünürlük ile saniyede 50, 25, 59.94 (60000/1001) veya 29.97 (30000/1001) kare sunar. Görüntünün en boy oranı korunur; TV, sınırlı aralıklı, 4:2:0 örneklemeli ilerlemeli BT.709 video kullanır. Çözünürlük ve kare hızı yalnızca TV modunda seçilebilir. Kayıt ayarları penceresi simge durumuna küçültülebilir ve uygulamanın diğer pencerelerini engellemez. Tamam, seçenekleri bir sonraki MP4 kaydı için kaydeder; İptal veya Esc onaylanmamış değişiklikleri iptal eder. Kayıt sırasında kaydedilen ekranın seçimi kaldırılamaz; diğer ekranlardaki değişiklikler kaydı durdurmaz. Kayıt sırasında uygulamayı kapatmak kaydı da durduracağı için onay gerektirir. Animasyon sırasında ekran koruyucuyu engelle seçeneği, Windows ekran koruyucusunun yalnızca animasyon gerçekten görünürken ve duraklatılmamışken başlamasını engeller. `FlyingSolids.scr` kayıt özelliği içermeyen ayrı ayarlara sahiptir. Tam ekran kipinde her monitörde bağımsız sahne açılır. Ayarlardaki Önizlemeyi aç, tüm monitörlerde ayrı bir tam ekran önizleme başlatır. Geçerli ayarları kullanır, anlık değişikliklere izin verir ve tekrar durdurulabilir. Tam ekran koruyucudan herhangi bir tuş, fare hareketi veya fare tıklamasıyla çıkılır. Ayarlarda Esc, İptal ile aynı işlevi görür; Yardım veya Hakkında penceresinde yalnızca o pencereyi kapatır.

## Ayarların saklanması

```text
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\Standalone
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\ScreenSaver
```

## Sistem gereksinimleri

Windows 7 ile Windows 11 arasındaki sürümler, PNG anlık görüntüler ve MP4 kaydı dâhil tüm özellikleri destekler. Uygulamayı Windows Vista SP2'de çalıştırmak için KB971512 ve KB2117917 güncellemelerini yüklemeniz gerekir. Geçerli sürümde MP4 kaydı Vista'da çalışmaz. Görüntüleme, yalnızca eski bir DirectX çalışma zamanı değil, Direct3D 11 gerektirir. MP4 kaydı, kullanılabilir Media Foundation bileşenleri ve bir H.264 kodlayıcı gerektirir.

## Derleme

`DispSavers.slnx` dosyasını MSVC v145 ve Windows SDK bulunan Visual Studio’da açın. `Release | x86` seçin ve çözümü yeniden derleyerek `Release\FlyingSolids.exe` ve `Release\FlyingSolids.scr` dosyalarını oluşturun. x64 yapılandırması yoktur. `FlyingSolids` projesinin özelliklerindeki `Signing` sayfasında, geçerli kullanıcının `Personal (My)` deposunda özel anahtarı bulunan geçerli bir kod imzalama sertifikasının adını veya parmak izini girin. Ayarlar EXE ve SCR için ortaktır ve Git’in yok saydığı `FlyingSolids.vcxproj.user` dosyasına kaydedilir. SignTool, PATH veya Windows SDK içinde otomatik olarak bulunur. SimplySign kullanıyorsanız derlemeden önce SimplySign Desktop’ta oturum açın. Önce SCR imzalanır ve ayarlanan zaman damgası sunucusundan zorunlu bir RFC 3161 SHA-256 zaman damgası alır; ardından EXE’ye gömülür. EXE de imzalanır ve zaman damgası alır. RFC 3161 zaman damgası sunucusunun URL adresini `Timestamp server` alanına girin. İmzalama, zaman damgası veya doğrulama hatası derlemeyi durdurur; geçerli ve zaman damgalı imzaya sahip dosyalar yeniden imzalanmaz.

Bu derleme çıktılarını paketlemek için `PackageRelease.ps1` dosyasını imzalama parametreleri olmadan çalıştırın. Betik geçici kopyalar kullanır, `Release` içindeki dosyaları değiştirmez ve yalnızca mevcut geçerli imzaları doğrular. `FlyingSolids\FlyingSolids.exe`, `FlyingSolids\FlyingSolids.scr`, `FlyingSolids\license.txt`, `FlightCorridor\FlightCorridor.exe`, `FlightCorridor\FlightCorridor.scr`, `FlightCorridor\license.txt`, `SpaceFlight\SpaceFlight.exe`, `SpaceFlight\SpaceFlight.scr` ve `SpaceFlight\license.txt` içeren tek `DispSavers-<version>-win32.zip` arşivini oluşturur. Önceki ZIP çalıştırmanın başında silinir; doğrulama hatası yeni bir arşiv oluşturulmasını engeller.

## Lisans

FlyingSolids [MIT Lisansı](../license.txt) ile sunulur. Copyright © Petr Červinka — FortSoft 2026

## FlightCorridor

FlightCorridor, Biçim değiştiren dört yüzey arasında uçuş ve Biçim değiştiren bir huninin içinden uçuş seçeneklerini sunar. Her monitöre tam olarak bir uçuş atayın: monitörün satırını ve ilgili seçenek düğmesini seçin.

`Release\FlightCorridor.exe` · `Release\FlightCorridor.scr` · [FlightCorridor](../FlightCorridor/README.tr-TR.md)

## SpaceFlight

SpaceFlight, „Sonsuz dalgalanan yüzey“ ve „Uzun mesafeli uçuş — biçim değiştiren yüzey“ seçeneklerini sunar. Her monitöre tam olarak bir uçuş atayın: monitörün satırını ve ilgili seçenek düğmesini seçin.

`Release\SpaceFlight.exe` · `Release\SpaceFlight.scr` · [SpaceFlight](../SpaceFlight/README.tr-TR.md)

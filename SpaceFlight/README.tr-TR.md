# SpaceFlight

[Čeština](README.cs-CZ.md) · [English (US)](README.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Português](README.pt-PT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [Dansk](README.da-DK.md) · [Suomi](README.fi-FI.md) · [Íslenska](README.is-IS.md) · [Norsk (bokmål)](README.nb-NO.md) · [Svenska](README.sv-SE.md) · **Türkçe** · [Eesti](README.et-EE.md) · [Gaeilge](README.ga-IE.md) · [Lietuvių](README.lt-LT.md) · [Latviešu](README.lv-LV.md) · [Magyar](README.hu-HU.md) · [Malti](README.mt-MT.md) · [Nederlands](README.nl-NL.md) · [Română](README.ro-RO.md) · [Ελληνικά](README.el-GR.md) · [Bosanski](README.bs-Latn-BA.md) · [Hrvatski](README.hr-HR.md) · [Slovenščina](README.sl-SI.md) · [Crnogorski](README.cnr-Latn-ME.md) · [Беларуская](README.be-BY.md) · [Български](README.bg-BG.md) · [Македонски](README.mk-MK.md) · [Српски](README.sr-Cyrl-RS.md) · [Українська](README.uk-UA.md) · [Русский](README.ru-RU.md)

SpaceFlight: Sonsuz dalgalanan yüzey; Uzun mesafeli uçuş — biçim değiştiren yüzey. Her ekrana tam bir animasyon atayın. Doku, dokulu yüzeyler ile tel kafes modeli arasında geçiş yapar. Serbest kamera dönüşü bakış yönünü üç boyutta yavaşça değiştirir. Duraklamalar ve yön değişimleri, dönüşe rastgele yavaşlamalar, duraklamalar ve ters yön değişimleri ekler; ileri uçuş devam eder. Hız 0–1600% aralığındadır. Her ekranın kendi yenileme hızında çizilen bağımsız rastgele bir sahnesi vardır.

Satır seçimi, hangi ekranların düzenlendiğini belirler; animasyon çıkışlarını açan onay kutularından ayrıdır. Ctrl+A tüm ekranları seçer; Ctrl ve Shift seçimi değiştirir. Tüm animasyon seçenekleri ve kaydırıcılar seçili ekranlara uygulanır. Seçim EXE ve SCR için ayrı saklanır. Tüm ekranlar seçiliyse sonradan bağlanan ekranlar da seçime katılır.

## Uygulama

`SpaceFlight.exe`

Listede birden çok monitör seçilebilir; satıra çift tıklamak monitördeki animasyonu açıp kapatır; tüm monitörlerin seçimi de kaldırılabilir. Her monitör bağımsız sahne kullanır. Anlık görüntü PNG kaydeder; kayıt düğmesi MP4 kaydını başlatır veya bitirir. Duraklat animasyonu durdurur. Uygulama gömülü ekran koruyucuyu da kurar veya kaldırır. Ayarlar sürekli kaydedilir. Uygulamanın aynı anda yalnızca bir örneği çalışabilir. Yeniden başlatılması, simge durumuna küçültülmüş denetim penceresini geri yükler ve ön plana getirir. Denetimler arasında Tab ve Shift+Tab ile ilerleyin; Alt ve altı çizili harf bir komutu etkinleştirir. Esc, etkin Yardım veya Hakkında penceresini kapatır; denetim penceresinde uygulamadan çıkar. Animasyon sırasında ekran koruyucuyu engelle seçeneği, Windows ekran koruyucusunun yalnızca animasyon gerçekten görünürken ve duraklatılmamışken başlamasını engeller.

Anlık görüntüler ve kayıtlar, tüm monitörlerin birleşik görüntüsünü değil, ilk etkin animasyon monitörünü kullanır. PNG Resimler, MP4 Videolar klasörünü kullanır; bu klasörler yoksa Belgeler kullanılır. Kayıt ayarları düğmesi Viewport veya TV seçimini açar. Viewport, animasyon monitörünün boyutlarını ve yenileme hızını saniyede en fazla 60 kareyle korur. TV, 16:9 oranında 1920 × 1080, 1440 × 1080 veya 1280 × 720 çözünürlük ile saniyede 50, 25, 59.94 (60000/1001) veya 29.97 (30000/1001) kare sunar. Görüntünün en boy oranı korunur; TV, sınırlı aralıklı, 4:2:0 örneklemeli ilerlemeli BT.709 video kullanır. Çözünürlük ve kare hızı yalnızca TV modunda seçilebilir. Kayıt ayarları penceresi simge durumuna küçültülebilir ve uygulamanın diğer pencerelerini engellemez. Tamam, seçenekleri bir sonraki MP4 kaydı için kaydeder; İptal veya Esc onaylanmamış değişiklikleri iptal eder. Kayıt sırasında kaydedilen ekranın seçimi kaldırılamaz; diğer ekranlardaki değişiklikler kaydı durdurmaz. Kayıt sırasında uygulamayı kapatmak kaydı da durduracağı için onay gerektirir.

Windows 7 ile Windows 11 arasındaki sürümler, PNG anlık görüntüler ve MP4 kaydı dâhil tüm özellikleri destekler. Uygulamayı Windows Vista SP2'de çalıştırmak için KB971512 ve KB2117917 güncellemelerini yüklemeniz gerekir. Geçerli sürümde MP4 kaydı Vista'da çalışmaz.

## Ekran koruyucu

`SpaceFlight.scr`

Önizlemeyi etkinleştir tüm monitörlerde tam ekran önizleme başlatır. Ayarlar penceresi açık kalır ve değişiklikler anında görülür. Tamam ayarları kaydeder, İptal değişiklikleri iptal eder. Tam ekran koruyucudan Esc veya fare hareketiyle çıkılır. Denetimler arasında Tab ve Shift+Tab ile ilerleyin; Alt ve altı çizili harf bir komutu etkinleştirir. Ayarlarda Esc, İptal ile aynı işlevi görür; Yardım veya Hakkında penceresinde yalnızca o pencereyi kapatır.

Windows 7 ile Windows 11 arasındaki sürümler desteklenir. Uygulamayı Windows Vista SP2'de çalıştırmak için KB971512 ve KB2117917 güncellemelerini yüklemeniz gerekir.

## Derleme

`DispSavers.slnx` dosyasını MSVC v145 ve Windows SDK bulunan Visual Studio’da açın. `Release | x86` seçin ve çözümü yeniden derleyerek `Release\SpaceFlight.exe` ve `Release\SpaceFlight.scr` dosyalarını oluşturun. x64 yapılandırması yoktur. `SpaceFlight` projesinin özelliklerindeki `Signing` sayfasında, geçerli kullanıcının `Personal (My)` deposunda özel anahtarı bulunan geçerli bir kod imzalama sertifikasının adını veya parmak izini girin. Ayarlar EXE ve SCR için ortaktır ve Git’in yok saydığı `SpaceFlight.vcxproj.user` dosyasına kaydedilir. SignTool, PATH veya Windows SDK içinde otomatik olarak bulunur. SimplySign kullanıyorsanız derlemeden önce SimplySign Desktop’ta oturum açın. Önce SCR imzalanır ve ayarlanan zaman damgası sunucusundan zorunlu bir RFC 3161 SHA-256 zaman damgası alır; ardından EXE’ye gömülür. EXE de imzalanır ve zaman damgası alır. RFC 3161 zaman damgası sunucusunun URL adresini `Timestamp server` alanına girin. İmzalama, zaman damgası veya doğrulama hatası derlemeyi durdurur; geçerli ve zaman damgalı imzaya sahip dosyalar yeniden imzalanmaz.

[MIT License](license.txt) — Copyright © Petr Červinka — FortSoft 2026

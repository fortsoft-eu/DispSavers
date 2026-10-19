# SpaceFlight

[Čeština](README.cs-CZ.md) · [English (US)](README.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Português](README.pt-PT.md) · [Norsk](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Suomi](README.fi-FI.md) · [Dansk](README.da-DK.md) · [Íslenska](README.is-IS.md) · **Türkçe**

SpaceFlight, „Sonsuz dalgalanan yüzey“ ve „Uzun mesafeli uçuş — biçim değiştiren yüzey“ seçeneklerini sunar. Her monitöre tam olarak bir uçuş atayın: monitörün satırını ve ilgili seçenek düğmesini seçin. Varsayılan olarak tüm monitörlerde ilk animasyon seçilidir. Doku varsayılan olarak açıktır; seçili monitörleri tel kafes modeliyle göstermek için Doku seçeneğini kapatın. Birden fazla satır seçilirse seçim tüm bu monitörlere uygulanır. Kaydırıcı animasyon hızını %0–1600 arasında ayarlar. Varsayılan başlangıçta EXE yalnızca birincil animasyon monitörünü, ekran koruyucu tüm monitörleri etkinleştirir. Her monitör kendi yenileme hızında çizilir. Ayarlar uygulama ve ekran koruyucu için ayrı ayrı kaydedilir. Serbest kamera dönüşü, seçili ekranlarda görünümü tüm yönlerde akıcı biçimde döndürür; varsayılan olarak kapalıdır. Duraklamalar ve yön değişimleri kamera dönüşünü rastgele aralıklarla yavaşlatır, kısa süreliğine durdurur ve ters yönde yeniden başlatır. Bu seçenek serbest kamera dönüşü etkin olduğunda kullanılabilir ve varsayılan olarak kapalıdır; ileri uçuş devam eder.

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

`DispSavers.slnx` dosyasını MSVC v145 ve Windows SDK bulunan Visual Studio’da açın. `Release | x86` seçin ve çözümü yeniden derleyerek `Release\SpaceFlight.exe` ve `Release\SpaceFlight.scr` dosyalarını oluşturun. x64 yapılandırması yoktur. İmzalama hem Release hem de Debug için varsayılan olarak etkindir. `SpaceFlight` projesinin özelliklerindeki `Signing` sayfasında, geçerli kullanıcının `Personal (My)` deposunda özel anahtarı bulunan geçerli bir kod imzalama sertifikasının adını veya parmak izini girin. Ayarlar EXE ve SCR için ortaktır ve Git’in yok saydığı `SpaceFlight.vcxproj.user` dosyasına kaydedilir. SignTool, PATH veya Windows SDK içinde otomatik olarak bulunur. SimplySign kullanıyorsanız derlemeden önce SimplySign Desktop’ta oturum açın. Önce SCR imzalanır ve ayarlanan zaman damgası sunucusundan zorunlu bir RFC 3161 SHA-256 zaman damgası alır; ardından EXE’ye gömülür. EXE de imzalanır ve zaman damgası alır. RFC 3161 zaman damgası sunucusunun URL adresini `Timestamp server` alanına girin. İmzalama, zaman damgası veya doğrulama hatası derlemeyi durdurur; geçerli ve zaman damgalı imzaya sahip dosyalar yeniden imzalanmaz.

[MIT License](license.txt) — Copyright © Petr Červinka — FortSoft 2026

# DispSavers

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Português](README.pt-PT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [Dansk](README.da-DK.md) · [Suomi](README.fi-FI.md) · [Íslenska](README.is-IS.md) · [Norsk (bokmål)](README.nb-NO.md) · [Svenska](README.sv-SE.md) · **Türkçe** · [Eesti](README.et-EE.md) · [Gaeilge](README.ga-IE.md) · [Lietuvių](README.lt-LT.md) · [Latviešu](README.lv-LV.md) · [Magyar](README.hu-HU.md) · [Malti](README.mt-MT.md) · [Nederlands](README.nl-NL.md) · [Română](README.ro-RO.md) · [Ελληνικά](README.el-GR.md) · [Bosanski](README.bs-Latn-BA.md) · [Hrvatski](README.hr-HR.md) · [Slovenščina](README.sl-SI.md) · [Crnogorski](README.cnr-Latn-ME.md) · [Беларуская](README.be-BY.md) · [Български](README.bg-BG.md) · [Македонски](README.mk-MK.md) · [Српски](README.sr-Cyrl-RS.md) · [Українська](README.uk-UA.md) · [Русский](README.ru-RU.md)

## FlyingSolids

Katı 3B nesnelerin donanım hızlandırmalı animasyonu.

Listeden bir veya daha fazla ekran seçin. Kamera modu, nesneler, aydınlatma, hızlar, boyut ve kopya sayısı yalnızca seçili ekranlara uygulanır. Her ekran kendi ayarlarını hatırlar. FlyingSolids aydınlatılmış katı 3B cisimler gösterir. Kaydırıcılar nesne ve kamera hızını %0–1600, kopya sayısını bir ile on ve boyutu %50–200 arasında ayarlar. Uzayı gözlemleme veya doğrusal Uzayda uçuş kipini seçip istenen cisimleri etkinleştirin. Kaydırıcıların altındaki Ana ışık, Dolgu ışığı, Ortam ışığı ve Kenar aydınlatması onay kutuları seçili ekranların aydınlatmasını birbirinden bağımsız olarak kontrol eder. Ortam ışığı yüzeylere temel aydınlatma sağlar, kenar aydınlatması ise kenarları vurgular. Ayarlar uygulama ve ekran koruyucu için ayrı ayrı kaydedilir.

`FlyingSolids.exe` · `FlyingSolids.scr`

## FlightCorridor

Biçim değiştiren bir koridor ve hunide donanım hızlandırmalı uçuş.

FlightCorridor: Biçim değiştiren dört yüzey arasında uçuş; Biçim değiştiren bir huninin içinden uçuş. Her ekrana tam bir animasyon atayın. Doku, dokulu yüzeyler ile tel kafes modeli arasında geçiş yapar. Serbest kamera dönüşü bakış yönünü üç boyutta yavaşça değiştirir. Duraklama ve ters dönüş, dönüşe rastgele yavaşlamalar, duraklamalar ve ters yön değişimleri ekler; ileri uçuş devam eder. Hız %0–1600 aralığındadır. Her ekranın kendi yenileme hızında çizilen bağımsız rastgele bir sahnesi vardır. Ana ışık, dolgu ışığı, ortam ışığı ve kenar aydınlatması seçili ekranlar için ayrı ayrı açılıp kapatılabilir. Aydınlatma yalnızca dokulu yüzeylere uygulanır.

`FlightCorridor.exe` · `FlightCorridor.scr`

## SpaceFlight

Dalgalanan ve biçim değiştiren yüzeyler üzerinde donanım hızlandırmalı uçuş.

SpaceFlight: Sonsuz dalgalanan yüzey; Uzun mesafeli uçuş — biçim değiştiren yüzey; Kütleçekimiyle bükülmüş uzayda uçuş. Her ekrana tam bir animasyon atayın. Doku, dokulu yüzeyler ile tel kafes modeli arasında geçiş yapar. Serbest kamera dönüşü bakış yönünü üç boyutta yavaşça değiştirir. Duraklama ve ters dönüş, dönüşe rastgele yavaşlamalar, duraklamalar ve ters yön değişimleri ekler; ileri uçuş devam eder. Hız %0–1600 aralığındadır. Her ekranın kendi yenileme hızında çizilen bağımsız rastgele bir sahnesi vardır. Ana ışık, dolgu ışığı, ortam ışığı ve kenar aydınlatması seçili ekranlar için ayrı ayrı açılıp kapatılabilir. Aydınlatma yalnızca dokulu yüzeylere uygulanır. İki yüzey animasyonunda Düzlem, Dalgalanma veya Huni seçilebilir. Huni, kamerayı aşağı doğru bir sarmal boyunca içeri çeker. Kütleçekimiyle bükülmüş uzayda uçuş, üç boyutlu bir tel kafes gösterir. Doku, yüzey biçimi ve aydınlatma seçenekleri yalnızca iki yüzey animasyonuna uygulanır.

`SpaceFlight.exe` · `SpaceFlight.scr`

## GameOfLife

Ekranlar arasında paylaşılan bir dünyada Conway'in Hayat Oyunu.

### Kurallar

Conway'in Hayat Oyunu B3/S23 kurallarını kullanır. Ölü hücre tam üç canlı komşuyla doğar; canlı hücre iki veya üç komşuyla yaşar. Sekiz komşuya çaprazlar da dahildir. Tüm hücreler aynı anda değişir. Karşılıklı kenarlar birleşir: sol sağa, üst alta bağlanır.

### Ekranlar ve paylaşilan dünya

EXE'deki kutular ekranları etkinleştirir; ayarlar paylaşılan dünyaya uygulanır. Tek etkin ekran tüm dünyayı içerir. Ekran düzeninin bir bölümü seçilirse tamamen boş satır ve sütunlar kaldırılır: ortadaki kapatılınca sol ve sağ ekran birleşir. Kaldırılamayan iç boşluklar simülasyonda kalır. Tüm ekranların seçilmesi veya SCR kullanılması görünmez aralıklarla birlikte masaüstünü çevreleyen dikdörtgeni korur. Her ekran aynı simülasyonun kendi bölgesini gösterir.

### Başlangiç durumu ve desenler

Varsayılan başlangıç, %25 canlı hücreli rastgele gürültüdür. %0–100 başlangıç yoğunluğu sonraki yeniden başlatmada kullanılır. Yalnızca bilinen desenler, gürültüsüz 4.106 yerleşik desen kullanır ve yoğunluğu kapatır. Karışım veya bir ad seçin; boyutlar hücre cinsindendir. Aramak için ad yazın. Yalnızca tamamen sığan desenler listelenir. Doğrulanmış küçük desenler ayrı kopyalarda tekrarlanır; büyük veya karmaşık desenler ortada bir kez başlar. Dünyayı küçültmek, sığmayan seçimi karışımla değiştirebilir. Modu veya deseni değiştirmek yeni sahne başlatır. Yeniden başlatmalar seçimi korur; katalog çevrimdışı çalışır.

### Hücre boyutu, izgara ve renkler

Izgarasız hücre boyutu 1–64 px'tir. Izgarayı göster, mevcut aralığın içine 1 px kenar ekler: gösterilen değer ve kaydırıcı bir azalır, kullanılabilir değerler 1–63 olur. Kapatmak değeri geri getirir. Kaydırıcı tam aralığını korur ve kullanılamayan uçtan geri döner; kutu etkin kalır. Geçiş sahneyi korur; 1 px'te açılırsa aralık 2 px olur ve yeni sahne başlar. Boyut veya ekran değişimi de yeniden başlatır. Çok büyük dünyalar daha yüksek alt sınır gerektirebilir. Hücre, arka plan ve ızgara renkleri yeniden başlatmadan ayrı ayrı değişir. Canlı hücrelerin rastgele rengi, sahnenin her elle veya otomatik yeniden başlatılmasında yeniden seçilir. Kayıtlı renginiz korunur ve seçenek kapatıldığında geri gelir. Aynı davranış arka plan ve ızgara için ayrı ayrı etkinleştirilebilir; iki yeni seçenek de başlangıçta kapalıdır.

### Hiz, duraklatma ve otomatik yeniden başlatma

Hız, ekran yenilemesinden bağımsız 0–240 nesil/sn'dir; 0 gelişimi durdurur. Duraklat ve Sürdür dünyayı korur. Yeniden başlat seçilen modda yeni başlangıç yapar. İsteğe bağlı otomatik yeniden başlatma, salınımcılar dahil durağan ve tam yinelenen görünür evreleri algılar. Saniyeleri değil nesilleri karşılaştırır; görünmez bölgeler dışlanır. Eşzamansız sonuçlar yeniden başlatmayı biraz geciktirebilir. Varsayılanlar: 8 px aralık, 20 nesil/sn, canlı hücrelerin rastgele rengi ve otomatik yeniden başlatma açık. Izgara varsayılan olarak kapalıdır. Ulaşılan hız performansa ve hücre sayısına bağlıdır. Otomatik yeniden başlatma etkin ekranların bölgelerini karşılaştırır; aradaki boşluklar gelişmeye devam eder ancak karşılaştırmaya katılmaz.

### Değerleri sıfırla

Sıfırlama, ızgara açık veya kapalıyken gösterilen hücre boyutunu 8 px yapar (aralık 9 veya 8 px); hızı 20 nesil/sn, yoğunluğu %25 ve üç rengi varsayılan değerlerine döndürür. Diğer seçimler korunur; artık sığmayan desenin yerini karışım alır. Yalnızca aralık değişirse veya gürültü modunda yoğunluk değişirse yeni sahne oluşturulur.

### Bağimsiz uygulama ve MP4 kaydi

EXE ayarları sürekli kaydeder ve ilk etkin ekranı MP4 olarak kaydeder. Videolar klasörü, yoksa Belgeler önerilir. Viewport ekran boyutlarını ve en çok 60 kare/sn yenilemesini kullanır. TV, 16:9 oranında 1920 × 1080, 1440 × 1080 veya 1280 × 720; 50, 25, 59,94 (60000/1001) veya 29,97 (30000/1001) kare/sn sunar. En-boy oranı korunur; TV aşamalı, sınırlı aralıklı BT.709 ve 4:2:0 kullanır. Bağımsız kayıt ayarları penceresi küçültülebilir. Tamam sonraki kayıt için saklar; İptal veya Esc onaylanmamış değişiklikleri atar. Kaydedilen ekran kapatılamaz; diğer çıkışlar değişebilir. Kayıt sırasında çıkış onay ister. Animasyona odaklanıldığında Boşluk duraklatmayı değiştirir, F9: Kaydı başlat; F10: Kaydı durdur. İmleç 1 saniye hareketsizlikten sonra gizlenir, hareketle görünür. Tab/Shift+Tab denetimler arasında gezer; Alt altı çizili komutları çalıştırır. Esc Yardım/Hakkında'yı kapatır veya ana pencerede uygulamadan çıkar. Windows ekran koruyucusu… sistemin ekran koruyucusu ayarlarını açar.

### Exe’de anlik görüntü ve ekran koruyucu yöneti̇mi̇

Anlık görüntü, kayıt yapılan ekranı veya kayıt yoksa ilk etkin ekranı kendi çözünürlüğünde BMP/GIF/JPEG/PNG/TIFF/WebP olarak saklar; sahneyi yeniden başlatmaz. Resimler klasörü, yoksa Belgeler önerilir. Animasyon sırasında ekran koruyucuyu engelleme, animasyon görünür ve duraklatılmamışken koruyucunun başlamasını önler. Sıfır hız duraklatma değildir. EXE’den kurulum, içerilen SCR’yi açar ve Windows ekran koruyucusu olarak seçer. Kurulum ve kaldırma yönetici onayı gerektirebilir; durum çubuğu işlemi tamamlanana kadar gösterir. Kaldırma engellenirse çalışan koruyucuyu, ayarlarını ve Windows önizlemesini kapatın.

### Windows ekran koruyucusu

GameOfLife.scr tüm ekranları, EXE'den ayrı ayarlarla kullanır. Önizlemeyi aç, ayarlar açıkken tam ekran animasyonu başlatır. Küçük Windows önizlemesi tüm dünyayı küçültür. Tamam kaydeder; İptal veya Esc değişiklikleri atar. Fare hareketi veya bir tuş tam ekran koruyucudan çıkar. MP4 kaydı EXE'de kullanılabilir.

### Pencere konumlari ve durumu

Kapanışta ana pencere ve Hakkında penceresinin konumları ayrı kaydedilir; Yardım için boyut ve küçültmeden önceki normal veya büyütülmüş durum da saklanır. Bu işlem uygulama ayarlarının onaylanmasından bağımsızdır. Uygulamadan çıkış Yardım ve Hakkında pencerelerini de kapatır.

### Görüntüleme ve desen lisanslari

Gelişim ve görünür durum karşılaştırmaları GPU üzerinde Direct3D 11 gölgelendiricileri kullanır; donanım başlatılamazsa yazılımsal görüntüleme kullanılabilir. Her ekran kendi yenileme hızında aynı denenmiş kare zamanlayıcısını kullanır. MP4, Media Foundation ve H.264 kodlayıcı gerektirir. Desenler LifeWiki'den (GFDL 1.2 veya sonrası) ve Alan Hensel'in kamu malı koleksiyonlarından gelir. Program kodu MIT lisanslıdır; katalog bildirimleri ve lisansları ayrıdır.

[Desen kaynakları, lisanslar ve içe aktarma ayrıntıları](../GameOfLife/LifePatternsLicense.txt)

`GameOfLife.exe` · `GameOfLife.scr`

## FlyingSolids · FlightCorridor · SpaceFlight

### EKRANLAR

Satır seçimi, hangi ekranların düzenlendiğini belirler; animasyon çıkışlarını açan onay kutularından ayrıdır. Ctrl+A tüm ekranları seçer; Ctrl ve Shift seçimi değiştirir. Tüm animasyon seçenekleri ve kaydırıcılar seçili ekranlara uygulanır. Seçim EXE ve SCR için ayrı saklanır. Tüm ekranlar seçiliyse sonradan bağlanan ekranlar da seçime katılır. Seçili ekranlardaki farklı değerler, belirsiz durumdaki onay kutuları ve seçenek düğmelerinde, kaydırıcı tutamaçlarında ve “Tümünü etkinleştir” ve “Tümünü devre dışı bırak” düğmelerinde noktalı desenle gösterilir. Kaydırıcı etiketleri ortak bir değer yerine çizgi gösterir. Bir seçeneği değiştirmek veya kaydırıcıya tıklamak bu değeri tüm seçili ekranlara uygular.

### KULLANIM

Animasyon çıkışlarını ekran onay kutularıyla veya satırlarına çift tıklayarak açıp kapatabilirsiniz. Her monitör bağımsız sahne kullanır. Anlık görüntü BMP/GIF/JPEG/PNG/TIFF/WebP kaydeder; kayıt düğmesi MP4 kaydını başlatır veya bitirir. Duraklat animasyonu durdurur. Uygulama gömülü ekran koruyucuyu da kurar veya kaldırır. Ayarlar sürekli kaydedilir. Uygulamanın aynı anda yalnızca bir örneği çalışabilir. Yeniden başlatılması, simge durumuna küçültülmüş denetim penceresini geri yükler ve ön plana getirir. Denetimler arasında Tab ve Shift+Tab ile ilerleyin; Alt ve altı çizili harf bir komutu etkinleştirir. Esc, etkin Yardım veya Hakkında penceresini kapatır; denetim penceresinde uygulamadan çıkar. Duraklatma ve ekran koruyucuyu engelleme, ekran seçiminden bağımsız olarak uygulamanın tamamına uygulanır. Engelleme açıkken Windows ekran koruyucusu yalnızca en az bir ekranda görünür ve duraklatılmamış animasyon varken engellenir.

### EKRAN GÖRÜNTÜLERİ VE KAYIT

Anlık görüntüler ve kayıtlar, tüm monitörlerin birleşik görüntüsünü değil, ilk etkin animasyon monitörünü kullanır. BMP/GIF/JPEG/PNG/TIFF/WebP Resimler, MP4 Videolar klasörünü kullanır; bu klasörler yoksa Belgeler kullanılır. Kayıt ayarları düğmesi Viewport veya TV seçimini açar. Viewport, animasyon monitörünün boyutlarını ve yenileme hızını saniyede en fazla 60 kareyle korur. TV, 16:9 oranında 1920 × 1080, 1440 × 1080 veya 1280 × 720 çözünürlük ile saniyede 50, 25, 59.94 (60000/1001) veya 29.97 (30000/1001) kare sunar. Görüntünün en boy oranı korunur; TV, sınırlı aralıklı, 4:2:0 örneklemeli ilerlemeli BT.709 video kullanır. Çözünürlük ve kare hızı yalnızca TV modunda seçilebilir. Kayıt ayarları penceresi simge durumuna küçültülebilir ve uygulamanın diğer pencerelerini engellemez. Tamam, seçenekleri bir sonraki MP4 kaydı için kaydeder; İptal veya Esc onaylanmamış değişiklikleri iptal eder. Kayıt sırasında kaydedilen ekranın animasyon çıkışı kapatılamaz; diğer ekranlardaki değişiklikler kaydı durdurmaz. Kayıt sırasında uygulamayı kapatmak kaydı da durduracağı için onay gerektirir.

### ÖNİZLEME VE KULLANIM

Önizlemeyi aç tüm monitörlerde tam ekran önizleme başlatır. Ayarlar penceresi açık kalır ve değişiklikler anında görülür. Tamam ayarları kaydeder, İptal değişiklikleri iptal eder. Tam ekran koruyucudan Esc veya fare hareketiyle çıkılır. Denetimler arasında Tab ve Shift+Tab ile ilerleyin; Alt ve altı çizili harf bir komutu etkinleştirir. Ayarlarda Esc, İptal ile aynı işlevi görür; Yardım veya Hakkında penceresinde yalnızca o pencereyi kapatır.

### Sistem gereksinimleri

Windows 7 ile Windows 11 arasındaki sürümler, BMP/GIF/JPEG/PNG/TIFF/WebP anlık görüntüler ve MP4 kaydı dâhil tüm özellikleri destekler. Uygulamayı Windows Vista SP2'de çalıştırmak için KB971512 ve KB2117917 güncellemelerini yüklemeniz gerekir. Geçerli sürümde MP4 kaydı Vista'da çalışmaz. Görüntüleme, yalnızca eski bir DirectX çalışma zamanı değil, Direct3D 11 gerektirir. MP4 kaydı, kullanılabilir Media Foundation bileşenleri ve bir H.264 kodlayıcı gerektirir. Bağımsız uygulama Wine aracılığıyla Linux üzerinde de çalışabilir; ekran koruyucu bütünleştirmesi yalnızca Windows’ta kullanılabilir.

## Derleme

`DispSavers.slnx` dosyasını MSVC v145 ve Windows SDK bulunan Visual Studio’da açın. `Release | x86` seçin ve çözümü yeniden derleyerek `Release\FlyingSolids.exe`, `Release\FlightCorridor.exe`, `Release\GameOfLife.exe`, `Release\GameOfLife.scr`, `Release\SpaceFlight.exe` ve `Release\FlyingSolids.scr`, `Release\FlightCorridor.scr`, `Release\SpaceFlight.scr` dosyalarını oluşturun. x64 yapılandırması yoktur.

Bu derleme çıktılarını paketlemek için `PackageRelease.ps1` dosyasını imzalama parametreleri olmadan çalıştırın. Betik geçici kopyalar kullanır, `Release` içindeki dosyaları değiştirmez ve yalnızca mevcut geçerli imzaları doğrular. `FlyingSolids\FlyingSolids.exe`, `FlyingSolids\FlyingSolids.scr`, `FlyingSolids\license.txt`, `FlightCorridor\FlightCorridor.exe`, `FlightCorridor\FlightCorridor.scr`, `FlightCorridor\license.txt`, `GameOfLife\GameOfLife.exe`, `GameOfLife\GameOfLife.scr`, `GameOfLife\license.txt`, `SpaceFlight\SpaceFlight.exe`, `SpaceFlight\SpaceFlight.scr` ve `SpaceFlight\license.txt` içeren tek `DispSavers-<version>-win32.zip` arşivini oluşturur. Önceki ZIP çalıştırmanın başında silinir; doğrulama hatası yeni bir arşiv oluşturulmasını engeller.

## Lisans

DispSavers [MIT Lisansı](../license.txt) ile sunulur. Copyright © Petr Červinka — FortSoft 2026

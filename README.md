OpenMP ile Paralel Programlama

Bu çalışmanın amacı, paralel programlama kavramlarını anlamak ve uygulamaktır. Paralel programlama, modern işlemcilerin çok çekirdekli mimarilerinden tam anlamıyla yararlanarak yüksek performanslı yazılımlar geliştirme sürecini içerir. Bu bağlamda, OpenMP (Open Multi-Processing) kütüphanesi kullanılarak bir uygulama geliştirilmiştir. Bu uygulama, işlem süresi ve verimliliği artırmayı hedefleyen paralel programlama tekniklerini pratik etme ve analiz etme amacı taşımaktadır. Çalışmanın spesifik amaçları şunlardır:
1.	Paralel Programlama Tekniklerini Öğrenmek: OpenMP kullanarak, paralel bölümlerin nasıl tanımlandığını ve farklı iş parçacıklarına iş yükünün nasıl dağıtıldığını anlamak.
2.	Performans Artışı Sağlamak: Sıralı bir algoritmanın paralel hale getirilmesiyle sağlanan hızlanma oranını analiz etmek.
3.	Ölçeklenebilirliği Değerlendirmek: İş parçacığı sayısını artırarak, programın farklı çekirdek sayıları altında nasıl performans gösterdiğini test etmek ve ölçeklenebilirlik potansiyelini incelemek.
4.	Teorik ve Pratik Kısıtlamaları Analiz Etmek: Paralel programlamanın avantajlarının yanı sıra, Amdahl Yasası gibi teorik sınırların gerçek dünyadaki etkilerini değerlendirmek.
5.	Büyük Verilerin İşlenmesi: Matris çarpımı gibi hesaplama yoğun işlemleri paralel olarak gerçekleştirmek, böylece büyük ölçekli veri işleme süreçlerinde performansı artırmak için stratejiler geliştirmek.
Bu amaçlar doğrultusunda, paralel matris çarpımı uygulaması geliştirilmiş ve performans karşılaştırmaları gerçekleştirilmiştir. Çalışmanın sonunda, elde edilen bulgular ışığında paralel programlamanın avantajları, sınırlamaları ve uygulanabilirliği üzerine yorum yapılmıştır.
________________________________________
Paralel Programlama Nedir?

Paralel programlama, bir problemi daha küçük alt problemlere bölerek bu alt problemleri aynı anda birden fazla işlemci veya çekirdek üzerinde çalıştırma yöntemidir. Geleneksel sıralı programlama, işlemleri birer birer gerçekleştirirken, paralel programlama bu işlemleri eş zamanlı olarak çalıştırarak işlem süresini azaltmayı ve verimliliği artırmayı hedefler.
Paralel programlama aşağıdaki temel kavramlara dayanır:
1.	Görev Paralelliği: Farklı görevlerin (örneğin, dosya okuma ve veri işleme) aynı anda çalıştırılması.
2.	Veri Paralelliği: Aynı görevin farklı veri parçaları üzerinde eş zamanlı olarak gerçekleştirilmesi.
3.	Ölçeklenebilirlik: Programın, iş parçacığı sayısına bağlı olarak performansını artırma potansiyeli.
4.	Senkronizasyon: Paralel çalışan iş parçacıklarının birbiriyle iletişim kurması ve verilerin tutarlı kalması için kullanılan mekanizmalar
________________________________________
OpenMP Nedir?

OpenMP (Open Multi-Processing), paylaşımlı bellek mimarisine sahip çok çekirdekli sistemlerde paralel programlama yapmak için geliştirilmiş bir API'dir. C, C++ ve Fortran dillerini destekler ve paralel bölümleri tanımlamak için direktif tabanlı bir yaklaşıma sahiptir. OpenMP'nin temel özellikleri şunlardır:
1.	Kolay Kullanım: Mevcut sıralı kodlara minimal değişiklikle paralellik eklemeye olanak tanır. Programcılar, özel OpenMP direktiflerini kullanarak kodun paralel kısımlarını belirtebilir.
2.	Esneklik: İş yükü dağıtımı, iş parçacığı sayısı ve senkronizasyon gibi ayarları kontrol etmek için zengin bir yapı sunar.
3.	Paylaşımlı Bellek Modeli: OpenMP, iş parçacıklarının aynı bellek alanını paylaşmasını sağlar. Bu, verilerin kopyalanması gereksinimini ortadan kaldırarak performansı artırır.
4.	Dinamik ve Statik İş Yükü Dağıtımı: İş yükü, programın dinamik gereksinimlerine veya önceden tanımlanmış bir modele göre iş parçacıkları arasında dağıtılabilir.
5.	Platform Bağımsızlık: OpenMP, çeşitli işlemci mimarilerinde ve işletim sistemlerinde çalışabilir.
________________________________________
OpenMP'nin Temel Bileşenleri

1.	Paralel Bölümler:
○	#pragma omp parallel direktifi kullanılarak, bir kod bölümü paralel hale getirilebilir. Bu direktif, belirli bir kod bloğunu iş parçacıkları arasında dağıtır.
2.	Çalışma Paylaşımı:
○	Döngüler ve iş yükü dağıtımı, #pragma omp for gibi direktiflerle paralelleştirilir.
3.	Senkronizasyon:
○	İş parçacıkları arasındaki veri tutarlılığı, #pragma omp critical, #pragma omp barrier gibi direktiflerle sağlanır.
4.	İş Parçacığı Yönetimi:
○	İş parçacığı sayısı, omp_set_num_threads() fonksiyonu veya OMP_NUM_THREADS çevresel değişkeni ile kontrol edilebilir.
________________________________________
OpenMP'nin Avantajları ve Kısıtlamaları

Avantajlar:

1.	Kullanım Kolaylığı: Mevcut sıralı kodlara minimal değişiklikle paralellik eklenebilir.
2.	Hızlı Uygulama: İşlem sürelerini önemli ölçüde azaltabilir.
3.	Geniş Destek: Çeşitli işlemci ve işletim sistemi platformlarında çalışır.

Kısıtlamalar:

1.	Paylaşımlı Bellek Sınırlamaları: Bellek erişimi çatışmaları, ölçeklenebilirliği sınırlayabilir.
2.	Donanım Bağımlılığı: Performans, kullanılan donanımın özelliklerine bağlıdır.
3.	Senkronizasyon Maliyetleri: Paralel bölümler arasındaki senkronizasyon maliyetli olabilir.
Görev Detayları

1.	Hesaplama Görevi
○	Matris çarpma işlemi, paralel programlama için uygun bir problem olarak seçilmiştir. Bu işlem, hem sıralı hem de paralel olarak gerçekleştirilmiştir.
○	Matrisler, belirli bir boyutta (örneğin, 500x500) oluşturulmuş ve rastgele sayılarla doldurulmuştur. Bu, her iki uygulamanın da aynı giriş verileri üzerinde çalışmasını sağlamıştır.
2.	Farklı Sayıda İş Parçacığı Kullanımı
○	OpenMP kütüphanesi kullanılarak iş parçacığı sayısı sırasıyla 1, 2, 4 ve 8 olarak artırılmıştır.
○	Her iş parçacığı sayısı için paralel uygulama çalıştırılmış ve performans ölçümleri yapılmıştır.
3.	Performans Analizi ve Hızlanma Oranı
○	Sıralı versiyonun çalıştırma süresi referans alınarak paralel versiyonun hızlanma oranı hesaplanmıştır.
○	Farklı iş parçacığı sayıları için ölçeklenebilirlik ve performans kazançları analiz edilmiştir.
________________________________________
Sonuçlar ve Analiz

Aşağıda, farklı iş parçacığı sayıları için elde edilen sonuçlar özetlenmiştir:
●	Sıralı Versiyon: Referans olarak kullanılan sıralı uygulama, 1 iş parçacığı ile çalıştırılmıştır ve temel performans ölçütlerini sağlamıştır.
●	Paralel Versiyon: İş parçacığı sayısı arttıkça, paralel uygulamanın çalışma süresi belirgin şekilde azalmıştır. Ancak, iş parçacığı sayısı arttıkça hızlanma oranında bir azalma gözlemlenmiştir.

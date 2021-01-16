# C-Dizideki en yakın iki sayı (Sırasız ve Sıralı Dizi)
Dizi içerisindeki en yakın iki sayıyı farklı iki yöntem ve iki farklı zaman karmaşıklığında bulan c kodlarıdır.

Bu kodlar time complexity'ye dikkat çekmek amacıyla yazılmıştır. Aynı işlemler farklı zaman karmaşılıklarında çözülebilmektedir.

Önce dizinin boyutu kullanıcıdan alınmaktadır. Dizinin boyutu alındıktan sonra 1 ile 100 arasında rastgele sayılar ile doldurulmuştur.

Dizilerde işlem yaparken kodlarımızın daha efektif çalışabilmesi için bilinmesi gereken ilk şey dizinin sıralı olup olmama durumudur. Burada sayılar bulunurken ilk olarak
brute force (zor kullanma) yöntemi kullanılmıştır. Brute force yönteminde tüm ihtimaller tek tek konrol edilmelidir. Bu durum bizi N^2 karmaşıklığına götürmektedir 
fakat eğer dizi sıralı olsaydı tek turda bu sayı çiftini bulabilecektik. 

İkinci yöntemde ise dizi merge sort ile sıralandıktan sonra bir kez dönülerek bu sayılara ulaşılmıştır. Merge sort ile sıralanırken karmaşıklığımız NLogN olacaktır. 
Dizi sıralandıktan sonra sıralı ikilileri karşılaştırarak en yakın iki sayı belirlenebilir.

# Percobaan LED – FreeRTOS pada ESP32-S3

## Tujuan
Percobaan ini bertujuan untuk memahami bagaimana satu *task* pada FreeRTOS dapat mengontrol beberapa LED secara bersamaan dan dijalankan pada core tertentu dari prosesor ESP32-S3.  
Melalui percobaan ini, mahasiswa dapat mempelajari cara kerja sistem multitasking dan pembagian beban kerja antar core (Core 0 dan Core 1).

---

## Konfigurasi Komponen
Tiga buah LED digunakan dengan konfigurasi sebagai berikut:

| Komponen  | GPIO | Keterangan |
|-----------|------|------------|
| LED Hijau | 3    | Output |
| LED Putih | 7    | Output |
| LED Tosca | 15   | Output |

Ketiga LED dikendalikan secara bersamaan melalui satu task yang berjalan di salah satu core prosesor.

---

## Alur Program
1. **Inisialisasi Pin Output**  
   Program dimulai dengan mendefinisikan tiga pin GPIO sebagai *output*. Hal ini memungkinkan setiap LED menerima sinyal logika HIGH dan LOW dari mikrokontroler.

2. **Pembuatan Task LED**  
   Sebuah task baru dibuat menggunakan fungsi `xTaskCreatePinnedToCore()`.  
   Fungsi ini merupakan bagian dari FreeRTOS dan digunakan untuk menentukan di core mana task akan dijalankan.  
   Dengan parameter terakhir (`0` atau `1`), pengguna dapat memilih apakah task dijalankan di Core 0 atau Core 1.

3. **Proses Utama Task**  
   Task yang telah dibuat berfungsi untuk menyalakan dan mematikan ketiga LED secara bersamaan.  
   Setelah LED menyala, sistem menunggu selama 500 milidetik (*delay non-blocking*) menggunakan `vTaskDelay()`.  
   Setelah itu, ketiga LED dimatikan dan menunggu lagi selama 500 milidetik.  
   Proses ini berjalan berulang terus-menerus selama sistem aktif.

4. **Menentukan Core Eksekusi**  
   Pada bagian pembuatan task, parameter terakhir menentukan core yang akan menjalankan task.  
   - Jika nilainya `0`, task berjalan di **Core 0**.  
   - Jika nilainya `1`, task berjalan di **Core 1**.  
   Dengan cara ini, kita dapat mengamati bagaimana task dijalankan pada dua prosesor yang berbeda tetapi memberikan hasil yang sama.

5. **Loop Utama (loop())**  
   Fungsi `loop()` tidak memiliki logika utama karena seluruh proses dijalankan oleh FreeRTOS melalui task yang sudah dibuat.  
   Fungsi ini hanya berisi jeda ringan untuk menjaga kestabilan sistem.

---

## Hasil Percobaan
Ketiga LED berkedip bersamaan setiap 500 milidetik.  
Hasil percobaan menunjukkan bahwa baik Core 0 maupun Core 1 dapat menjalankan task LED tanpa perbedaan hasil secara fungsional.  
Perbedaannya hanya pada core tempat proses dieksekusi, yang dapat dilihat dari output Serial Monitor.

---

## Kesimpulan
1. FreeRTOS memungkinkan pembuatan task yang dapat dijalankan secara paralel di beberapa core prosesor.  
2. Satu task dapat mengontrol beberapa perangkat sekaligus (dalam hal ini tiga LED).  
3. Fungsi `xTaskCreatePinnedToCore()` berperan penting dalam menentukan pembagian beban kerja antar core.  
4. Percobaan ini membuktikan bahwa ESP32-S3 mampu menjalankan multitasking nyata tanpa mengganggu proses utama sistem.

---

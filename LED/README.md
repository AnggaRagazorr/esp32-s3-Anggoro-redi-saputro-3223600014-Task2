# TaskLED – Blink 3 LED Bersamaan

## Tujuan
Percobaan ini bertujuan untuk memahami cara mengontrol beberapa LED secara bersamaan menggunakan sistem operasi **FreeRTOS** pada mikrokontroler **ESP32-S3**.  
Pada percobaan ini, tiga LED (Hijau, Putih, Tosca) dikontrol secara serentak menggunakan satu task yang dijalankan di core tertentu (Core 0 atau Core 1).  
Tujuan lainnya adalah untuk mempelajari bagaimana task pada FreeRTOS bekerja secara paralel dan bagaimana pembagian kerja antar core dapat diatur.

---

## Konfigurasi Pin

| Komponen | GPIO | Fungsi |
|-----------|-------|---------|
| LED Hijau | 3 | Output |
| LED Putih | 7 | Output |
| LED Tosca | 15 | Output |

Ketiga LED dihubungkan ke pin digital pada ESP32-S3, dengan resistor seri untuk membatasi arus.

---

## Struktur dan Penjelasan Task

### Inisialisasi Pin

Bagian ini digunakan untuk mendefinisikan ketiga pin LED sebagai output agar dapat dikontrol dengan `digitalWrite()`.

```cpp
pinMode(LED_HIJAU, OUTPUT);
pinMode(LED_PUTIH, OUTPUT);
pinMode(LED_TOSCA, OUTPUT);

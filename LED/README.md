# TaskLED – Blink 3 LED Bersamaan

## Tujuan
Percobaan ini bertujuan untuk memahami cara mengontrol beberapa LED secara bersamaan menggunakan sistem operasi **FreeRTOS** pada mikrokontroler **ESP32-S3**.  
Tiga LED (Hijau, Putih, Tosca) dikontrol secara serentak menggunakan satu task yang dijalankan di core tertentu.  
Tujuan lain adalah untuk memahami bagaimana task bekerja paralel dan pembagian kerja antar-core.

---

## Konfigurasi Pin

| Komponen | GPIO | Fungsi |
|-----------|-------|---------|
| LED Hijau | 3 | Output |
| LED Putih | 7 | Output |
| LED Tosca | 15 | Output |

---

## Struktur dan Penjelasan Task

### 🧩 Inisialisasi Pin

Bagian ini digunakan untuk mendefinisikan ketiga pin LED sebagai output agar dapat dikontrol dengan `digitalWrite()`.

```cpp
pinMode(LED_HIJAU, OUTPUT);
pinMode(LED_PUTIH, OUTPUT);
pinMode(LED_TOSCA, OUTPUT);

---

ff

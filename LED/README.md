# TaskLED – Tiga LED Blink Bersamaan

## Tujuan
Percobaan ini bertujuan untuk menguji cara kerja multitasking pada ESP32-S3 menggunakan FreeRTOS.  
Tiga LED dikontrol bersamaan melalui satu task agar berkedip secara serentak.

---

## Konfigurasi Pin

| Warna LED | GPIO | Fungsi |
|------------|-------|---------|
| Hijau | 3 | Output |
| Putih | 7 | Output |
| Tosca | 15 | Output |

---

## Penjelasan Program

Program menggunakan konsep **task** di FreeRTOS untuk menjalankan tiga LED secara paralel.  
Berikut beberapa bagian penting dari program:

### 1. Inisialisasi Pin
```cpp
pinMode(LED_HIJAU, OUTPUT);
pinMode(LED_PUTIH, OUTPUT);
pinMode(LED_TOSCA, OUTPUT);

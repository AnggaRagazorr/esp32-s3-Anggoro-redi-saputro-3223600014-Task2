# Percobaan Buzzer – FreeRTOS pada ESP32-S3

## Tujuan
Mengetes kontrol buzzer secara periodik menggunakan task FreeRTOS dengan pengaturan prioritas dan core yang berbeda.

---

## Konfigurasi Komponen
| Komponen | GPIO | Keterangan |
|-----------|------|------------|
| Buzzer | 4 | Output |

---

## Alur Program
- **TaskBuzzer** dijalankan di **Core 0** dengan **prioritas 2**.  
- Buzzer aktif selama 200 ms, lalu diam 1800 ms menggunakan `vTaskDelay()`.  
- Frekuensi bunyi tidak dipengaruhi oleh task lain karena menggunakan delay non-blocking.

---

## Hasil Percobaan
![Hasil Buzzer](../assets/Percobaan_Buzzer.gif)

---

## Kesimpulan
- Task berprioritas menengah membuat buzzer tetap stabil.  
- Tidak mengganggu task LED dengan prioritas lebih rendah.


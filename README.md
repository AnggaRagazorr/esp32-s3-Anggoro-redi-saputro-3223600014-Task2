# esp32-s3-Anggoro-redi-saputro-3223600014-Task2
Anggoro redi saputro 
3223600014
3 D4 Teknik Komputer A

Tujuan Percobaan
Percobaan ini bertujuan untuk memahami cara kerja multitasking menggunakan FreeRTOS pada ESP32-S3 dengan membuat setiap peripheral dijalankan sebagai task terpisah.
Setiap task bekerja secara independen tanpa saling bergantung, berjalan bersamaan di dua core (Core 0 dan Core 1) dengan prioritas berbeda.

Tabel Pin Konfigurasi
| Komponen           | Pin ESP32-S3 | Keterangan     |
| ------------------ | ------------ | -------------- |
| LED Hijau          | GPIO 3       | Output         |
| LED Putih          | GPIO 7       | Output         |
| LED Tosca          | GPIO 15      | Output         |
| Buzzer             | GPIO 4       | Output         |
| Button 1           | GPIO 19      | Input (PULLUP) |
| Button 2           | GPIO 21      | Input (PULLUP) |
| Potensiometer      | GPIO 5       | Analog Input   |
| Servo              | GPIO 42      | PWM Output     |
| Rotary Encoder CLK | GPIO 10      | Digital Input  |
| Rotary Encoder DT  | GPIO 11      | Digital Input  |
| Stepper A–         | GPIO 40      | Output         |
| Stepper A+         | GPIO 39      | Output         |
| Stepper B+         | GPIO 38      | Output         |
| Stepper B–         | GPIO 37      | Output         |
| OLED SDA           | GPIO 8       | I²C SDA        |
| OLED SCL           | GPIO 9       | I²C SCL        |

Struktur Task dan Core Assignment
| Task        | Fungsi                       | Core   | Priority | Keterangan                        |
| ----------- | ---------------------------- | ------ | -------- | --------------------------------- |
| TaskLED1    | Blink LED Hijau              | Core 0 | 1        | Nyala-mati cepat                  |
| TaskLED2    | Blink LED Putih              | Core 1 | 2        | Nyala-mati sedang                 |
| TaskLED3    | Blink LED Tosca              | Core 0 | 3        | Nyala-mati cepat                  |
| TaskBuzzer  | Bunyikan buzzer tiap 2 detik | Core 0 | 4        | Aktif-mati bergantian             |
| TaskButton1 | Deteksi tombol 1             | Core 1 | 5        | Tampilkan di Serial Monitor       |
| TaskButton2 | Deteksi tombol 2             | Core 1 | 5        | Tampilkan di Serial Monitor       |
| TaskPot     | Baca potensiometer           | Core 0 | 6        | Kirim nilai ke Serial Monitor     |
| TaskServo   | Gerakkan servo 0°–180°       | Core 0 | 7        | Bergerak bolak-balik              |
| TaskEncoder | Hitung putaran encoder       | Core 1 | 6        | Tampilkan nilai ke Serial Monitor |
| TaskOLED    | Tampilkan data Pot & Encoder | Core 0 | 8        | Update layar tiap 0.5 s           |
| TaskStepper | Putar stepper motor          | Core 1 | 4        | Rotasi berulang (tanpa driver)    |

Penjelasan Mekanisme FreeRTOS
1. xTaskCreatePinnedToCore()
   Fungsi ini digunakan untuk membuat task baru pada FreeRTOS dan menentukan core mana yang menjalankannya.
2.vTaskDelay()
   Digunakan menggantikan delay() agar CPU tetap bisa menjalankan task lain selama satu task menunggu.

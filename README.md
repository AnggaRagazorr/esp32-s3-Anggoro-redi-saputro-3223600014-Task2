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



Penjelasan Mekanisme FreeRTOS
1. xTaskCreatePinnedToCore()
   Fungsi ini digunakan untuk membuat task baru pada FreeRTOS dan menentukan core mana yang menjalankannya.
2.vTaskDelay()
   Digunakan menggantikan delay() agar CPU tetap bisa menjalankan task lain selama satu task menunggu.

TaskLED 

Tujuan
Menjalankan tiga buah LED (Hijau, Putih, Tosca) secara bersamaan dalam satu task menggunakan FreeRTOS.
Task ini menunjukkan cara membuat fungsi paralel di Core tertentu tanpa blocking delay(),
menggunakan fungsi vTaskDelay() agar sistem tetap multitasking.

Konfigurasi Pin
| Warna LED | GPIO | Fungsi |
| --------- | ---- | ------ |
| Hijau     | 3    | Output |
| Putih     | 7    | Output |
| Tosca     | 15   | Output |

Penjelasan Kode
1. Deklarasi Pin
#define LED_HIJAU 3
#define LED_PUTIH 7
#define LED_TOSCA 15

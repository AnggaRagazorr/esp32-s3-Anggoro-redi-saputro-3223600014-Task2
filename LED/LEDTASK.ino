#define LED_HIJAU 3
#define LED_PUTIH 7
#define LED_TOSCA 15

void TaskLED(void *pvParameters) {
  pinMode(LED_HIJAU, OUTPUT);
  pinMode(LED_PUTIH, OUTPUT);
  pinMode(LED_TOSCA, OUTPUT);

  while (1) {
    // Nyalakan semua LED
    digitalWrite(LED_HIJAU, HIGH);
    digitalWrite(LED_PUTIH, HIGH);
    digitalWrite(LED_TOSCA, HIGH);
    Serial.printf("LEDs ON | Core: %d\n", xPortGetCoreID());
    vTaskDelay(500 / portTICK_PERIOD_MS);  // Tunda 500 ms

    // Matikan semua LED
    digitalWrite(LED_HIJAU, LOW);
    digitalWrite(LED_PUTIH, LOW);
    digitalWrite(LED_TOSCA, LOW);
    Serial.printf("LEDs OFF | Core: %d\n", xPortGetCoreID());
    vTaskDelay(500 / portTICK_PERIOD_MS);  // Tunda 500 ms
  }
}

void setup() {
  Serial.begin(115200);

  // Core 0
  //xTaskCreatePinnedToCore(TaskLED, "TaskLED_Core0", 2000, NULL, 1, NULL, 0);
  // Core 1
   xTaskCreatePinnedToCore(TaskLED, "TaskLED_Core1", 2000, NULL, 1, NULL, 1);
}

void loop() {}

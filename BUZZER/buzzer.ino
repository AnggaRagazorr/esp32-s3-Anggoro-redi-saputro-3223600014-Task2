#define BUZZER 4

void TaskBuzzer(void *pvParameters) {
  pinMode(BUZZER, OUTPUT);
  while (1) {
    digitalWrite(BUZZER, HIGH);
    Serial.printf("Buzzer ON | Core: %d\n", xPortGetCoreID());
    vTaskDelay(300 / portTICK_PERIOD_MS);
    digitalWrite(BUZZER, LOW);
    Serial.printf("Buzzer OFF | Core: %d\n", xPortGetCoreID());
    vTaskDelay(700 / portTICK_PERIOD_MS);
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(BUZZER, OUTPUT);

  // Core 0
  xTaskCreatePinnedToCore(TaskBuzzer, "TaskBuzzer_Core0", 2000, NULL, 2, NULL, 0);
  // Core 1
  // xTaskCreatePinnedToCore(TaskBuzzer, "TaskBuzzer_Core1", 2000, NULL, 2, NULL, 1);
}

void loop() {}


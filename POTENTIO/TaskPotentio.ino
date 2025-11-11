#define POT_PIN 5

void TaskPot(void *pvParameters) {
  while (1) {
    int val = analogRead(POT_PIN);
    Serial.printf("Potentiometer: %d | Core: %d\n", val, xPortGetCoreID());
    vTaskDelay(300 / portTICK_PERIOD_MS);
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(POT_PIN, INPUT);

  // Core 0
  xTaskCreatePinnedToCore(TaskPot, "TaskPot_Core0", 2000, NULL, 4, NULL, 1);
}

void loop() {}


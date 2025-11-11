#define BUTTON 18

void TaskButton(void *pvParameters) {
  pinMode(BUTTON, INPUT_PULLUP);
  while (1) {
    if (digitalRead(BUTTON) == LOW) {
      Serial.printf("Button Pressed | Core: %d\n", xPortGetCoreID());
    }
    vTaskDelay(50 / portTICK_PERIOD_MS);
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON, INPUT_PULLUP);

  // Core 1
  xTaskCreatePinnedToCore(TaskButton, "TaskButton_Core1", 2000, NULL, 3, NULL, 1);
}

void loop() {}


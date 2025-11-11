#define CLK 10
#define DT 11
int lastStateCLK, counter = 0;

void TaskEncoder(void *pvParameters) {
  pinMode(CLK, INPUT);
  pinMode(DT, INPUT);
  lastStateCLK = digitalRead(CLK);
  while (1) {
    int currentStateCLK = digitalRead(CLK);
    if (currentStateCLK != lastStateCLK) {
      if (digitalRead(DT) != currentStateCLK) counter++;
      else counter--;
      Serial.printf("Encoder Count: %d | Core: %d\n", counter, xPortGetCoreID());
    }
    lastStateCLK = currentStateCLK;
    vTaskDelay(10 / portTICK_PERIOD_MS);
  }
}

void setup() {
  Serial.begin(115200);

  // Core 1
  xTaskCreatePinnedToCore(TaskEncoder, "TaskEncoder_Core1", 2000, NULL, 4, NULL, 1);
}

void loop() {}


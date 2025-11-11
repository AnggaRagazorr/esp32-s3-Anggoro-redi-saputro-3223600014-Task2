#define BMINUS 37
#define BPLUS 38
#define APLUS 39
#define AMINUS 40

void TaskStepper(void *pvParameters) {
  int seq[4][4] = {
    {1, 0, 1, 0},
    {0, 1, 1, 0},
    {0, 1, 0, 1},
    {1, 0, 0, 1}
  };

  pinMode(BMINUS, OUTPUT);
  pinMode(BPLUS, OUTPUT);
  pinMode(APLUS, OUTPUT);
  pinMode(AMINUS, OUTPUT);

  while (1) {
    for (int step = 0; step < 4; step++) {
      digitalWrite(AMINUS, seq[step][0]);
      digitalWrite(APLUS, seq[step][1]);
      digitalWrite(BPLUS, seq[step][2]);
      digitalWrite(BMINUS, seq[step][3]);
      Serial.printf("Stepper step: %d | Core: %d\n", step, xPortGetCoreID());
      vTaskDelay(5 / portTICK_PERIOD_MS);
    }
  }
}

void setup() {
  Serial.begin(115200);

  // Core 1
  xTaskCreatePinnedToCore(TaskStepper, "TaskStepper_Core1", 3000, NULL, 5, NULL, 1);
}

void loop() {}


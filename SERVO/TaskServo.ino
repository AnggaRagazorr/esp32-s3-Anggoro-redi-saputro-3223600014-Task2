#include <ESP32Servo.h>
#define SERVO_PIN 42
Servo myservo;

void TaskServo(void *pvParameters) {
  myservo.attach(SERVO_PIN);
  while (1) {
    for (int pos = 0; pos <= 180; pos += 20) {
      myservo.write(pos);
      Serial.printf("Servo angle: %d | Core: %d\n", pos, xPortGetCoreID());
      vTaskDelay(300 / portTICK_PERIOD_MS);
    }
    for (int pos = 180; pos >= 0; pos -= 20) {
      myservo.write(pos);
      Serial.printf("Servo angle: %d | Core: %d\n", pos, xPortGetCoreID());
      vTaskDelay(300 / portTICK_PERIOD_MS);
    }
  }
}

void setup() {
  Serial.begin(115200);
  myservo.attach(SERVO_PIN);

  // Core 0
  xTaskCreatePinnedToCore(TaskServo, "TaskServo_Core0", 3000, NULL, 5, NULL, 0);
}

void loop() {}

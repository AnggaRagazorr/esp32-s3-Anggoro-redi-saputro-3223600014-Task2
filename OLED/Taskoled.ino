#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void TaskOLED(void *pvParameters) {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  int count = 0;

  while (1) {
    display.clearDisplay();
    display.setCursor(0, 10);
    display.print("Task OLED Running");
    display.setCursor(0, 30);
    display.print("Counter: ");
    display.println(count++);
    display.display();

    Serial.printf("OLED Updated | Core: %d\n", xPortGetCoreID());
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}

void setup() {
  Serial.begin(115200);
  Wire.begin(8, 9);

  // Core 0
  xTaskCreatePinnedToCore(TaskOLED, "TaskOLED_Core0", 4000, NULL, 3, NULL, 0);
}

void loop() {}


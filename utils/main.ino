#include <Adafruit_NeoPixel.h>

// Pin definitions
#define ONBOARD_LED_PIN 8  // Onboard LED 
#define NEOPIXEL_PIN 1     // NeoPixel data 

#define TOTAL_PIXELS 13

// NeoPixel objects
Adafruit_NeoPixel onboard(1, ONBOARD_LED_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel external(TOTAL_PIXELS - 1, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);

// Transgender flag colors (RGB)
uint32_t transFlag[] = {
  onboard.Color(91, 206, 250),  // Light blue
  onboard.Color(245, 169, 184), // Pink
  onboard.Color(255, 255, 255), // White
  onboard.Color(245, 169, 184), // Pink
  onboard.Color(91, 206, 250)   // Light blue
};

const int delayTime = 500; // Delay between color changes
int currentColorIndex = 0;

void updatePixels(uint32_t color) {
  // Update onboard pixel
  onboard.setPixelColor(0, color);

  // Update external pixels
  for (int i = 0; i < TOTAL_PIXELS - 1; i++) {
    external.setPixelColor(i, color);
  }

  // Apply changes
  onboard.show();
  external.show();
}

void setup() {
  // Initialize NeoPixel objects
  onboard.begin();
  onboard.setBrightness(200);
  onboard.show();

  external.begin();
  external.setBrightness(200);
  external.show();
}

void loop() {
  // Set all pixels to the current color
  updatePixels(transFlag[currentColorIndex]);

  // Move to the next color
  currentColorIndex = (currentColorIndex + 1) % 5;

  // Wait before updating again
  delay(delayTime);
}

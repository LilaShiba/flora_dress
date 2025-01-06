#include <Adafruit_FloraPixel.h>
#include <Adafruit_NeoPixel.h>

// Configuration
#define PIXEL_PIN 1        // Pin where NeoPixels are connected
#define NUM_PIXELS 13     // Number of chained NeoPixels
#define BRIGHTNESS 255     // Brightness level (0-255)

Adafruit_NeoPixel pixels(NUM_PIXELS, PIXEL_PIN, NEO_GRB + NEO_KHZ800); // Initialize NeoPixel object

// Function to set all pixels to a single color
void setColor(uint32_t color) {
  pixels.fill(color);    // Set all pixels to the same color
  pixels.show();         // Update the NeoPixels
}

// Cycle color for all pixels
void colorCycle(int wait) {
  setColor(pixels.Color(255, 0, 0));  // Red
  delay(wait);
  setColor(pixels.Color(0, 255, 0));  // Green
  delay(wait);
  setColor(pixels.Color(0, 0, 255));  // Blue
  delay(wait);
}

// Cycle colors for each individual pixel sequentially
void individualColors(int wait) {
  static int i = 0;
  // Count for getting idx and color of led
  i += 1;
  int idx = i % (NUM_PIXELS-1);
  int pixel_color = i % 3

  // Color
  if (pixel_color == 1){
      pixels.setPixelColor((idx, pixels.Color(255, 0, 0));
  } else if (pixel_color == 2){
      pixels.setPixelColor((idx, pixels.Color(0, 255, 0));
  } else{
      pixels.setPixelColor((idx, pixels.Color(0,0,255));
  }

  pixels.show();  
  delay(wait);
}

void setup() {
  pixels.begin();       // Initialize NeoPixel strip
  pixels.setBrightness(BRIGHTNESS);  // Set brightness
}

void loop() {
  // colorCycle(500);        // Change color every 500 milliseconds
  individualColors(100);  // Set each pixel individually with a delay
}

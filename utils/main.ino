#include <Adafruit_FloraPixel.h>

#include <Adafruit_NeoPixel.h>

// Configuration
#define PIXEL_PIN 1       
#define NUM_PIXELS 13    
#define BRIGHTNESS 255     
// Initialize NeoPixel object
Adafruit_NeoPixel pixels(NUM_PIXELS, PIXEL_PIN, NEO_GRB + NEO_KHZ800); 

uint32_t lightBlue = pixels.Color(85, 205, 252);  // #55CDFC
uint32_t pink = pixels.Color(247, 168, 184);     // #F7A8B8
uint32_t white = pixels.Color(255, 255, 255);    // #FFFFFF


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
  static int i = -1;
  // Count for getting idx and color of led
  i += 1;
  int idx = i % (NUM_PIXELS-1);
  int pixel_color = i % 3;

  // Color
  if (pixel_color == 1){
      pixels.setPixelColor(idx, lightBlue);
  } else if (pixel_color == 2){
      pixels.setPixelColor(idx, pink);
  } else{
      pixels.setPixelColor(idx, white);
  }

  pixels.show();  
  delay(wait);
}

void setup() {
  pixels.begin();       // Initialize NeoPixel strip
  pixels.setBrightness(BRIGHTNESS);  // Set brightness
  setColor(white);
}

void loop() {
  // colorCycle(500);        // Change color every 500 milliseconds
  individualColors(100);  // Set each pixel individually with a delay
}

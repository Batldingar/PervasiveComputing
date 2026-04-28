#include <Adafruit_NeoPixel.h>

#define POWER_PIN    13   
#define DATA_PIN     12  
#define NUMPIXELS    16   

Adafruit_NeoPixel pixels(NUMPIXELS, DATA_PIN, NEO_GRB + NEO_KHZ800);

int offset = 0; // shifts the pattern each time

void setup() {
  pinMode(POWER_PIN, OUTPUT);
  digitalWrite(POWER_PIN, HIGH);
  delay(10); 
  pixels.begin();
}

void loop() {
  pixels.clear();

  // Loop through all 16 LEDs
  for(int i = 0; i < NUMPIXELS; i++) {
    // This creates a repeating pattern: Red, Green, Blue, Off, Red, Green, Blue...
    if ((i + offset) % 4 == 0) {
      pixels.setPixelColor(i, pixels.Color(150, 0, 0));   // Red
    } else if ((i + offset) % 4 == 1) {
      pixels.setPixelColor(i, pixels.Color(0, 150, 0));   // Green
    } else if ((i + offset) % 4 == 2) {
      pixels.setPixelColor(i, pixels.Color(0, 0, 150));   // Blue
    }
    // The 4th state ( % 4 == 3 ) is left as "clear"
  }

  pixels.show();
  
  offset++; // Shift the starting point for the next frame
  if (offset >= 4) offset = 0; 

  delay(150); // 
}

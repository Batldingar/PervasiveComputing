#include <Adafruit_NeoPixel.h>

// Choose your pins
#define POWER_PIN    13   // This pin will act as your "VCC"
#define DATA_PIN     12  // This pin sends the color data
#define NUMPIXELS    2   

Adafruit_NeoPixel pixels(NUMPIXELS, DATA_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // Set the Power Pin to OUTPUT and turn it HIGH (3.3V)
  pinMode(POWER_PIN, OUTPUT);
  digitalWrite(POWER_PIN, HIGH);

  // Give the LED a tiny moment to wake up after receiving power
  delay(10); 

  pixels.begin();
}

void loop() {
  // Set to Red
  pixels.setPixelColor(0, pixels.Color(150, 0, 0));
  // Set to Blue
  pixels.setPixelColor(1, pixels.Color(0, 0, 150));
  pixels.show();
  
  delay(1000); 
}

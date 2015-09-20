#include "application.h"
#include "neopixel.h"

// IMPORTANT: Set pixel COUNT, PIN and TYPE

// The digital data pin that the strip is plugged into.
#define PIXEL_PIN D0

// The number of pixels (LEDs) in your strip.
#define PIXEL_COUNT 15

// The type of pixel LED being used. You shouldn't have to change this!
#define PIXEL_TYPE WS2812B

// Instantiate an LED strip
Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

void setup() 
{
  // Start the strip
  strip.begin();

  // Initialize all pixels to 'off'
  strip.show();

  // 0-100. More brightness = more power.
  strip.setBrightness(40);
}
void loop() 
{
  rainbow(20);
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}
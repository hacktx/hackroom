#include "application.h"
#include "neopixel.h"

// IMPORTANT: Set pixel COUNT, PIN and TYPE
#define PIXEL_PIN D0
#define PIXEL_COUNT 150
#define PIXEL_TYPE WS2812B

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

void setup() 
{
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  strip.setBrightness(50);  // 0-100. More bright = more power :(
}
void loop() 
{
  halvesBackAndForth(40);
}

void halvesBackAndForth(uint8_t wait, uint16_t lcdWait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      if (i % 2 == 0) {
        strip.setPixelColor(i, Wheel((i+j) & 255));
        strip.setPixelColor(strip.numPixels() - i - 1, Wheel((255 -i-j) & 255));
      } else {
        strip.setPixelColor(i, Wheel((255 -i-j) & 255));
        strip.setPixelColor(strip.numPixels() - i - 1, Wheel((i+j) & 255));
      }
      strip.show();
    }
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
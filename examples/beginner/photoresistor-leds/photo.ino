
// The pin that the photoresistor is plugged into.
#define ANALOG_PIN = A0

// LED Stuff. See the rainbow project for details.
#define PIXEL_PIN D0
#define PIXEL_COUNT 15
#define PIXEL_TYPE WS2812B

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

void setup() 
{
  // More LED stuff.
  strip.begin();
  strip.show();
  strip.setBrightness(40);
}

void loop() 
{
  color(20);
}

void color(uint8_t wait) {
  uint16_t i;

  // Read light intensity from photoresistor
  int light_intensity = analogRead(ANALOG_PIN);
  for(i=0; i<strip.numPixels(); i++) {
    // Set color based on light intensity.
    strip.setPixelColor(i, Wheel((light_intensity) & 255));
  }
  strip.show();
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
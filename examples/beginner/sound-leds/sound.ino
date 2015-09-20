// LED Stuff. See the rainbow project for details.
#define PIXEL_PIN D0
#define PIXEL_COUNT 15
#define PIXEL_TYPE WS2812B

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

// Sound sensor stuff
#define PIN_GATE_IN D1
#define IRQ_GATE_IN  D2
#define PIN_ANALOG_IN A0

void setup() 
{
  // More LED stuff.
  strip.begin();
  strip.show();
  strip.setBrightness(40);

  // configure input
  pinMode(PIN_GATE_IN, INPUT);

  // Attach an interrupt handler to be called when the state on IRQ_GATE_IN is changed.
  attachInterrupt(IRQ_GATE_IN, soundInterrupt, CHANGE);
}

void soundInterrupt()
{
  int pin_val;

  pin_val = digitalRead(PIN_GATE_IN);
  // do stuff with information
}

void loop() 
{
  color(20);
}

void color(uint8_t wait) {
  uint16_t i;

  // Read sound input
  int sound_intensity = analogRead(PIN_ANALOG_IN);
  for(i=0; i<strip.numPixels(); i++) {
    // Set color based on sound intensity.
    // <10 = quiet, 10 < x < 30 = moderate, > 30 = loud.
    strip.setPixelColor(i, Wheel((255 * sound_intensity / 40) & 255));
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
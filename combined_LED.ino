#combined red_blue and raindbow, alternating with delay
#include <FastLED.h>

FASTLED_USING_NAMESPACE

#define DATA_PIN    12
#define LED_TYPE    SK6812
#define COLOR_ORDER GRB
#define NUM_LEDS    144
#define NUM_COLOURS 2
#define CONSEC_LED 5
CRGB leds[NUM_LEDS];

#define BRIGHTNESS          96
#define FRAMES_PER_SECOND  120

void setup() {
  delay(3000); // 3 second delay for recovery
  
  // tell FastLED about the LED strip configuration
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setMaxPowerInVoltsAndMilliamps(5,500);
  FastLED.clear();
  FastLED.show();

  FastLED.setBrightness(BRIGHTNESS);
}


// List of patterns to cycle through.  Each is defined as a separate function below.
typedef void (*SimplePatternList[])();
SimplePatternList gPatterns = { rainbow, red_blue};

uint8_t gCurrentPatternNumber = 0; // Index number of which pattern is current
uint8_t gHue = 0; // rotating "base color" used by many of the patterns
  
void loop()
{
  // Call the current pattern function once, updating the 'leds' array
  gPatterns[gCurrentPatternNumber]();

  // send the 'leds' array out to the actual LED strip
  FastLED.show();  
  // insert a delay to keep the framerate modest
  FastLED.delay(1000/FRAMES_PER_SECOND); 

  // do some periodic updates
  EVERY_N_MILLISECONDS( 20 ) { gHue++; } // slowly cycle the "base color" through the rainbow
  EVERY_N_SECONDS( 10 ) { nextPattern(); } // change patterns periodically
}

#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))

void nextPattern()
{
  // add one to the current pattern number, and wrap around at the end
  gCurrentPatternNumber = (gCurrentPatternNumber + 1) % ARRAY_SIZE( gPatterns);
}

void rainbow() 
{
  // FastLED's built-in rainbow generator
  fill_rainbow( leds, NUM_LEDS, gHue, 7);
}

void red_blue() {
  // put your main code here, to run repeatedly:

// RED            GREEEN              BLUE
//  LEDS[0] = CRGB(225, 0 ,0);
//FastLED.show();

//getting the red and blue alternating colours
int i; // declare i again
for (int i = 0; i < NUM_LEDS; i++) {
  if ((i/CONSEC_LED) % NUM_COLOURS == 0) {
    leds[i] = CRGB(255, 0, 0); // Red light
  } else {
    leds[i] = CRGB(0, 0, 255); // Blue light
  }
}
FastLED.show();
delay(100);
} 

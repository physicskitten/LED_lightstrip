#include <FastLED.h>

#define LED_PIN    12          // Pin connected to the LED strip
#define LED_TYPE   SK6812      // Type of LED strip (e.g., WS2812, SK6812)
#define NUM_LEDS   144         // Total number of LEDs on the strip
#define COLOR_ORDER GRB        // Color order of the LEDs
#define BRIGHTNESS 96          // Brightness of the LEDs
#define FRAMES_PER_SECOND 120  // Refresh rate of the LEDs

#define NUM_COLOURS 2          // Number of colors in the alternating pattern
#define CONSEC_LED 5           // Number of consecutive LEDs per color

CRGB leds[NUM_LEDS];           // Array to hold the LED data

// Define your colors here
CRGB color1 = CRGB(255, 0, 0); // Red
CRGB color2 = CRGB(0, 0, 255); // Blue

void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.clear();
  FastLED.show();
}

void loop() {
  // Calibration pattern: alternating colors
  for (int i = 0; i < NUM_LEDS; i++) {
    if ((i / CONSEC_LED) % NUM_COLOURS == 0) {
      leds[i] = color1; // First color (Red)
    } else {
      leds[i] = color2; // Second color (Blue)
    }
  }
  
  FastLED.show();
  delay(100); // Delay to control the refresh rate
}

// Function to add more colors in the future
void addMoreColors() {
  // Add additional colors to this array if needed
  CRGB colors[] = {CRGB(255, 0, 0), CRGB(0, 0, 255), CRGB(0, 255, 0)}; // Example: Red, Blue, Green
  
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = colors[(i / CONSEC_LED) % NUM_COLOURS];
  }
  
  FastLED.show();
  delay(100);
}

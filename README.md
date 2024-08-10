This repository contains code to control a programmable LED light strip using the FastLED library. The project is set up to display alternating red and blue colors on the LEDs, but it can be easily modified to support different colors and patterns.

#Features
LED Type: SK6812
Number of LEDs: 144
Color Order: GRB
Brightness: 96
Frame Rate: 120 FPS
Alternating Red and Blue Colors: The LED strip displays a sequence of red and blue colors, with each color occupying five consecutive LEDs.
Getting Started

#Prerequisites
Arduino IDE installed on your computer.
FastLED library installed in the Arduino IDE. You can install it via the Arduino Library Manager.

#Customisation
Change Colors: Modify the CRGB values in the loop() function to change the colors displayed by the LEDs.
Adjust LED Blocks: Change the CONSEC_LED value to adjust the number of consecutive LEDs that share the same color.
Brightness and Frame Rate: Modify BRIGHTNESS and FRAMES_PER_SECOND to suit your needs.

# LED Light Patterns with FastLED

This project utilizes the [FastLED](http://fastled.io/) library to create dynamic light patterns on an LED strip. The code implements two different patterns: a rainbow effect and an alternating red and blue pattern with a customizable delay. The LED strip is made up of SK6812 LEDs and is controlled by an Arduino or a similar microcontroller.

# Features
- **LED Type:** SK6812
- **Number of LEDs:** 144
- **Color Order:** GRB
- **Brightness:** 96
- **Frame Rate:** 120 FPS
- **Alternating Red and Blue Colors:** The LED strip displays a sequence of red and blue colors, with each color occupying five consecutive LEDs.

## Prerequisites
- Arduino IDE installed on your computer.
- FastLED library installed in the Arduino IDE. You can install it via the Arduino Library Manager.

# Customization
- **Change Colors:** Modify the `CRGB` values in the `loop()` function to change the colors displayed by the LEDs.
- **Adjust LED Blocks:** Change the `CONSEC_LED` value to adjust the number of consecutive LEDs that share the same color.
- **Brightness and Frame Rate:** Modify `BRIGHTNESS` and `FRAMES_PER_SECOND` to suit your needs.

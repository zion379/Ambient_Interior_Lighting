#include <Arduino.h>
#include <FastLED.h>

const int NUM_LEDS = 24;
const int DATA_PIN_Front_L = 3;
const int DATA_PIN_Front_R = 5;
const int DATA_PIN_Rear_L = 6;
const int DATA_PIN_Rear_R = 9;

CRGB leds_front_left[NUM_LEDS];
CRGB leds_front_right[NUM_LEDS];
CRGB leds_rear_left[NUM_LEDS];
CRGB leds_rear_right[NUM_LEDS];

int pattern_delay = 70; // Miliseconds

void setup() {
  FastLED.addLeds<WS2812, DATA_PIN_Front_L>(leds_front_left, NUM_LEDS);
  FastLED.addLeds<WS2812, DATA_PIN_Front_R>(leds_front_right, NUM_LEDS);

}

void fade_in_animation() {
  for (int i = 0; i < NUM_LEDS; i++ ) {
    leds_front_left[i] = CRGB::Green;
    leds_front_right[i] = CRGB::Green;
    leds_rear_left[i] = CRGB::Green;
    leds_rear_right[i] = CRGB::Green;
    FastLED.show();
    delay(pattern_delay);
  }
}

void inverted_fade_in_animation() {
  for (int i = NUM_LEDS - 1; i >= 0; i-- ) {
    leds_front_left[i] = CRGB::Green;
    leds_front_right[i] = CRGB::Green;
    leds_rear_left[i] = CRGB::Green;
    leds_rear_right[i] = CRGB::Green;
    FastLED.show();
    delay(pattern_delay);
  }
}

void fade_out_animation() {
  for( int i = NUM_LEDS - 1; i >= 0; i--) {
    leds_front_left[i] = CRGB::Black;
    leds_front_right[i] = CRGB::Black;
    leds_rear_left[i] = CRGB::Black;
    leds_rear_right[i] = CRGB::Black;
    FastLED.show();
    delay(pattern_delay);
  }
}

void inverted_fade_out_animation() {
  for( int i = 0; i < NUM_LEDS; i++) {
    leds_front_left[i] = CRGB::Black;
    leds_front_right[i] = CRGB::Black;
    leds_rear_left[i] = CRGB::Black;
    leds_rear_right[i] = CRGB::Black;
    FastLED.show();
    delay(pattern_delay);
  }
}
// Fade in from center
void fade_in_from_center() {
  // determine if sum of LEDs is EVEN or ODD
  if (NUM_LEDS % 2 == 0) {
    int array_mid_point[2];
    array_mid_point[0] = (NUM_LEDS / 2) - 1;
    array_mid_point[1] = NUM_LEDS / 2;
    for(int i = 0; i < (NUM_LEDS / 2); i += 1) {
      leds_front_left[array_mid_point[0] -i] = CRGB::Green;
      leds_front_left[array_mid_point[1] +i] = CRGB::Green;
      leds_front_right[array_mid_point[0] -i] = CRGB::Green;
      leds_front_right[array_mid_point[1] +i] = CRGB::Green;
      FastLED.show();
      delay(pattern_delay);
    }
  }
  else {
    int array_mid_point = ((NUM_LEDS - 1) / 2) + 1;
    for (int i = 0; i < (array_mid_point) - 1; i++) {
      leds_front_left[array_mid_point -i] = CRGB::Green;
      leds_front_left[array_mid_point +i] = CRGB::Green;
      leds_front_right[array_mid_point -i] = CRGB::Green;
      leds_front_right[array_mid_point +i] = CRGB::Green;
      FastLED.show();
      delay(pattern_delay);
    }
  }
}

void invert_fade_in_from_center() {
  for(int i = 0; i <= (NUM_LEDS / 2); i++) {
    leds_front_left[i] = CRGB::Green;
    leds_front_left[NUM_LEDS - i] = CRGB::Green;
    leds_front_right[i] = CRGB::Green;
    leds_front_right[NUM_LEDS - i] = CRGB::Green;
    FastLED.show();
    delay(pattern_delay);
  }
  // create functionality for odd array of leds
}

void clear_fade_in_from_center() {
  for(int i = 0; i <= (NUM_LEDS / 2); i++) {
    leds_front_left[i] = CRGB::Black;
    leds_front_left[NUM_LEDS - i] = CRGB::Black;
    leds_front_right[i] = CRGB::Black;
    leds_front_right[NUM_LEDS - i] = CRGB::Black;
    FastLED.show();
    delay(pattern_delay);
  }
}

void clear_invert_fade_in_from_center() {
  int array_mid_point[2];
    array_mid_point[0] = (NUM_LEDS / 2) - 1;
    array_mid_point[1] = NUM_LEDS / 2;
  for(int i = 0; i < (NUM_LEDS / 2); i++) {
    leds_front_left[array_mid_point[0] - i] = CRGB::Black;
    leds_front_left[array_mid_point[1] + i] = CRGB::Black;
    leds_front_right[array_mid_point[0] - i] = CRGB::Black;
    leds_front_right[array_mid_point[1] + i] = CRGB::Black;
    FastLED.show();
    delay(pattern_delay);
  }
}

// void scroll_animation() {
//   // 2/3 ratio
//   int block1 = 2;
//   int block2 = 3;

//   for(int i = 0; i < 24; i++) {

//   }
// }

void loop() {
  // put your main code here, to run repeatedly:
  // Turn the LED on, then pause
  // leds[23] = CRGB::Red;
  // FastLED.show();
  // delay(500);
  // // Now turn the LED off, then pause
  // leds[23] = CRGB::Black;
  // FastLED.show();
  // delay(500);
  fade_in_from_center();
  delay(50);
  clear_invert_fade_in_from_center();
  delay(50);
  invert_fade_in_from_center();
  delay(50);
  clear_fade_in_from_center();
  // FastLED.clear();
  delay(50);
  fade_in_animation();
  delay(50);
  fade_out_animation();
  delay(50);
  // FastLED.clear();
  inverted_fade_in_animation();
  delay(50);
  inverted_fade_out_animation();
  delay(50);
}




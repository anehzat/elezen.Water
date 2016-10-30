// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library
#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN            9

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      16

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 500; // delay for half a second

// these constants won't change. They are the
// lowest and highest readings you get from your sensor:
const int sensorMin = 0;      // sensor minimum, discovered through experiment
const int sensorMax = 135;    // sensor maximum, discovered through experiment


// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600); 
  // This initializes the NeoPixel library.
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A5);
  // print out the value you read:
  Serial.println(sensorValue);

  // map the sensor range to a range of four options:
  int range = map(sensorValue, sensorMin, sensorMax, 0, 6);
  // do something different depending on the
  // range value:
  switch (range) {
    case 0:    // your hand is on the sensor
      Serial.println("8");
      colorWipe(strip.Color(0, 200, 0), 50); // Green
      break;
    case 1:    // your hand is close to the sensor
      Serial.println("7");
      colorWipe(strip.Color(100, 200, 0), 50); // 
      break;
    case 2:    // your hand is a few inches from the sensor
      Serial.println("6");
      colorWipe(strip.Color(150, 200, 0), 50); // 
      break;
    case 3:    // your hand is a few inches from the sensor
      Serial.println("5");
      colorWipe(strip.Color(200, 200, 0), 50); // Yellow 
      break;
    case 4:    // your hand is a few inches from the sensor
      Serial.println("4");
      colorWipe(strip.Color(200, 150, 0), 50); // 
      break;
    case 5:    // your hand is a few inches from the sensor
      Serial.println("3");
      colorWipe(strip.Color(200, 100, 0), 50); // 
      break;
    case 6:    // your hand is a few inches from the sensor
      Serial.println("1");
      colorWipe(strip.Color(200, 0, 0), 50); // Red
      break;
  }

  // delay in between reads for stability
  delay(100);  
}



// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}


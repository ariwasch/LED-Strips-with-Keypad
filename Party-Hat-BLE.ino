#define FASTLED_INTERNAL
#include <FastLED.h> 
//#include <Keypad.h> 
#define NUM_LEDS 120 //number of LEDs
# define NUM_WHITE 3
# define LED_PIN 6

//initialized variables
int brightNum = 256;
int r = 0;
int g = 0;
int b = 0;
int amount = 5;
int delayNum = 5;
int amountDelay = 1;
boolean delaytf = true;
char key;
int lastDelay = delayNum;
const byte rows = 4; //four rows
const byte cols = 4; //three columns
boolean isHashtagHold = false;
boolean isStarHold = false;
CRGB leds[NUM_LEDS];
boolean wtf = false;
char mode;
unsigned long previousMillis = 0;
const long interval = 50;
char function = '1';
CRGB color = CRGB::Blue;
char keys[rows][cols] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

//sets up everything 
void setup() {
  FastLED.addLeds < WS2812, LED_PIN, GRB > (leds, NUM_LEDS);
  Serial.begin(9600);
  mode = 'A';
  Serial.println("hi");
}
//constant running code
void loop() {
  delayThing();
  colorChange();
  brightness();
  keypadEvent();
//  Serial.println(function);
  leds[0] = CRGB::Black;
  leds[1] = CRGB::Black;
  leds[2] = CRGB::Black;
  leds[3] = CRGB::Black;
  leds[4] = CRGB::Black;
  if (function == '1') {
    function1(); //does nothing
  } else if (function == '2') {
    function2(); //white dashing line across standard colors
  } else if (function == '3') {
    function3(); //party function 
  } else if (function == '4') {
    function4(); //Snake
  } else if (function == '5') {
    function5(); //festival lights
  } else if (function == '6') {
    //function6(); 
    meteorRain(10, 64, true); // meteor rain from https://www.tweaking4all.com/hardware/arduino/adruino-led-strip-effects/
  } else if (function == '7') {
    function7(); //random sparkles with input color
  } else if (function == '8') {
    function8(); // rainbow changing colors from https://www.tweaking4all.com/hardware/arduino/adruino-led-strip-effects/
  } else if (function == '9') {
    function9(); // rainbow changing colors with sparkles
  }
}
void function1() {
//  amount = 1;
  for (int i = 4; i < NUM_LEDS; i++) {
    leds[i] = color;
  }
  FastLED.show();
  if (mode == '1') {

  }
}
void function2() {
  if (function == '2') {
    for (int j = 49; j < NUM_LEDS - 2; j++) {

      //a++;
      leds[j] = CRGB(255, 255, 255);
      leds[0] = CRGB::Black;
      leds[1] = CRGB::Black;
      leds[2] = CRGB::Black;
      leds[3] = CRGB::Black;
      leds[4] = CRGB::Black;
      FastLED.show();
      leds[NUM_LEDS - j] = CRGB(255, 255, 255);
      leds[0] = CRGB::Black;
      leds[1] = CRGB::Black;
      leds[2] = CRGB::Black;
      leds[3] = CRGB::Black;
      leds[4] = CRGB::Black;
      FastLED.show();
      leds[j + 1] = CRGB(255, 255, 255);
      leds[0] = CRGB::Black;
      leds[1] = CRGB::Black;
      leds[2] = CRGB::Black;
      leds[3] = CRGB::Black;
      leds[4] = CRGB::Black;
      FastLED.show();
      leds[NUM_LEDS - j - 1] = CRGB(255, 255, 255);
      leds[0] = CRGB::Black;
      leds[1] = CRGB::Black;
      leds[2] = CRGB::Black;
      leds[3] = CRGB::Black;
      leds[4] = CRGB::Black;
      FastLED.show();
      leds[j + 2] = CRGB(255, 255, 255);
      leds[0] = CRGB::Black;
      leds[1] = CRGB::Black;
      leds[2] = CRGB::Black;
      leds[3] = CRGB::Black;
      leds[4] = CRGB::Black;
      FastLED.show();
      leds[NUM_LEDS - j - 2] = CRGB(255, 255, 255);
      leds[0] = CRGB::Black;
      leds[1] = CRGB::Black;
      leds[2] = CRGB::Black;
      leds[3] = CRGB::Black;
      leds[4] = CRGB::Black;
      FastLED.show();

      //FastLED.show();
      leds[j] = color;
      leds[NUM_LEDS - j] = color;
      leds[0] = CRGB::Black;
      leds[1] = CRGB::Black;
      leds[2] = CRGB::Black;
      leds[3] = CRGB::Black;
      leds[4] = CRGB::Black;
      Serial.println(j);
      Serial.println(j);
      myDelay(delayNum);

      Serial.println("wtf");
      //Serial.print("HELLO");
      //FastLED.show();
    }
    for (int i = 4; i < NUM_LEDS; i++) {
      leds[i] = color;
    }
    FastLED.show();
  }
}

void function3() {
  for (int i = 4; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Blue;
    FastLED.show();
  }
  myDelay(delayNum);
  for (int i = 4; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Purple;
    FastLED.show();
  }
  myDelay(delayNum);
  for (int i = 4; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Red;
    FastLED.show();
  }
  myDelay(delayNum);
  for (int i = 4; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Yellow;
    FastLED.show();
  }
  myDelay(delayNum);
  for (int i = 4; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Green;
    FastLED.show();
  }
  myDelay(delayNum);

}

void function4() {
  if (function != '4') goto stupid;
  for (int i = 4; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
    FastLED.show();
    delay4(delayNum, '4');
//    Serial.println(function);
  }
  if (function != '4') goto stupid;
  for (int i = 4; i < NUM_LEDS; i++) {
    leds[i] = color;
    FastLED.show();
    delay4(delayNum, '4');
  }
  stupid: String stupid = "Bennett";
}
void delay4(int time, char fun) {
  unsigned long t = millis();
  t = 0;
  while (t < time) {
    check();
    delayThing();
    colorChange();
    brightness();
    if (function != '4') {
      goto nothing;
    }
    t++;
  }
//  Serial.println(t);
  nothing: String no = "no";
}
void function5() {
  int Position = 0;
  for (int i = 0; i < 6; i++) {
    Position++; // = 0; //Position + Rate;
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB(((sin(i + Position) * 127 + 128) / 255) * r,
        ((sin(i + Position) * 127 + 128) / 255) * g,
        ((sin(i + Position) * 127 + 128) / 255) * b);
    }

    FastLED.show();
    myDelay(delayNum);
  }
}
// from https://www.tweaking4all.com/hardware/arduino/adruino-led-strip-effects/
void meteorRain(byte meteorSize, byte meteorTrailDecay, boolean meteorRandomDecay) {
  FastLED.clear();
  for (int i = 4; i < NUM_LEDS; i++) {

    if (function != '6') goto hello;
    // fade brightness all LEDs one step
    for (int j = 0; j < NUM_LEDS; j++) {
      if ((!meteorRandomDecay) || (random(10) > 5)) {
        fadeToBlack(j, meteorTrailDecay);
      }
    }
    if (function != '6') goto hello;
    // draw meteor
    for (int j = 0; j < meteorSize; j++) {
      if ((i - j < NUM_LEDS) && (i - j >= 0)) {
        leds[i] = CRGB(r, g, b);
      }
    }

    FastLED.show();
    myDelay(delayNum);
    hello: String hello = "hi";
  }
}

void fadeToBlack(int ledNo, byte fadeValue) {
  #ifdef ADAFRUIT_NEOPIXEL_H
  // NeoPixel
  uint32_t oldColor;
  uint8_t red, green, blue;
  int value;

  oldColor = strip.getPixelColor(ledNo);
  red = (oldColor & 0x00ff0000 UL) >> 16;
  green = (oldColor & 0x0000ff00 UL) >> 8;
  blue = (oldColor & 0x000000ff UL);

  red = (r <= 10) ? 0 : (int) red - (red * fadeValue / 256);
  green = (g <= 10) ? 0 : (int) green - (green * fadeValue / 256);
  blue = (b <= 10) ? 0 : (int) blue - (blue * fadeValue / 256);

  strip.setPixelColor(ledNo, red, green, blue);
  #endif
  #ifndef ADAFRUIT_NEOPIXEL_H
  // FastLED
  leds[ledNo].fadeToBlackBy(fadeValue);
  #endif
}
void function7() {
  for (int i = 4; i < NUM_LEDS; i++) {
    leds[i] = CRGB(random(0, r), random(0, g), random(0, b));
  }
  FastLED.show();
  myDelay(delayNum);
}
void function8() {
  if (function != '8') goto lol;
  for (int colorStep = 0; colorStep < 256; colorStep++) {
    int r = 255 - colorStep; // Redness starts at zero and goes up to full
    int g = colorStep; // Blue starts at full and goes down to zero
    int b = 0; // No green needed to go from blue to red
    if (function != '8') goto lol;
    for (int x = 0; x < NUM_LEDS; x++) {
      leds[x] = CRGB(r, g, b);
    }
    FastLED.show();
    myDelay(delayNum);
  }
  if (function != '8') goto lol;
  for (int colorStep = 0; colorStep < 256; colorStep++) {
    int r = 0; // Redness starts at zero and goes up to full
    int g = 255 - colorStep; // Blue starts at full and goes down to zero
    int b = colorStep; // No green needed to go from blue to red
    if (function != '8') goto lol;
    for (int x = 0; x < NUM_LEDS; x++) {
      leds[x] = CRGB(r, g, b);
    }
    FastLED.show();
    myDelay(delayNum);
  }
  if (function != '8') goto lol;
  for (int colorStep = 0; colorStep < 256; colorStep++) {
    int r = colorStep; // Redness starts at zero and goes up to full
    int g = 0; // Blue starts at full and goes down to zero
    int b = 255 - colorStep; // No green needed to go from blue to red
    if (function != '8') goto lol;
    for (int x = 0; x < NUM_LEDS; x++) {
      leds[x] = CRGB(r, g, b);
    }
    FastLED.show();
    myDelay(delayNum);
  }
  lol: String lol = "lol";
}

// from https://www.tweaking4all.com/hardware/arduino/adruino-led-strip-effects/
void function9() {
  if (function != '9') goto lol;
  for (int colorStep = 0; colorStep < 256; colorStep++) {
    int r = 255 - colorStep; // Redness starts at zero and goes up to full
    int g = colorStep; // Blue starts at full and goes down to zero
    int b = 0; // No green needed to go from blue to red
    if (function != '9') goto lol;
    for (int x = 0; x < NUM_LEDS; x++) {
      leds[random(0, NUM_LEDS)] = CRGB(r, g, b);
      leds[random(0, NUM_LEDS)] = CRGB::Black;
    }
    FastLED.show();
    myDelay(delayNum);
  }
  if (function != '9') goto lol;
  for (int colorStep = 0; colorStep < 256; colorStep++) {
    int r = 0; // Redness starts at zero and goes up to full
    int g = 255 - colorStep; // Blue starts at full and goes down to zero
    int b = colorStep; // No green needed to go from blue to red
    if (function != '9') goto lol;
    for (int x = 0; x < NUM_LEDS; x++) {
      leds[random(0, NUM_LEDS)] = CRGB(r, g, b);
      leds[random(0, NUM_LEDS)] = CRGB::Black;
    }
    FastLED.show();
    myDelay(delayNum);
  }
  if (function != '9') goto lol;
  for (int colorStep = 0; colorStep < 256; colorStep++) {
    int r = colorStep; // Redness starts at zero and goes up to full
    int g = 0; // Blue starts at full and goes down to zero
    int b = 255 - colorStep; // No green needed to go from blue to red
    if (function != '9') goto lol;
    for (int x = 0; x < NUM_LEDS; x++) {
      leds[random(0, NUM_LEDS)] = CRGB(r, g, b);
      leds[random(0, NUM_LEDS)] = CRGB::Black;
    }
    FastLED.show();
    myDelay(delayNum);
  }
  lol: String lol = "lol";
}
void check() {
//  Serial.println(key2.getKey());
//  if (key2.getKey() == '1') {
//    function = key2.getKey();
//    Serial.println(key2.getKey());
//  }
}
void myDelay(int time) {
  unsigned long t = millis();
  t = 0;
  while (t < time) {
    check();
    delayThing();
    colorChange();
    brightness();
    if (function == '1') {
      goto nothing;
    }
    t++;
  }
//  Serial.println(t);
  nothing: String no = "no";
}

//switches patterns and colors
void keypadEvent() {
 char incomingByte = 'h';
 String message = "";
    while(Serial.available() > 0)
    {
//      Serial.println("AISODJOSAIJDIOASJDJASIODJIOSA");
//      delay(3);
      if(incomingByte != ""){
        incomingByte = Serial.read();      
        message += incomingByte;
      }
//      Serial.println(incomingByte);
    }
//      Serial.println("ASDJSJDAJSDJSAD");


      if(message != ""){
         Serial.println(message);
//          Serial.println(message.indexOf("A"));

//        readString = message;
        if(message.indexOf("#") != 0 && (message.indexOf("*") != 0)){
        if((message.indexOf("A") != 0) && (message.indexOf("B") != 0) && (message.indexOf("C") != 0) && (message.indexOf("D") != 0) && (message.indexOf("0") != 0)){
          function = message[0];
          Serial.println("FUNCTION");
          Serial.println(function);
        }else{
          mode = message[0];
          Serial.println("MODE");
        }
        }
        if(message.indexOf("#") >= 0){
          isHashtagHold = !isHashtagHold;
          isStarHold = false;

        }else if(message.indexOf("*") >= 0){
           isStarHold = !isStarHold;
           isHashtagHold = false;

        }else{
          isHashtagHold = false;
          isStarHold = false;

        }
//      mySerial.println(y2);
      message = "";
      }else{
          isHashtagHold = false;
          isStarHold = false;
      }

    delaytf = !delaytf;
//    if (key == '*') {
//      isStarHold = !isStarHold;
//      Serial.println("HELLO");
//    } else if (key == '#') {
//      isHashtagHold = !isHashtagHold;
//    }
  

}
void delayThing() {
  if (mode == 'A') {
    if (isHashtagHold && delayNum <= 69) {
      delayNum += amountDelay;
      if (amountDelay > 69) {
        delayNum = 69;
      }
    } else if (isStarHold && delayNum > 1) {
      delayNum -= amountDelay;
      if (amountDelay < 1) {
        delayNum = 1;
      }
    }
  }
}
//changes colors based off of keypad
int colorChange() {
  if (mode == 'B') {
    r = increase(r);
    r = decrease(r);
    Serial.print("r ");
    Serial.print(r);
    Serial.println();
  } else if (mode == 'C') {
    g = increase(g);
    g = decrease(g);
    Serial.print("g ");
    Serial.print(g);
    Serial.println();
  } else if (mode == 'D') {
    b = increase(b);
    b = decrease(b);
    Serial.print("b ");
    Serial.print(b);
    Serial.println();
  }
  color = CRGB(r, g, b);
}
int increase(int num) {
  if (isHashtagHold && num <= 255 && num >= 0) {
    num += amount;

    if (num > 255) {
      num = 255;
    }
    //delay(20);
  }
  return num;
}
int decrease(int num) {
  if (isStarHold && num <= 255 && num >= 0) {
    num -= amount;
    if (num < 0) {
      num = 0;
    }
    //delay(20);
  }
  return num;
}
void brightness() {
  if (mode == '0') {
    brightNum = increase(brightNum);
    brightNum = decrease(brightNum);
    FastLED.setBrightness(brightNum);
  }
}

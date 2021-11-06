
#define FASTLED_INTERNAL
#include <FastLED.h> 

#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>


//#include <Keypad.h> 
#define NUM_LEDS 33 //number of LEDs
# define NUM_WHITE 3
# define LED_PIN 26

//initialized variables
int brightNum = 255;
int r = 148;
int g = 0;
int b = 211;
int amount = 5;
int delayNum = 165;
int amountDelay = 10;
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
String phoneMessage = "";
int buttonIncrement = 0;
char keys[rows][cols] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};


#define PERIPHERAL_NAME             "UWRT LEDs"
#define SERVICE_UUID                "FFE0"
#define CHARACTERISTIC_INPUT_UUID   "FFE1"
#define CHARACTERISTIC_OUTPUT_UUID  "FFE2"

// Current value of output characteristic persisted here
static uint8_t outputData[1];

// Output characteristic is used to send the response back to the connected phone
BLECharacteristic *pOutputChar;

// Class defines methods called when a device connects and disconnects from the service
class ServerCallbacks: public BLEServerCallbacks {
    void onConnect(BLEServer* pServer) {
        Serial.println("BLE Client Connected");
    }
    void onDisconnect(BLEServer* pServer) {
        BLEDevice::startAdvertising();
        Serial.println("BLE Client Disconnected");
    }
    
};

class InputReceivedCallbacks: public BLECharacteristicCallbacks {
    void onWrite(BLECharacteristic *pCharWriteState) {
        Serial.println("LOLLL");
        uint8_t *inputValues = pCharWriteState->getData();
//        Serial.println(String((char)pCharWriteState->getData());
//        String result = "";
//        for(int i = 0; i < 10; i++){
//          result += String((char)inputValues[i]);
//        }
//        Serial.println(result);
        phoneMessage = String((char)inputValues[0]);
//        Serial.println(phoneMessage);

        
//        Serial.printf("Sending response:   %02x\r\n", outputData[0]);  
        
//        pOutputChar->setValue((uint8_t *)outputData, 1);
//        pOutputChar->notify();
    }
};

void setup() {
  // Use the Arduino serial monitor set to this baud rate to view BLE peripheral logs 
  FastLED.addLeds < WS2812, LED_PIN, GRB > (leds, NUM_LEDS);
  mode = 'A';
  Serial.println("hi");

  Serial.begin(115200);
  Serial.println("Begin Setup BLE Service and Characteristics");

  // Configure thes server

  BLEDevice::init(PERIPHERAL_NAME);
  BLEServer *pServer = BLEDevice::createServer();

  // Create the service
  BLEService *pService = pServer->createService(SERVICE_UUID);

  // Create a characteristic for the service
  BLECharacteristic *pInputChar = pService->createCharacteristic(
                              CHARACTERISTIC_INPUT_UUID,                                        
                              BLECharacteristic::PROPERTY_WRITE_NR | BLECharacteristic::PROPERTY_WRITE);

  pOutputChar = pService->createCharacteristic(
                              CHARACTERISTIC_OUTPUT_UUID,
                              BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY);

                                       

  // Hook callback to report server events
  pServer->setCallbacks(new ServerCallbacks());
  pInputChar->setCallbacks(new InputReceivedCallbacks());

  // Initial characteristic value
  outputData[0] = 0x00;
  pOutputChar->setValue((uint8_t *)outputData, 1);

  // Start the service
  pService->start();

  // Advertise the service
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(true);
//  pAdvertising->setMinPreferred(0x06);  
//  pAdvertising->setMinPreferred(0x12);
  BLEDevice::startAdvertising();

  Serial.println("BLE Service is advertising");
}


//constant running code
void loop() {
  delayThing();
  colorChange();
  brightness();
  keypadEvent();
//  Serial.println(function);
  if (function == '1') {
    function1(); //does nothing
  } else if (function == '2') {
    function2(); //white dashing line across standard colors
  } else if (function == '3') {
    function3(); //party function 
  } else if (function == '4') {
//    function4(); //Snake
    function4();

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
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = color;
  }
  FastLED.show();
  if (mode == '1') {

  }
}
void function2() {
  if (function == '2') {
    for (int j = 0; j < NUM_LEDS - 2; j++) {

      //a++;
      leds[j] = CRGB(255, 255, 255);
      FastLED.show();
      leds[NUM_LEDS - j] = CRGB(255, 255, 255);
      FastLED.show();
      leds[j + 1] = CRGB(255, 255, 255);
      FastLED.show();
      leds[NUM_LEDS - j - 1] = CRGB(255, 255, 255);
      FastLED.show();
      leds[j + 2] = CRGB(255, 255, 255);
      FastLED.show();
      leds[NUM_LEDS - j - 2] = CRGB(255, 255, 255);
      FastLED.show();
      leds[j] = color;
      leds[NUM_LEDS - j] = color;
      Serial.println(j);
      Serial.println(j);
      myDelay(170);

      Serial.println("wtf");
      //Serial.print("HELLO");
      //FastLED.show();
    }
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = color;
    }
    FastLED.show();
  }
}

void function3() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Blue;
    FastLED.show();
    myDelay(50);

  }
  myDelay(2000);
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Purple;
    FastLED.show();
    myDelay(50);

  }
  myDelay(2000);
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Red;
    FastLED.show();
    myDelay(50);
  }
  myDelay(2000);
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Yellow;
    FastLED.show();
    myDelay(50);
  }
  myDelay(2000);
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Green;
    FastLED.show();
    myDelay(50);
  }
  myDelay(2000);

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
    myDelay(135);
  }
}

// from https://www.tweaking4all.com/hardware/arduino/adruino-led-strip-effects/
void meteorRain(byte meteorSize, byte meteorTrailDecay, boolean meteorRandomDecay) {
  FastLED.clear();
  for (int i = 0; i < NUM_LEDS; i++) {

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

  red = (r <= 10) ? 0 : (int) red - (red * fadeValue / i = 0);
  green = (g <= 10) ? 0 : (int) green - (green * fadeValue / i = 0);
  blue = (b <= 10) ? 0 : (int) blue - (blue * fadeValue / i = 0);

  strip.setPixelColor(ledNo, red, green, blue);
  #endif
  #ifndef ADAFRUIT_NEOPIXEL_H
  // FastLED
  leds[ledNo].fadeToBlackBy(fadeValue);
  #endif
}


//https://github.com/FastLED/FastLED/blob/master/examples/Fire2012WithPalette/Fire2012WithPalette.ino
void function4()
{
    int cooling = 55;
    int sparking = 120;
    bool gReverseDirection = false;

    CRGBPalette16 gPal = CRGBPalette16( CRGB::Black, CRGB::Purple, CRGB::Blue,  CRGB::White);
  
  // Third, here's a simpler, three-step gradient, from black to red to white
  //   gPal = CRGBPalette16( CRGB::Black, CRGB::Red, CRGB::White);

// Array of temperature readings at each simulation cell
  static uint8_t heat[NUM_LEDS];

  // Step 1.  Cool down every cell a little
    for( int i = 0; i < NUM_LEDS; i++) {
      heat[i] = qsub8( heat[i],  random8(0, ((cooling * 10) / NUM_LEDS) + 2));
    }
  
    // Step 2.  Heat from each cell drifts 'up' and diffuses a little
    for( int k= NUM_LEDS - 1; k >= 2; k--) {
      heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
    }
    
    // Step 3.  Randomly ignite new 'sparks' of heat near the bottom
    if( random8() < sparking ) {
      int y = random8(7);
      heat[y] = qadd8( heat[y], random8(160,255) );
    }

    // Step 4.  Map from heat cells to LED colors
    for( int j = 0; j < NUM_LEDS; j++) {
      // Scale the heat value from 0-255 down to 0-240
      // for best results with color palettes.
      uint8_t colorindex = scale8( heat[j], 240);
      CRGB color = ColorFromPalette( gPal, colorindex);
      int pixelnumber;
      if( gReverseDirection ) {
        pixelnumber = (NUM_LEDS-1) - j;
      } else {
        pixelnumber = j;
      }
      leds[pixelnumber] = color;
    }
    FastLED.show();
    myDelay(125);
}


void function7() {
  for (int i = 0; i < NUM_LEDS; i++) {
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
//  char incomingByte = 'h';
 String message = phoneMessage;
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
      phoneMessage = "";

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

  bool stopReadingButton5 = true;
  if(digitalRead(5) == HIGH && stopReadingButton5){
    stopReadingButton5 = false;
    buttonIncrement++;
    function = '1';
    if(buttonIncrement % 5 == 0){
      r = 0;
      g = 0;
      b = 255;
    }else if(buttonIncrement % 5 == 1){
      r = 255;
      g = 0;
      b = 0;
    }else if(buttonIncrement % 5 == 2){
      r = 0;
      g = 255;
      b = 0;
    }else if(buttonIncrement % 5 == 3){
      r = 255;
      g = 255;
      b = 0;
    }else if(buttonIncrement % 5 == 4){
      r = 87;
      g = 5;
      b = 139;
    }
    if(digitalRead(5) == LOW){
      stopReadingButton5 = true;
    }
    
  }
  if(digitalRead(16) == HIGH){
    function = '4';
  }
  if(digitalRead(17) == HIGH){
    function = '2';
  }

}
void delayThing() {
  if (mode == 'A') {
    Serial.println(delayNum);
    if (isHashtagHold && delayNum <= 255) {
      delayNum += amountDelay;
      if (delayNum > 255) {
        delayNum = 255;
      }
    } else if (isStarHold && delayNum > 1) {
      delayNum -= amountDelay;
      if (delayNum < 1) {
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

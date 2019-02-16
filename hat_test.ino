//#include "avdweb_VirtualDelay.h"
 
//VirtualDelay delay1;

# define FASTLED_INTERNAL
# include <FastLED.h>
# include <Keypad.h>
# define NUM_LEDS  98
#define NUM_WHITE   3
//130 for white hat
//115 for black hat
# define LED_PIN 10     
int brightNum = 256;
int r = 0;
int g = 0;
int b = 0;
int amount = 1;
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
  {'1','2','3', 'A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};
byte rowPins[rows] = {2, 3, 4, 5}; //connect to the row pinouts of the keypad
byte colPins[cols] = {6, 7, 8, 9}; //connect to the column pinouts of the keypad
Keypad key2 = Keypad( makeKeymap(keys), rowPins, colPins, rows, cols );
void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  // put your setup code here, to run once:
  Serial.begin(9600);
  mode = 'A';
  key2.addEventListener(keypadEvent);
}

void loop() {                                             
//time = millis();
Serial.println(delayNum);
delayThing();
colorChange();
brightness();
  // put your main code here, to run repeatedly:
  key = key2.getKey();
  Serial.println(function);
  leds[0] = CRGB::Black;
  leds[1] = CRGB::Black;
  leds[2] = CRGB::Black;
  leds[3] = CRGB::Black;
  leds[4] = CRGB::Black;  
    if(function == '1'){
     function1();
    }else if(function == '2'){
     function2();
    }else if(function == '3'){
     function3();
    }else if(function == '4'){
     function4();
    }else if(function == '5'){
      Serial.println("WRF");
     function5();
    }else if(function == '6'){
      //function6();
      meteorRain(10, 64, true);
    }else if(function == '7'){
      function7();
    }else if(function == '8'){
      function8();
    }else if(function == '9'){
      function9();
    }
//  function1();
//  function2();
//  //function3();
//  function4();
  
  //Serial.println(r);
  //leds.fill_solid(color);
  //function1();
}
void function1(){
  amount = 1;
  //if(function == '1'){
    for(int i = 4; i < NUM_LEDS; i++){
    leds[i] = color;
  }
  FastLED.show();
  //}
  if(mode == '1'){
    
  }
}
void function2(){
  if(function == '2'){
   //int a = 49;
     for(int j = 49; j < NUM_LEDS - 2; j++){
      
  //a++;
  leds[j] = CRGB(255, 255, 255);
  leds[0] = CRGB::Black;
  leds[1] = CRGB::Black;
  leds[2] = CRGB::Black;
  leds[3] = CRGB::Black;
  leds[4] = CRGB::Black;
  FastLED.show();
  leds[NUM_LEDS-j] = CRGB(255, 255, 255);
  leds[0] = CRGB::Black;
  leds[1] = CRGB::Black;
  leds[2] = CRGB::Black;
  leds[3] = CRGB::Black;
  leds[4] = CRGB::Black;
  FastLED.show();
  leds[j+1] = CRGB(255, 255, 255);
  leds[0] = CRGB::Black;
  leds[1] = CRGB::Black;
  leds[2] = CRGB::Black;
  leds[3] = CRGB::Black;
  leds[4] = CRGB::Black;
  FastLED.show();
  leds[NUM_LEDS-j-1] = CRGB(255, 255, 255);
  leds[0] = CRGB::Black;
  leds[1] = CRGB::Black;
  leds[2] = CRGB::Black;
  leds[3] = CRGB::Black;
  leds[4] = CRGB::Black;
  FastLED.show();
  leds[j+2] = CRGB(255, 255, 255);
  leds[0] = CRGB::Black;
  leds[1] = CRGB::Black;
  leds[2] = CRGB::Black;
  leds[3] = CRGB::Black;
  leds[4] = CRGB::Black;
  FastLED.show();
  leds[NUM_LEDS-j-2] = CRGB(255, 255, 255);
  leds[0] = CRGB::Black;
  leds[1] = CRGB::Black;
  leds[2] = CRGB::Black;
  leds[3] = CRGB::Black;
  leds[4] = CRGB::Black;
  FastLED.show();
  
  //FastLED.show();
  leds[j] = color;
  leds[NUM_LEDS-j] = color;
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
  for(int i = 4; i < NUM_LEDS; i++){
    leds[i] = color;
  }
  FastLED.show();
  } 
  }
  
  void function3() {
    for(int i = 4; i < NUM_LEDS; i++){
      leds[i] = CRGB::Blue;
      FastLED.show();
    }
    myDelay(delayNum);
    for(int i = 4; i < NUM_LEDS; i++){
      leds[i] = CRGB::Purple;
      FastLED.show();
    }
    myDelay(delayNum);
    for(int i = 4; i < NUM_LEDS; i++){
      leds[i] = CRGB::Red;
      FastLED.show();
    }
    myDelay(delayNum);
    for(int i = 4; i < NUM_LEDS; i++){
      leds[i] = CRGB::Yellow;
      FastLED.show();
    }
    myDelay(delayNum);
    for(int i = 4; i < NUM_LEDS; i++){
      leds[i] = CRGB::Green;
      FastLED.show();
    }
    myDelay(delayNum);
    
  }
//  void setAll(int re,int gr, int bl){
//    for(int i = 4; i < NUM_LEDS; i++){
//      leds[i].setRGB( re, gr, bl);
//    }
//    FastLED.show();
//  }
  void function4(){
      if(function != '4') goto stupid;
      for(int i = 4; i < NUM_LEDS; i++){
        leds[i] = CRGB::Black;
        FastLED.show();
        delay4(delayNum, '4');
        Serial.println(function);
      }
      if(function != '4') goto stupid;
      for(int i = 4; i < NUM_LEDS; i++){
        leds[i] = color;
        FastLED.show();
        delay4(delayNum, '4');
      }
      stupid: String stupid = "Bennett";
  }
  void delay4(int time, char fun){
    unsigned long t = millis();
    t = 0;
    while(t < time){
    check();
    delayThing();
    colorChange();
    brightness();
    if(function != '4'){
      goto nothing;
    }
    t++;
  }
  Serial.println(t);
  nothing: String no = "no";
  }
  void function5() {
  int Position=0;
  Serial.println("DFHISDHGIOSDHIUFHIUGSEGHUIBDUIFG");
  for(int i=0; i<6; i++)
  {
      Position++; // = 0; //Position + Rate;
      for(int i=0; i<NUM_LEDS; i++) {
        // sine wave, 3 offset waves make a rainbow!
        //float level = sin(i+Position) * 127 + 128;
        //setPixel(i,level,0,0);
        //float level = sin(i+Position) * 127 + 128;
        leds[i] = CRGB(((sin(i+Position) * 127 + 128)/255)*r,
                   ((sin(i+Position) * 127 + 128)/255)*g,
                   ((sin(i+Position) * 127 + 128)/255)*b);
      }
      
      FastLED.show();
      myDelay(delayNum);
  }
}
void function6(){
    FastLED.clear();
//    for(int i = 4; i < NUM_LEDS; i++){
//      leds[i] = 
//    }
FastLED.show();
//
    leds[31] = CRGB(67, 92, 200);
    leds[33] = CRGB(67, 92, 200);
    leds[35] = CRGB(67, 92, 200);
    leds[37] = CRGB(67, 92, 200);
    leds[65] = CRGB(67, 92, 200);
    leds[67] = CRGB(67, 92, 200);
    leds[69] = CRGB(67, 92, 200);
    leds[71] = CRGB(67, 92, 200);
    leds[12] = CRGB(67, 92, 200);
    leds[14] = CRGB(67, 92, 200);
    leds[16] = CRGB(67, 92, 200);
    leds[18] = CRGB(67, 92, 200);
    leds[48] = CRGB(67, 92, 200);
    leds[50] = CRGB(67, 92, 200);
    leds[52] = CRGB(67, 92, 200);
    leds[54] = CRGB(67, 92, 200);
    FastLED.show();
  }
  void meteorRain(byte meteorSize, byte meteorTrailDecay, boolean meteorRandomDecay) {  
  FastLED.clear();
  for(int i = 4; i < NUM_LEDS; i++) {
    
    if(function != '6') goto hello;
    // fade brightness all LEDs one step
    for(int j=0; j<NUM_LEDS; j++) {
      if( (!meteorRandomDecay) || (random(10)>5) ) {
        fadeToBlack(j, meteorTrailDecay );        
      }
    }
    if(function != '6') goto hello;
    // draw meteor
    for(int j = 0; j < meteorSize; j++) {
      if( ( i-j <NUM_LEDS) && (i-j>=0) ) {
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
    red = (oldColor & 0x00ff0000UL) >> 16;
    green = (oldColor & 0x0000ff00UL) >> 8;
    blue = (oldColor & 0x000000ffUL);

    red=(r<=10)? 0 : (int) red-(red*fadeValue/256);
    green=(g<=10)? 0 : (int) green-(green*fadeValue/256);
    blue=(b<=10)? 0 : (int) blue-(blue*fadeValue/256);
    
    strip.setPixelColor(ledNo, red,green,blue);
 #endif
 #ifndef ADAFRUIT_NEOPIXEL_H
   // FastLED
   leds[ledNo].fadeToBlackBy( fadeValue );
 #endif  
}
void function7(){
  for(int i = 4; i < NUM_LEDS; i++){
    leds[i] = CRGB(random(0, r), random(0, g), random(0, b));
  }
  FastLED.show();
  myDelay(delayNum);
}
void function8(){
  if(function != '8') goto lol;
  for( int colorStep=0; colorStep<256; colorStep++ ) {
      int r = 255-colorStep;  // Redness starts at zero and goes up to full
      int g = colorStep;  // Blue starts at full and goes down to zero
      int b = 0;              // No green needed to go from blue to red
      if(function != '8') goto lol;
      for(int x = 0; x < NUM_LEDS; x++){
          leds[x] = CRGB(r,g,b);
      }
      FastLED.show();
      myDelay(delayNum); 
  }
  if(function != '8') goto lol;
  for( int colorStep=0; colorStep<256; colorStep++ ) {
      int r = 0;  // Redness starts at zero and goes up to full
      int g = 255-colorStep;  // Blue starts at full and goes down to zero
      int b = colorStep;              // No green needed to go from blue to red
      if(function != '8') goto lol;
      for(int x = 0; x < NUM_LEDS; x++){
          leds[x] = CRGB(r,g,b);
      }
      FastLED.show();
      myDelay(delayNum); 
  }
  if(function != '8') goto lol;
  for( int colorStep=0; colorStep<256; colorStep++ ) {
      int r = colorStep;  // Redness starts at zero and goes up to full
      int g = 0;  // Blue starts at full and goes down to zero
      int b = 255 - colorStep;              // No green needed to go from blue to red
      if(function != '8') goto lol;
      for(int x = 0; x < NUM_LEDS; x++){
          leds[x] = CRGB(r,g,b);
      }
      FastLED.show();
      myDelay(delayNum); 
  }
  lol: String lol = "lol";
}
void function9(){
  if(function != '9') goto lol;
  for( int colorStep=0; colorStep<256; colorStep++ ) {
      int r = 255-colorStep;  // Redness starts at zero and goes up to full
      int g = colorStep;  // Blue starts at full and goes down to zero
      int b = 0;              // No green needed to go from blue to red
      if(function != '9') goto lol;
      for(int x = 0; x < NUM_LEDS; x++){
          leds[random(0, NUM_LEDS)] = CRGB(r,g,b);
          leds[random(0, NUM_LEDS)] = CRGB::Black;
      }
      FastLED.show();
      myDelay(delayNum); 
  }
  if(function != '9') goto lol;
  for( int colorStep=0; colorStep<256; colorStep++ ) {
      int r = 0;  // Redness starts at zero and goes up to full
      int g = 255-colorStep;  // Blue starts at full and goes down to zero
      int b = colorStep;              // No green needed to go from blue to red
      if(function != '9') goto lol;
      for(int x = 0; x < NUM_LEDS; x++){
          leds[random(0, NUM_LEDS)] = CRGB(r,g,b);
          leds[random(0, NUM_LEDS)] = CRGB::Black;
      }
      FastLED.show();
      myDelay(delayNum); 
  }
  if(function != '9') goto lol;
  for( int colorStep=0; colorStep<256; colorStep++ ) {
      int r = colorStep;  // Redness starts at zero and goes up to full
      int g = 0;  // Blue starts at full and goes down to zero
      int b = 255 - colorStep;              // No green needed to go from blue to red
      if(function != '9') goto lol;
      for(int x = 0; x < NUM_LEDS; x++){
          leds[random(0, NUM_LEDS)] = CRGB(r,g,b);
          leds[random(0, NUM_LEDS)] = CRGB::Black;
      }
      FastLED.show();
      myDelay(delayNum); 
  }
  lol: String lol = "lol";
}
void check(){
  Serial.println(key2.getKey());
  if(key2.getKey() == '1'){
    function = key2.getKey();
    Serial.println(key2.getKey());
  }
}
void myDelay(int time){
  unsigned long t = millis();
  t = 0;
  while(t < time){
    check();
    delayThing();
    colorChange();
    brightness();
    if(function == '1'){
      goto nothing;
    }
    t++;
  }
  Serial.println(t);
  nothing: String no = "no";
}
//void delayer(){
//  if(delaytf){
//    delay(delayNum);
//    amount = 30;
//    //amountDelay = delayNum;
//  }
//}
void keypadEvent(KeypadEvent key){
    switch (key2.getState()){
    
    case PRESSED:
        delaytf = !delaytf;
        if(key == '1'){
          function = '1';
          
          //function1();
        }else if(key == '2'){
          function = '2';
        }else if(key == '3'){
          function = '3';
        }else if(key == '4'){
          function = '4';
        }else if(key == '5'){
          function = '5';
          Serial.println("WTFDFF");
        }else if(key == '6'){
          function = '6';
        }else if(key == '7'){
          function = '7';
        }else if(key == '8'){
          function = '8';
        }else if(key == '9'){
          function = '9';
        }
        if(key == 'A'){
          mode = 'A';
          Serial.println(mode);
          
        }
        else if(key == 'B'){
          mode = 'B';
          Serial.println(mode);
        }
        else if(key == 'C'){
          mode = 'C';
          Serial.println("sdlfkhdshfshdiof");
          Serial.println(mode);
        }
        else if(key == 'D'){
          mode = 'D';
          Serial.println(mode);
        }
        else if(key == '#'){
          isHashtagHold = !isHashtagHold;
        }
        else if(key == '*') {
            isStarHold = !isStarHold; 
            Serial.println("HELLO");   
        }else if(key == '0'){
          mode = '0';
        }
        break;

        case RELEASED:

        delaytf = !delaytf;
        if(key == '*') {
            isStarHold = !isStarHold; 
            Serial.println("HELLO"); 
        }else if(key == '#'){
          isHashtagHold = !isHashtagHold;
        }

//        case HOLD:
//        delaytf = !delaytf;
    }
    
  
}
void delayThing(){
  if(mode == 'A'){
    if(isHashtagHold && delayNum <= 69){
      delayNum += amountDelay;
      if(amountDelay > 69){
        delayNum = 69;
      }
    }else if(isStarHold && delayNum > 1){
      delayNum -= amountDelay;
      if(amountDelay < 1){
        delayNum = 1;
      }
    }
  }
}
int colorChange(){
  if(mode == 'B'){
    r = increase(r);
    r = decrease(r);
    Serial.print("r ");
    Serial.print(r);
    Serial.println();
  }else if(mode == 'C'){
    g = increase(g);
    g = decrease(g);
    Serial.print("g ");
    Serial.print(g);
    Serial.println();
  }else if(mode == 'D'){
    b = increase(b);
    b = decrease(b);
    Serial.print("b ");
    Serial.print(b);
    Serial.println();
  }
  color = CRGB( r, g, b);
}
int increase(int num){
  if(isHashtagHold && num <= 255 && num >= 0){
    num+= amount;

    if(num > 255){
      num = 255;
    }
    //delay(20);
  }
  return num;
}
int decrease(int num){
  if(isStarHold  && num <= 255 && num >= 0){
    num-= amount;
    if(num < 0){
      num = 0;
    }
    //delay(20);
  }
  return num;
}
void brightness(){
  if(mode == '0'){
   brightNum = increase(brightNum);
   brightNum = decrease(brightNum);
   FastLED.setBrightness(brightNum);
  }
}


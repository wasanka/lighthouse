/*
 Fading

 This example shows how to fade an LED using the analogWrite() function.

 The circuit:
 * LED attached from digital pin 9 to ground.

 Created 1 Nov 2008
 By David A. Mellis
 modified 30 Aug 2011
 By Tom Igoe

 http://www.arduino.cc/en/Tutorial/Fading

 This example code is in the public domain.

 */

int leds[] = {15, 2, 0, 4, 5, 13, 12, 14, 16, 10};
int ledCount = 10;

void setup() {
  // nothing happens in setup
  //setPwmFrequency(ledPin, 500);
  //pinMode(ledPin, OUTPUT);
  //analogWriteFreq(10000);
  //analogWriteRange(024);
  
  //analogWriteResolution(256);
}

void loop() {

  for(int i = 0; i < ledCount; i++){

    int tailLED3 = i - 3;
    int tailLED2 = i - 2;
    int tailLED1 = i - 1;

    if(tailLED1 < 0){
        tailLED1 += ledCount;
    }

    if(tailLED2 < 0){
        tailLED2 += ledCount;
    }

    if(tailLED3 < 0){
        tailLED3 += ledCount;
    }

    int tailLED0 = leds[i];
    tailLED1 = leds[tailLED1];
    tailLED2 = leds[tailLED2];
    tailLED3 = leds[tailLED3];

    for(int j = 0; j < ledCount; j++){
      analogWrite(leds[j], 1024);
    }

    analogWrite(tailLED0, 0);
    analogWrite(tailLED1, 500);
    analogWrite(tailLED2, 800);
    analogWrite(tailLED3, 1000);

    delay(100);
    
  }
}



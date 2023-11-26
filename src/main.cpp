#include <Arduino.h>

// put function declarations here:
int myFunction(int, int);
int ledPin = 13;                 // Светодиод подключенный к вход/выходу 13
int inPin0 = A0;                 // датчик на входе А0
int inPin1 = A1;                 // датчик на входе А1
int inPin2 = A2;                 // датчик на входе А2
int inPin3 = A3;                 // датчик на входе А3
int inPin4 = A4;                 // датчик на входе А4
int inPin5 = A5;                 // датчик на входе А5
int AinPin6 = A6;                 // датчик на входе А6
int outPin0 = 8;                 // выход 0 
int outPin1 = 7;                 // выход 1
int outPin2 = 6;                 // выход 2
int outPin3 = 5;                 // выход 3
int outPin4 = 4;                 // выход 4
int outPin5 = 3;                 // выход 5
int outPin6 = 2;                 // выход 6
int outPin7 = 1;                 // выход 6
  boolean in0 = false;
  boolean in1 = false;
  boolean in2 = false;
  boolean in3 = false;
  boolean in4 = false;
  boolean in5 = false;
  //boolean in6 = false;

int val = 0;                      // переменная для хранения значения
unsigned long currentMillis;      //for BEEP
unsigned long previousMillis;     //for BEEP
const long interval = 600;        // interva`l at which to beep (milliseconds)
int beepState = LOW;              // BEEP
int beepOn = LOW;                 // ON/OFF BEEP
//int timeset;                    // For analog input


void setup() {
    Serial.begin(9600);             //Serial
    pinMode(ledPin, OUTPUT);        // выход для светодиод 13 (pin)
    pinMode(outPin0, OUTPUT);       // выход 0
    pinMode(outPin1, OUTPUT);       // выход 1
    pinMode(outPin2, OUTPUT);       // выход 2 
    pinMode(outPin3, OUTPUT);       // выход 3
    pinMode(outPin4, OUTPUT);       // выход 4
    pinMode(outPin5, OUTPUT);       // выход 5 
    //pinMode(outPin6, OUTPUT);       // выход 6 NO digital input!!!!!!!!!!!!!!!
    DDRC = 0;                       // set pins A0-A7 as input, modeInpit() in Arduino
    //pinMode(AinPin6,analogInPinToBit);

    // put your setup code here, to run once:
    //int result = myFunction(2, 3);
}

void loop() {
    uint8_t data = PINC;                 // read all A0-A7 inputs (8 bits)
    //timeset = analogRead(AinPin6);              // read analog set
    
    Serial.println (data);           // Print portA HEX

    switch (data)
    {
      case 0:                                        //NUL
      digitalWrite(outPin0,LOW);                     // pin D8 = 0
      digitalWrite(outPin1,LOW);                     // pin D7 = 0
      digitalWrite(outPin2,LOW);                     // pin D6 = 0
      digitalWrite(outPin3,LOW);                     // pin D5 = 0
      beepOn = LOW;                                  // beep OFF            
      break;
      case 16:                                       //Pedal
      digitalWrite(outPin0,LOW);                     // pin D8 = 0
      digitalWrite(outPin1,LOW);                     // pin D7 = 0
      digitalWrite(outPin2,LOW);                     // pin D6 = 0
      digitalWrite(outPin3,LOW);                     // pin D5 = 0
      beepOn = LOW;                                  // beep OFF            
      break;
      case 17:                                       // T1 + PEDAL
      digitalWrite(outPin0,HIGH);                    // pin D8 = 1
      beepOn = LOW;                                  // beep OFF
      break;
      case 18:                                       // T2 + PEDAL
      digitalWrite(outPin1,HIGH);                    // pin D7 = 1
      beepOn = LOW;                                  // beep OFF
      break;
      case 20:                                       // T3 + PEDAL
      digitalWrite(outPin2,HIGH);                    // pin D6 = 1
      beepOn = LOW;                                  // beep OFF
      break;
      case 24:                                       // T4 + PEDAL
      digitalWrite(outPin3,HIGH);                    // pin D5 = 1
      beepOn = LOW;                                  // beep OFF
      break;
      case 1:
      beepOn = LOW;                                  // beep OFF 
      break;
      case 2:
      beepOn = LOW;                                  // beep OFF 
      break;
      case 4:
      beepOn = LOW;                                  // beep OFF 
      break;
      case 8:
      beepOn = LOW;                                  // beep OFF 
      break;
      case 32:
      beepOn = LOW;                                  // beep OFF 
      break;
      default:
      digitalWrite(outPin0,LOW);                     // pin D8 = 0
      digitalWrite(outPin1,LOW);                     // pin D7 = 0
      digitalWrite(outPin2,LOW);                     // pin D6 = 0
      digitalWrite(outPin3,LOW);                     // pin D5 = 0
      beepOn = HIGH;
      break;
    }
    unsigned long currentMillis = millis();          //BEEPER
    if (currentMillis - previousMillis >= interval) {    
       previousMillis = currentMillis;
        if (beepState == LOW) 
          {
            beepState = HIGH;
            previousMillis = previousMillis+100;
          } else 
          {
            beepState = LOW;
          }
          digitalWrite(ledPin, beepState);          //LED13 = takt beep
        if (beepOn == HIGH)
          {
          digitalWrite(outPin5, beepState);         // BEEP ON
          } else
          {
          digitalWrite(outPin5,LOW);                // BEEP OFF
          }
    }
}  

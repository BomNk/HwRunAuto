/*
  Analog Input

  Demonstrates analog input by reading an analog sensor on analog pin 0 and
  turning on and off a light emitting diode(LED) connected to digital pin 13.
  The amount of time the LED will be on and off depends on the value obtained
  by analogRead().

  The circuit:
  - potentiometer
    center pin of the potentiometer to the analog input 0
    one side pin (either one) to ground
    the other side pin to +5V
  - LED
    anode (long leg) attached to digital output 13
    cathode (short leg) attached to ground

  - Note: because most Arduinos have a built-in LED attached to pin 13 on the
    board, the LED is optional.

  created by David Cuartielles
  modified 30 Aug 2011
  By Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogInput
*/
#define USE_ARDUINO_INTERRUPTS true    // Set-up low-level interrupts for most acurate BPM math.
#include <PulseSensorPlayground.h>     // Includes the PulseSensorPlayground Library. 
const byte interruptPin = 2;
volatile byte state = LOW;


const int PulseWire = A0;   // select the input pin for the potentiometer
//const int PulseWire = A0;       // PulseSensor PURPLE WIRE connected to ANALOG PIN 0
const int LED13 = 13;          // The on-board Arduino LED, close to PIN 13.
int Threshold = 550;
PulseSensorPlayground pulseSensor;

// select the pin for the LED

int Motor1_INT1 = 4;// variable to storethe value coming from the sensor
int Motor1_INT2 = 5;
int Motor1_Enable = 3;

char speedMotor;
int count=0;

//char ch;
void setup() {
  // declare the ledPin as an OUTPUT:
 
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink,FALLING);
  
  pinMode(Motor1_INT1,OUTPUT);
  pinMode(Motor1_INT2,OUTPUT);
  pinMode(Motor1_Enable,OUTPUT);
  //pinMode(PulseWire,INPUT);

  digitalWrite(Motor1_INT1,LOW);
  digitalWrite(Motor1_INT2,LOW);
  //digitalWrite(Motor1_Enable,50);
  
  //pinMode(ledPin, OUTPUT);
  Serial.begin(9600);

   pulseSensor.analogInput(PulseWire);   
  pulseSensor.blinkOnPulse(LED13);       //auto-magically blink Arduino's LED with heartbeat.
  pulseSensor.setThreshold(Threshold);   

  // Double-check the "pulseSensor" object was created and "began" seeing a signal. 
   if (pulseSensor.begin()) {
    //Serial.println("We created a pulseSensor Object !");  //This prints one time at Arduino power-up,  or on Arduino reset.  
  }

  speedMotor = '0';
}

void loop() {
  speedMotor = Serial.read();
  int myBPM = pulseSensor.getBeatsPerMinute();  

  if (pulseSensor.sawStartOfBeat()) {            // Constantly test to see if "a beat happened". 
 //Serial.println("♥  A HeartBeat Happened ! "); // If test is "true", print a message "a heartbeat happened".
 //Serial.print("BPM: ");                        // Print phrase "BPM: " 
    Serial.print(myBPM);    // Print the value inside of myBPM.
  
  }
  else{
     Serial.print(myBPM);
  }
  Serial.print("/");

  if(state == 1){
      state = 0;
      count = count + 1;
      delay(20);
  }
  Serial.println(count);
  
  //ch = Serial.read();
  //data_input  = digitalRead(Pro_input);
  //sensorValue = analogRead(sensorPin);
  //Serial.println(data_input);
  //Serial.println(sensorValue,DEC);
  motorA(speedMotor);
  //analogWrite(Motor1_Enable,sensorValue);
  delay(40);
}
void motorA(char ch){
  
    digitalWrite(Motor1_INT1,HIGH);
    digitalWrite(Motor1_INT2,LOW);
   if(ch == '0'){
     analogWrite(Motor1_Enable,0);
   }
    if(ch == '1'){
     analogWrite(Motor1_Enable,50);
   }
    if(ch == '2'){
    analogWrite(Motor1_Enable,100);
   }
   if(ch == '3'){
     analogWrite(Motor1_Enable,150);
   }
   if(ch == '4'){
     analogWrite(Motor1_Enable,200);
   }     
   if(ch == '5'){
    analogWrite(Motor1_Enable,250);
   }
}
void blink() {
  state = !state;
  
  
}

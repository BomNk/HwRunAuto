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

int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;
int Motor1_INT1 = 4;// variable to storethe value coming from the sensor
int Motor1_INT2 = 5;
int Motor1_Enable = 3;
int Pro_input = 2;
int data_input = 0;
char ch;
void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(Motor1_INT1,OUTPUT);
  pinMode(Motor1_INT2,OUTPUT);
  pinMode(Motor1_Enable,OUTPUT);
  pinMode(Pro_input,INPUT);

  digitalWrite(Motor1_INT1,LOW);
  digitalWrite(Motor1_INT2,LOW);
  //digitalWrite(Motor1_Enable,50);
  
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  ch = Serial.read();
  data_input  = digitalRead(Pro_input);
  sensorValue = analogRead(sensorPin);
  Serial.println(data_input);
  Serial.println(sensorValue,DEC);
  motorA(ch);
  analogWrite(Motor1_Enable,sensorValue);
  
}
void motorA(char ch){
   if(ch == 'L'){
      digitalWrite(Motor1_INT1,HIGH);
      digitalWrite(Motor1_INT2,LOW);
      
   }
   if(ch == 'R'){
      digitalWrite(Motor1_INT1,LOW);
      digitalWrite(Motor1_INT2,HIGH);
      //digitalWrite(Motor1_Enable,50);
   }     
}
void button_input(){
     
}


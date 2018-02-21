const byte ledPin = 13;
const byte interruptPin = 2;
volatile byte state = LOW;
int count = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink,FALLING);
}

void loop() {
  Serial.println(count);
  digitalWrite(ledPin, state);
  if(state == 1){
      state = 0;
      count = count + 1;
       delay(200);
  }
  //delay(100);
}

void blink() {
  state = !state;
  
  
}

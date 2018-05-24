
int switchState = 0;


void setup() {
  // Switch as input
  pinMode(2, INPUT);
  
  // LED as outputs
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  switchState = digitalRead(2);
  
  if(switchState == 0) {
    digitalWrite(3, HIGH);

    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }
  else {
    digitalWrite(3, LOW);

    // Blinking LEDs
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    delay(100);
    digitalWrite(4, LOW);
    delay(100);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    delay(100);
  }
  
}

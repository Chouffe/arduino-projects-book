const int INSTRUMENT_PIN = A0;
const int PIEZZO_PIN = 8;
const int LED_PIN = 13;

const int NOTES[] = {262, 294, 330, 349};

int keyValue = 0;

void setup() {
  // Start debugger
  Serial.begin(9600);

  // Set INPUT/OUTPUT
  pinMode(INSTRUMENT_PIN, INPUT);
  pinMode(PIEZZO_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {

  keyValue = analogRead(INSTRUMENT_PIN);
  delay(5);

  // Debug
  Serial.print("keyValue = ");
  Serial.println(keyValue);

  // PIEZZO output based on i value
  if (keyValue >= 1023) {
    tone(PIEZZO_PIN, NOTES[0]);
    digitalWrite(LED_PIN, LOW);
  }
  else if (keyValue >= 990) {
    tone(PIEZZO_PIN, NOTES[1]);
    digitalWrite(LED_PIN, LOW);
  }
  else if (keyValue >= 505) {
    tone(PIEZZO_PIN, NOTES[2]);
    digitalWrite(LED_PIN, LOW);
  }
  else if (keyValue >= 5) {
    tone(PIEZZO_PIN, NOTES[3]);
    digitalWrite(LED_PIN, LOW);
  }
  else {
    noTone(PIEZZO_PIN);
    digitalWrite(LED_PIN, HIGH);
  }

}

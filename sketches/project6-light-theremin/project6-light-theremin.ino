const int PIEZZO_PIN = 8;
const int SENSOR_PIN = A0;
const int LED_PIN = 13;

int sensorLowValue = 1023;
int sensorHighValue = 0;
int sensorValue;


void setup() {
  
  // INPUT/OUTPUT setup
  pinMode(PIEZZO_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(SENSOR_PIN, INPUT);

  Serial.begin(9600);

  // Sensor Calibration
  digitalWrite(LED_PIN, HIGH);
  
  while(millis() <= 5000) {
    sensorValue = analogRead(SENSOR_PIN);

    if (sensorValue > sensorHighValue) {
      sensorHighValue = sensorValue;
    }
    if (sensorValue < sensorLowValue) {
      sensorLowValue = sensorValue;
    }
  }

  digitalWrite(LED_PIN, LOW);
  // End of Calibration

}

void loop() {

  sensorValue = analogRead(SENSOR_PIN);
  int pitch = map(sensorValue, sensorLowValue, sensorHighValue, 50, 4000);

  tone(PIEZZO_PIN, pitch, 100);
  delay(10);

}

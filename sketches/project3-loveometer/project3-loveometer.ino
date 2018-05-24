// Initialize constants
const int SENSOR_PIN = A0;
const float BASELINE_TEMP = 28.0;
const float THRESHOLD_TEMP_1 = 30.0;
const float THRESHOLD_TEMP_2 = 32.0;

// Util functions
float getVoltage(float sensorVal) {
  return sensorVal / 1024.0 * 5.0;
}

float getTemperature(float voltage) {
  return (voltage - .5) * 100;
}

void setup() {
  // Open a Serial Port
  Serial.begin(9600);
  
  // Inputs
  pinMode(SENSOR_PIN, INPUT);

  // Outputs
  for (int pinNumber = 2; pinNumber < 5; pinNumber++) {
      pinMode(pinNumber, OUTPUT);
      digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  
  // Getting voltage and temperature from sensor
  int sensorVal = analogRead(SENSOR_PIN);

  float voltage = getVoltage(sensorVal);
  float temperature = getTemperature(voltage);

  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);
  Serial.print(", Volts: ");
  Serial.print(voltage);
  Serial.print(", Temperature: ");
  Serial.println(temperature);

  if (temperature < BASELINE_TEMP) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if (temperature < THRESHOLD_TEMP_1) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if (temperature < THRESHOLD_TEMP_2) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }
  else {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  } 
  
  // the analog reader cannot read so fast so add a delay to make it happy :-)
  delay(1);
}

const int GREEN_LED_PIN = 9;
const int BLUE_LED_PIN = 10;
const int RED_LED_PIN = 11;

const int GREEN_SENSOR_PIN = A2;
const int BLUE_SENSOR_PIN = A1;
const int RED_SENSOR_PIN = A0;

int greenValue = 0;
int blueValue = 0;
int redValue = 0;

int greenSensorValue = 0;
int blueSensorValue = 0;
int redSensorValue = 0;


void setup() {
  Serial.begin(9600);

  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);

}


void loop() {

  // Reading Sensor Values
  greenSensorValue = analogRead(GREEN_SENSOR_PIN);
  delay(5);
  blueSensorValue = analogRead(BLUE_SENSOR_PIN);
  delay(5);
  redSensorValue = analogRead(RED_SENSOR_PIN);
  delay(5);

  // Debug
  Serial.print("green: ");
  Serial.print(greenSensorValue);
  Serial.print(", blue: ");
  Serial.print(blueSensorValue);
  Serial.print(", red: ");
  Serial.print(redSensorValue);

  Serial.println("");

  // Map to Output values: [0-..1023] -> [0..255]
  greenValue = greenSensorValue / 4;
  blueValue = blueSensorValue / 4;
  redValue = redSensorValue / 4;

  analogWrite(GREEN_LED_PIN, greenValue);
  analogWrite(BLUE_LED_PIN, blueValue);
  analogWrite(RED_LED_PIN, redValue);
  

}

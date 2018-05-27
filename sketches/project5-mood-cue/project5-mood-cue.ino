#include <Servo.h>

// Intialize a Servo Object
Servo myServo;

// Initialize PINs
const int POTENTIOMETER_PIN = A1;
const int SERVO_PIN = 9;

int potVal = 0;
int angle = 0;

void setup() {

  // Attach Serial debugger
  Serial.begin(9600);
  
  // Attach Servo
  myServo.attach(SERVO_PIN);
  
  // Set potentiometer PIN
  pinMode(POTENTIOMETER_PIN, INPUT);

}

void loop() {

  potVal = analogRead(POTENTIOMETER_PIN);
  angle = map(potVal, 0, 1023, 0, 179);

  // Write angle to servo motor
  myServo.write(angle);

  // Debug Statements
  Serial.print("potVal: ");
  Serial.print(potVal);
  Serial.print("angle: ");
  Serial.print(angle);
  Serial.println("");

  // Some delay for the servo to have time to rotate
  delay(15);

}

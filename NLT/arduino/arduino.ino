#include <Servo.h>

Servo myServo;

const int startPin  = 2;   // Pi → Arduino
const int stopPin   = 4;   // Arduino → Pi
const int buttonPin = 3;   // Stopknop
const int servoPin  = 9;

void setup() {
  pinMode(startPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(stopPin, OUTPUT);

  myServo.attach(servoPin);
  myServo.write(0);            // motor uit bij start
  digitalWrite(stopPin, LOW);
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    // KNOP INGEDRUKT → alles uit
    myServo.write(0);
    digitalWrite(stopPin, HIGH);
  }
  else if (digitalRead(startPin) == HIGH) {
    // Pi activeert motor
    myServo.write(90);
    digitalWrite(stopPin, LOW);
  }
  else {
    myServo.write(0);
    digitalWrite(stopPin, LOW);
  }
}

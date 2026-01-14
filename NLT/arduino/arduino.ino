#include <Servo.h>

Servo servo;

const int startPin = 2;   // Pi → Arduino
const int servoPin = 9;

void setup() {
  pinMode(startPin, INPUT);
  servo.attach(servoPin);
  servo.write(0);         // rustpositie
}

void loop() {
  if (digitalRead(startPin) == HIGH) {
    servo.write(90);      // beweeg
  } else {
    servo.write(0);       // terug
  }
}

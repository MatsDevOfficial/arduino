#include <Servo.h>

Servo servo;
const int servoPin = 9;

void setup() {
  servo.attach(servoPin);
  servo.write(0);          // startpositie
}

void loop() {
  servo.write(90);         // beweeg naar 90°
  delay(500);              // 0,5 s vasthouden

  servo.write(0);          // terug naar 0°
  delay(1000);            // 10 s wachten
}

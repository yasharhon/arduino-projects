#include <Servo.h>

int const potPin = A0;
int const servoPin = 9;

Servo myServo;

 void setup() {
  // put your setup code here, to run once:
  myServo.attach(servoPin);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

}

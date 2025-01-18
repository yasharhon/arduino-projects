#include <Servo.h>

int const potPin = A0;
int const servoPin = 9;

int potVal;
int angle;

Servo myServo;

 void setup() {
  // put your setup code here, to run once:
  myServo.attach(servoPin);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  potVal = analogRead(potPin);
  angle = map(potVal, 0, 1023, 0, 179);

  Serial.print("Potentiometer: ");
  Serial.print(potVal);
  Serial.print(". Angle: ");
  Serial.print(angle);
  Serial.println();
}

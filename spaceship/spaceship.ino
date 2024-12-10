int switchState = 0;
int switchParallelPin = 2;
int red1 = 4;
int red2 = 5;
int green = 3;
int delayVal = 250;

void setup() {
  // put your setup code here, to run once:
  pinMode(switchParallelPin, INPUT);
  pinMode(green, OUTPUT);
  pinMode(red1, OUTPUT);
  pinMode(red2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(switchParallelPin);

  if (switchState == LOW)
  {
    digitalWrite(green, HIGH);
    digitalWrite(red1, LOW);
    digitalWrite(red2, LOW);
  }
  else
  {
    digitalWrite(green, LOW);

    digitalWrite(red1, LOW);
    digitalWrite(red2, LOW);
    delay(delayVal);

    digitalWrite(red1, HIGH);
    digitalWrite(red2, HIGH);
    delay(delayVal);
  }
}

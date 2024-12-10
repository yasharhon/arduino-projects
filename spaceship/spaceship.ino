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

void setOffState()
{
  digitalWrite(green, HIGH);
  digitalWrite(red1, LOW);
  digitalWrite(red2, LOW);
}

void setPersistentOnState()
{
  digitalWrite(green, LOW);
}

void setOnState1()
{
  digitalWrite(red1, LOW);
  digitalWrite(red2, LOW);
}

void setOnState2()
{
  digitalWrite(red1, HIGH);
  digitalWrite(red2, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(switchParallelPin);

  if (switchState == LOW)
  {
    setOffState();
  }
  else
  {
    setPersistentOnState();

    setOnState1();
    delay(delayVal);

    setOnState2();
    delay(delayVal);
  }
}

const int sensorPin = A0;
const float ambientTemp = 20.0;

void setup ()
{
  Serial.begin(9600);

  for (int portNo = 2; portNo < 4; portNo++)
  {
    pinMode(portNo, OUTPUT);
    digitalWrite(portNo, LOW);
  }
}

void loop()
{
  int sensorVal = analogRead(sensorPin);

  Serial.print("Sensor value: ");
  Serial.print(sensorVal);
}
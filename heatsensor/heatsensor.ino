const int sensorPin = A0;
const float ambientTemp = 20.0;
const float maxAnalogReadValue = 1024.0;
const float maxVoltage = 5.0;
const float voltageAtZeroCelsius = 0.5;
const float celsiusChangePerVoltChange = 100.0;
const int finalDelay = 100;

void setup ()
{
  Serial.begin(9600);

  for (int portNo = 2; portNo <= 4; portNo++)
  {
    pinMode(portNo, OUTPUT);
    digitalWrite(portNo, LOW);
  }
}

float analogToVoltage(float analogVal)
{
  return (analogVal / maxAnalogReadValue) * maxVoltage;
}

float voltageToCelsiusTemp(float voltage)
{
  return (voltage - voltageAtZeroCelsius) * celsiusChangePerVoltChange;
}

void printMessageAndValue(char* message, float value)
{
  Serial.print(message);
  Serial.print(value);
}

void printLineBreak()
{
  Serial.println();
}

void loop()
{
  int sensorVal = analogRead(sensorPin);

  printMessageAndValue("Sensor value: ", sensorVal);

  float voltageVal = analogToVoltage(sensorVal);
  printMessageAndValue(". Voltage: ", voltageVal);

  float tempVal = voltageToCelsiusTemp(voltageVal);
  printMessageAndValue(". Temperature (C): ", tempVal);

  printLineBreak();

  int maxLightedPortNo = 2;

  if (tempVal > ambientTemp + 2 * 3)
  {
    maxLightedPortNo = 4;
  }
  else if (tempVal > ambientTemp + 2 * 2)
  {
    maxLightedPortNo = 3;
  }
  else if (tempVal > ambientTemp + 2 * 1)
  {
    maxLightedPortNo = 2;
  }
  else
  {
    maxLightedPortNo = 1;
  }

  for (int portNo = 2; portNo <= maxLightedPortNo; portNo++)
  {
    digitalWrite(portNo, HIGH);
  }

  delay(finalDelay);
}
const int sensorPin = A0;
const float ambientTemp = 20.0;
const float maxAnalogReadValue = 1024.0;
const float maxVoltage = 5.0;
const float voltageAtZeroCelsius = 0.5;
const float celsiusChangePerVoltChange = 100.0;
const float degreesPerPort = 2.0;
const int finalDelay = 100;

int treatedPorts[] = {2, 3, 4};
int noOfTreatedPorts = 3;

void setup ()
{
  Serial.begin(9600);

  for (int i = 0; i < noOfTreatedPorts; i++)
  {
    pinMode(treatedPorts[i], OUTPUT);
    digitalWrite(treatedPorts[i], LOW);
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

  float tempAboveAmbient = tempVal - ambientTemp;

  int portsToLight = 0;

  if (tempAboveAmbient > 0)
  {
    portsToLight = (int)(tempAboveAmbient / degreesPerPort);
  }

  for (int i = 0; i < portsToLight; i++)
  {
    digitalWrite(treatedPorts[i], HIGH);
  }

  for (int j = portsToLight; j < 3; j++)
  {
    digitalWrite(treatedPorts[j], LOW);
  }

  delay(finalDelay);
}
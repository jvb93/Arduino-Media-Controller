#include "RotaryEncoder.h"

int encoderPin1 = 2;
int encoderPin2 = 3;
int encoderSwitchPin = 4;


RotaryEncoder* rotaryEncoder;
int lastValue = 0;

void setup() 
{
  Serial.begin (9600);
  rotaryEncoder = new RotaryEncoder(encoderPin1, encoderPin2, encoderSwitchPin);
  rotaryEncoder->init([]{rotaryEncoder->UpdateEncoder();});
}

void loop() 
{

  if (rotaryEncoder->WasPushed()) 
  {
    Serial.println("pushed");
  }

  int currentValue = rotaryEncoder->Value();
  Serial.println(currentValue);

  if (currentValue < lastValue) 
  {
    Serial.println("down");
  }

  else if (currentValue > lastValue)
  {
    Serial.println("up");
  }

  else 
  {
    Serial.println("no change");
  }

  lastValue = currentValue;

  delay(1000); 
}

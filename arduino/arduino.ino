#include "RotaryEncoder.h"
#include "Button.h"
#include "HID-Project.h"

int encoderPin1 = 0;
int encoderPin2 = 1;
int encoderSwitchPin = 2;
int nextButtonPin = 3;
int pauseButtonPin = 4;
int previousButtonPin = 7;

RotaryEncoder* rotaryEncoder;
Button* nextButton;
Button* previousButton;
Button* pauseButton;

int lastValue = 0;

void setup() 
{
  Consumer.begin();

  rotaryEncoder = new RotaryEncoder(encoderPin1, encoderPin2, encoderSwitchPin);
  rotaryEncoder->init([]{rotaryEncoder->UpdateEncoder();});
  
  nextButton = new Button(nextButtonPin);
  previousButton = new Button(previousButtonPin);
  pauseButton = new Button(pauseButtonPin);
}

void loop() 
{
  int currentValue = rotaryEncoder->Value();

  if (currentValue < lastValue) 
  {
    Consumer.write(MEDIA_VOLUME_DOWN);
  }

  else if (currentValue > lastValue)
  {
    Consumer.write(MEDIA_VOLUME_UP);
  }

  lastValue = currentValue;

  if (rotaryEncoder->IsPushed()) 
  {
    Consumer.write(MEDIA_VOLUME_MUTE);
  }

  if (nextButton->IsPushed())
  {
    Consumer.write(MEDIA_NEXT);
  }

  if (previousButton->IsPushed())
  {
    Consumer.write(MEDIA_PREVIOUS);
  }

  if (pauseButton->IsPushed())
  {
    Consumer.write(MEDIA_PLAY_PAUSE);
  }

}

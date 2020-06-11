#include "RotaryEncoder.h"
#include "Button.h"
#include "HID-Project.h"

int encoderPin1 = 0;
int encoderPin2 = 1;
int encoderSwitchPin = 2;
int nextButtonPin = 3;
int previousButtonPin = 7;


RotaryEncoder* rotaryEncoder;
Button* nextButton;
Button* previousButton;



int lastValue = 0;

void setup() 
{
  Serial.begin (9600);
  Consumer.begin();

  rotaryEncoder = new RotaryEncoder(encoderPin1, encoderPin2, encoderSwitchPin);
  rotaryEncoder->init([]{rotaryEncoder->UpdateEncoder();}, []{rotaryEncoder->Trigger();});
  nextButton = new Button(nextButtonPin);
  nextButton->init([] { nextButton->Trigger(); });

  previousButton = new Button(previousButtonPin);
  previousButton->init([] { previousButton->Trigger(); });
}

void loop() 
{

  if (rotaryEncoder->WasPushed()) 
  {
    Consumer.write(MEDIA_PLAY_PAUSE);
    rotaryEncoder->ResetButton();
  }

  int currentValue = rotaryEncoder->Value();

  if (currentValue < lastValue) 
  {
    Consumer.write(MEDIA_VOLUME_DOWN);
    Consumer.write(MEDIA_VOLUME_DOWN);
    Consumer.write(MEDIA_VOLUME_DOWN);
  }

  else if (currentValue > lastValue)
  {
    Consumer.write(MEDIA_VOLUME_UP);
    Consumer.write(MEDIA_VOLUME_UP);
    Consumer.write(MEDIA_VOLUME_UP);
  }

  lastValue = currentValue;

  if (nextButton->WasPushed())
  {
    Consumer.write(MEDIA_NEXT);
    nextButton->Reset();
  }
  
  if (previousButton->WasPushed())
  {
    Consumer.write(MEDIA_PREVIOUS);
    previousButton->Reset();
  }
  
  delay(500); 
}

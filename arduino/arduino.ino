#include "RotaryEncoder.h"
#include "Button.h"

int encoderPin1 = 2;
int encoderPin2 = 3;
int encoderSwitchPin = 18;
int playButtonPin = 19;
int nextButtonPin = 20;
int previousButtonPin = 21;


RotaryEncoder* rotaryEncoder;
Button* playButton;
Button* nextButton;
Button* previousButton;


int lastValue = 0;

void setup() 
{
  Serial.begin (9600);
  rotaryEncoder = new RotaryEncoder(encoderPin1, encoderPin2, encoderSwitchPin);
  rotaryEncoder->init([]{rotaryEncoder->UpdateEncoder();}, []{rotaryEncoder->Trigger();});
  
  playButton = new Button(playButtonPin);
  playButton->init([]{playButton->Trigger();});

  nextButton = new Button(nextButtonPin);
  nextButton->init([] { nextButton->Trigger(); });

  previousButton = new Button(previousButtonPin);
  previousButton->init([] { previousButton->Trigger(); });
}

void loop() 
{

  if (rotaryEncoder->WasPushed()) 
  {
    Serial.println("mute pushed");
    rotaryEncoder->ResetButton();
  }

  int currentValue = rotaryEncoder->Value();

  if (currentValue < lastValue) 
  {
    Serial.println("volume down");
  }

  else if (currentValue > lastValue)
  {
    Serial.println("volume up");
  }


  lastValue = currentValue;

  if (playButton->WasPushed())
  {
    Serial.println("play pushed");
    playButton->Reset();
  }

  if (nextButton->WasPushed())
  {
    Serial.println("next pushed");
    nextButton->Reset();
  }
  
  if (previousButton->WasPushed())
  {
    Serial.println("previous pushed");
    previousButton->Reset();
  }

  delay(100); 
}

#include "RotaryEncoder.h"
#include "Button.h"

RotaryEncoder::RotaryEncoder(int pin1, int pin2, int button)
{
    _pin1 = pin1;
    _pin2 = pin2;
    _button = button;
    _encoderValue = 0;
    _lastEncoded = 0;
    _lastencoderValue = 0;

    _encoderButton = new Button(_button);
}

void RotaryEncoder::UpdateEncoder(void)
{
    int MSB = digitalRead(_pin1);
    int LSB = digitalRead(_pin2);

    int encoded = (MSB << 1) | LSB;
    int sum = (_lastEncoded << 2) | encoded; 

     if (sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) 
     {
         _encoderValue++;
     }

     if (sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) 
     {
         _encoderValue--;
     }

     _lastEncoded = encoded;
}


long RotaryEncoder::Value()
{
    return _encoderValue;
}

bool RotaryEncoder::IsPushed()
{
    return _encoderButton->IsPushed();
}

void RotaryEncoder::init(void (*rotaryCallback)(void))
{
    pinMode(_pin1, INPUT);
    pinMode(_pin2, INPUT);
    pinMode(_button, INPUT);

    digitalWrite(_pin1, HIGH);
    digitalWrite(_pin2, HIGH);
    digitalWrite(_button, HIGH);

    attachInterrupt(digitalPinToInterrupt(_pin1), rotaryCallback, CHANGE);
    attachInterrupt(digitalPinToInterrupt(_pin2), rotaryCallback, CHANGE);
}

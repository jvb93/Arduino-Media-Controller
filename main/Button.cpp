#include "Button.h"

Button::Button(int pin)
{   
    _pin = pin;
    _latch = false;
}

void Button::Trigger(void)
{
    _latch = true;
}

void Button::Reset(void)
{
    _latch = false;
}

bool Button::WasPushed(void)
{
    return _latch;
}

void Button::init(void (*ISR_callback)(void))
{
    pinMode(_pin, INPUT);
   
    digitalWrite(_pin, HIGH);

    attachInterrupt(digitalPinToInterrupt(_pin), ISR_callback, RISING);
}

#include "Button.h"

Button::Button(int pin)
{   
    _pin = pin;
    _lastButtonState = LOW;
    _lastDebounceTime = 0;
    _debounceDelay = 50;

    pinMode(_pin, INPUT);
    digitalWrite(_pin, HIGH);
}

bool Button::IsPushed()
{
    int reading = digitalRead(_pin);
    bool toReturn = false;

    if (reading != _lastButtonState)
    {
        _lastDebounceTime = millis();
    }

    if ((millis() - _lastDebounceTime) > _debounceDelay)
    {
        if (reading != _buttonState)
        {
            _buttonState = reading;
            toReturn = _buttonState == HIGH;
        }
    }

    _lastButtonState = reading;
    
    return toReturn;
}

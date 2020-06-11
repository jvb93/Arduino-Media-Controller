#ifndef Button_h
#define Button_h

#include <Arduino.h>

class Button
{
    private:
        int _pin;
        int _lastButtonState;
        int _buttonState;
        unsigned long _lastDebounceTime;
        unsigned long _debounceDelay;
        
    public:
        Button(int pin);
        bool IsPushed();
};

#endif

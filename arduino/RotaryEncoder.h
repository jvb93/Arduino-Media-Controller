#ifndef RotaryEncoder_h
#define RotaryEncoder_h

#include <Arduino.h>
#include "Button.h"

class RotaryEncoder
{
    private:
        int _pin1;
        int _pin2;
        int _button;
        volatile long _encoderValue;
        volatile int _lastEncoded;
        long _lastencoderValue;
        void(*rotaryCallback)();
        Button * _encoderButton;

    public:
        RotaryEncoder(int pin1, int pin2, int button);
        void UpdateEncoder();
        long Value();
        bool IsPushed();
        void init(void (*rotaryCallback)(void));
};

#endif

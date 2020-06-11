#ifndef RotaryEncoder_h
#define RotaryEncoder_h

#include <Arduino.h>

class RotaryEncoder
{
    private:
        int _pin1;
        int _pin2;
        int _button;
        bool _latch;
        volatile long _encoderValue;
        volatile int _lastEncoded;
        long _lastencoderValue;
        void(*rotaryCallback)();
        void(*buttonCallback)();

    public:
        RotaryEncoder(int pin1, int pin2, int button);
        void UpdateEncoder();
        void Trigger();
        void ResetButton();
        long Value();
        bool WasPushed();
        void init(void (*rotaryCallback)(void), void (*buttonCallback)(void));

};

#endif

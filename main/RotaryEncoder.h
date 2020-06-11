#ifndef RotaryEncoder_h
#define RotaryEncoder_h

#include <Arduino.h>

class RotaryEncoder
{
    private:
        int _pin1;
        int _pin2;
        int _button;
        volatile long _encoderValue;
        volatile int _lastEncoded;
        long _lastencoderValue;
        void(*ISR_callback)();

    public:
        RotaryEncoder(int pin1, int pin2, int button);
        void UpdateEncoder();
        long Value();
        bool WasPushed();
        void init(void (*ISR_callback)(void));

};

#endif

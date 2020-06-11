#ifndef Button_h
#define Button_h

#include <Arduino.h>

class Button
{
    private:
        int _pin;
        bool _latch;
        void(*ISR_callback)();

    public:
        Button(int pin);
        void Trigger();
        void Reset();
        bool WasPushed();
        void init(void (*ISR_callback)(void));

};

#endif

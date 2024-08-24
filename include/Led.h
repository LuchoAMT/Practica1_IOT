#ifndef LED_H
#define LED_H

class Led {
private:
    int pin;
    bool isOn;
    unsigned long previousMillis;
    unsigned long interval;

public:
    Led(int pin, unsigned long interval);
    void update(long distance);
    void turnOn();
    void turnOff();
};

#endif

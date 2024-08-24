#include "Led.h"
#include <Arduino.h>

Led::Led(int pin, unsigned long interval) {
    this->pin = pin;
    this->interval = interval;
    pinMode(pin, OUTPUT);
    isOn = false;
    previousMillis = 0;
}

void Led::update(long distance) {
    unsigned long currentMillis = millis();
    bool shouldBlink = false;

    // Determinar si el LED debe parpadear o encenderse constantemente
    if (distance > 200) {
        turnOn();
    } else if ((pin == 2 && distance <= 50) ||
               (pin == 4 && distance > 50 && distance <= 100) ||
               (pin == 32 && distance > 100 && distance <= 150) ||
               (pin == 33 && distance > 150 && distance <= 200)) {
        shouldBlink = true;
    } else {
        turnOff();
    }

    // Parpadeo del LED si corresponde
    if (shouldBlink) {
        if (currentMillis - previousMillis >= interval) {
            previousMillis = currentMillis;
            isOn = !isOn;
            digitalWrite(pin, isOn ? HIGH : LOW);
        }
    }
}

void Led::turnOn() {
    digitalWrite(pin, HIGH);
}

void Led::turnOff() {
    digitalWrite(pin, LOW);
    isOn = false;
}

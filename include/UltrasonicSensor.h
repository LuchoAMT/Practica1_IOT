#ifndef ULTRASONICSENSOR_H
#define ULTRASONICSENSOR_H

class UltrasonicSensor {
private:
    int trigPin;
    int echoPin;

public:
    UltrasonicSensor(int trigPin, int echoPin);
    long measureDistance();
};

#endif
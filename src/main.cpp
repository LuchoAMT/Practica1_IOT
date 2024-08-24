#include <Arduino.h>
#include "UltrasonicSensor.h"
#include "Led.h"

// Pines para el sensor ultrasónico
const int trigPin = 5;
const int echoPin = 18;

// Pines para los LEDs
const int led1Pin = 2;
const int led2Pin = 4;
const int led3Pin = 32;
const int led4Pin = 33;

UltrasonicSensor sensor(trigPin, echoPin);
Led led1(led1Pin, 500);
Led led2(led2Pin, 500);
Led led3(led3Pin, 500);
Led led4(led4Pin, 500);

void setup() {
    Serial.begin(115200);
}

void loop() {
    long distance = sensor.measureDistance();

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    led1.update(distance);
    led2.update(distance);
    led3.update(distance);
    led4.update(distance);
}

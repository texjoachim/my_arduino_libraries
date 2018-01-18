// motor.h

// our motor helper class

#include <Arduino.h>

class motor {
private:
    unsigned int _directionPinForward;
    unsigned int _directionPinReverse;
    unsigned int _speedPin;

public:
    motor(const unsigned int directionPinForward, const unsigned int directionPinReverse, const unsigned int speedPin) {
            _directionPinForward = directionPinForward;
            _directionPinReverse = directionPinReverse;
            _speedPin = speedPin;
            pinMode(_directionPinForward, OUTPUT);
            pinMode(_directionPinReverse, OUTPUT);
            pinMode(_speedPin, OUTPUT);
            digitalWrite(_directionPinForward, LOW);
            digitalWrite(_directionPinReverse, LOW);
            analogWrite(_speedPin, 0);
    }

    void stop() {
        digitalWrite(_directionPinForward, LOW);
        digitalWrite(_directionPinReverse, LOW);
        analogWrite(_speedPin, 0);
    }

    void forward(unsigned int speed) {
        digitalWrite(_directionPinForward, HIGH);
        digitalWrite(_directionPinReverse, LOW);
        analogWrite(_speedPin, speed);
    }

    void reverse(unsigned int speed) {
        digitalWrite(_directionPinForward, LOW);
        digitalWrite(_directionPinReverse, HIGH);
        analogWrite(_speedPin, speed);
    }

};
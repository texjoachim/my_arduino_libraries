// PIR.h

#include <Arduino.h>

// our colour sensor class

class PIR {
private:
	unsigned int _pin; // the output pin

public:
    PIR(const unsigned int pin) {
		_pin = pin; 
		pinMode(_pin, INPUT);
		}

    bool motion() {
        int val;
        val = digitalRead(_pin);
        if (val == HIGH) {
            return true;
        }
        else {
            return false;
        }
    }

bool nomotion() {
        int val;
        val = digitalRead(_pin);
        if (val == LOW) {
            return true;
        }
        else {
            return false;
        }
    }

};
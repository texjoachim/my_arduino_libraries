// flame.h

#include <Arduino.h>

// our flame sensor class

class flame {
private:
	unsigned int _pin;

public:
	flame(const unsigned int pin) {
		_pin = pin;
		pinMode(_pin, INPUT);
	}
	
	bool isNoFlame() {
		bool sense = digitalRead(_pin);
		if (sense == HIGH) {
			return true;
		}
		else {
			return false;
		}
	}

	bool isFlame() {
		bool sense = digitalRead(_pin);
		if (sense == LOW) {
			return true;
		}
		else {
			return false;
		}
	}
};
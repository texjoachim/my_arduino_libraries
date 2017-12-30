// LED.h

#include <SoftPWM.h>

// our LED class

class LED {
private:
	unsigned int _pin;

public:
	LED(const unsigned int pin) {
		_pin = pin;
		pinMode(_pin, OUTPUT);
	}

	void flicker(unsigned int intensity) {
		SoftPWMSetPercent(_pin, intensity);
		}
	}

	void on() {
		digitalWrite(_pin, HIGH);
		}
	}

	void off() {
		digitalWrite(_pin, LOW);
	}
};
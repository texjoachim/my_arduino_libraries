// ky033.h

// our ky033 class
class ky033 {
private:
	unsigned int _pin;

public:
	ky033(const unsigned int pin) {
		_pin = pin;
		pinMode(_pin, INPUT);
	}
	
	bool isDark() {
		bool sense = digitalRead(_pin);
		if (sense == HIGH) {
			return true;
		}
		else {
			return false;
		}
	}

	bool isLight() {
		bool sense = digitalRead(_pin);
		if (sense == LOW) {
			return true;
		}
		else {
			return false;
		}
	}
};

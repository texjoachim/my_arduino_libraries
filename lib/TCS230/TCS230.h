// TCS230.h

#include <Arduino.h>

// our colour sensor class

class tcs230 {
private:
	unsigned int _S0; // for frequency scaling
	unsigned int _S1; // for frequency scaling
	unsigned int _S2; // for photodiode
	unsigned int _S3; // for photodiode
	unsigned int _out; // for getting the pulse
	unsigned int _frequency; // to store the frequency

public:
    tcs230(const unsigned int S0, const unsigned int S1, const unsigned int S2, const unsigned int S3, const unsigned int out) {
		_S0 = S0; 
		_S1 = S1;
		_S2 = S2; 
		_S3 = S3; 
		_out = out;
		pinMode(_S0, OUTPUT);
		pinMode(_S1, OUTPUT);
		pinMode(_S2, OUTPUT);
		pinMode(_S3, OUTPUT);
		pinMode(out, INPUT);
        }

    void scalingdown() { 
	    digitalWrite(_S0, LOW);
		digitalWrite(_S1, LOW);
    }

	void scaling2() {
		digitalWrite(_S0, LOW);
		digitalWrite(_S1, HIGH);
	}

	void scaling20() {
		digitalWrite(_S0, HIGH);
		digitalWrite(_S1, LOW);
	}

	void scaling100() {
		digitalWrite(_S0, HIGH);
		digitalWrite(_S1, HIGH);
	}

	int readred() {
		digitalWrite(_S2, LOW);
		digitalWrite(_S3, LOW);
      	_frequency = pulseIn(_out, LOW);
	  	return _frequency;
	}

	int readblue() {
		digitalWrite(_S2, LOW);
		digitalWrite(_S3, HIGH);
      	_frequency = pulseIn(_out, LOW);
	  	return _frequency;
	}

	int readgreen() {
		digitalWrite(_S2, HIGH);
		digitalWrite(_S3, HIGH);
      	_frequency = pulseIn(_out, LOW);
	  	return _frequency;
	}

	int readclear() {
		digitalWrite(_S2, HIGH);
		digitalWrite(_S3, LOW);
      	_frequency = pulseIn(_out, LOW);
	  	return _frequency;
	}

};
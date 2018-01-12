// ultrasonic.h

// our ultrasonic sensor class

class ultrasonicsensor {
private:
	unsigned int _trigger;
    unsigned int _echo;

public:
    ultrasonicsensor(const unsigned int trigger, const unsigned int echo) {
		_trigger = trigger;
        _echo = echo;
		pinMode(_trigger, OUTPUT);
        pinMode(_echo, INPUT);
        digitalWrite(_trigger, HIGH);
	}

    int getDistance(){ 
	    long distance = 0;
	    long timeT = 0;
	    digitalWrite(_trigger, LOW); 
	    delayMicroseconds(3);
	    noInterrupts();
	    digitalWrite(_trigger, HIGH);
	    delayMicroseconds(10);
	    digitalWrite(_trigger, LOW); 
	    timeT = pulseIn(_echo, HIGH);
	    interrupts();
	    distance = (timeT / 2) * 0.03432;
	    return(distance);
    }
};
#include <Arduino.h>
#include "notes.h"
#include "clacsonListener.h"
#include "encoder.h"

#define GATE 0 // define the pin number for GATE
#define BUZZER 1

class Melody{
public:
	unsigned short length;
	int *note, *noteDuration;
	
	Melody(){}

	Melody(unsigned short length, int note[], int noteDuration[]){
		this->note = new int[length];
		this->noteDuration = new int[length];
		this->length = length;

		for(unsigned short i = 0; i < length; i++){
			this->note[i] = note[i];
			this->noteDuration[i] = noteDuration[i];
		}
	}
	
	void play(unsigned short speed, unsigned short pauseBetweenNotes){
		for (int i = 0; i < length && clacsonListener(); i++){
			tone(GATE, note[i], noteDuration[i] * speed);
			delay(pauseBetweenNotes);
			noTone(GATE);
	 	}
	}

	bool preview(unsigned short speed, unsigned short pauseBetweenNotes){
		for (int i = 0; i < length && !encoder.valueListener(); i++){
			if(encoder.clickListener())
				return true;

			tone(BUZZER, note[i], noteDuration[i] * speed);
			delay(pauseBetweenNotes);
			noTone(BUZZER);
	 	}

	 	return false;
	}
};
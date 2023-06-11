#include <Arduino.h>
#include "notes.h"
#include "clacsonListener.h"
#include "encoder.h"
#include <list>

#define GATE 0 // define the pin number for GATE
#define BUZZER 1

class Melody{
public:
	unsigned int length;
	int *note, *noteDuration;
	
	Melody(){}

	Melody(std::list<int> notes, std::list<int> notesDuration){
		length = notes.size();

		this->note = new int[length];
		this->noteDuration = new int[length];

		std::list<int>::iterator n_it = notes.begin(), nD_it = notesDuration.begin();

		for(unsigned short i = 0; i < length; ++i, ++n_it, ++nD_it){
			this->note[i] = *n_it;
			this->noteDuration[i] = *nD_it;
		}
	}
	
	void play(unsigned short speed, unsigned short pauseBetweenNotes){
		unsigned int i = 0;

		while(clacsonListener()){
			if(i < length)
				i++;
			else
				i = 0;

			tone(GATE, note[i], noteDuration[i] * speed);
			delay(pauseBetweenNotes);
			noTone(GATE);
		}
	}

	short preview(unsigned short speed, unsigned short pauseBetweenNotes){
		unsigned int i = 0;

		//Stop if clacson is pressed!!!
		while(!clacsonListener() && i < length){

			if(encoder.clickListener())// Stop if encoder confirm the melody
				return 0;

			if(encoder.valueListener())// Stop if encoder value change
				return 1;

			tone(BUZZER, note[i], noteDuration[i] * speed);
			delay(pauseBetweenNotes);
			noTone(BUZZER);

			i++;
	 	}

	 	return -1;
	}
};
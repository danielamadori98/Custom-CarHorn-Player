#include "notes.h"
#include <Arduino.h>

#define MELODY_NUMBER 10
#define GATE 0 // define the pin number for GATE


class Melody{
public:
	unsigned short length;
	int *note, *noteDuration;
	
	Melody(unsigned short length, int note[], int noteDuration[]){
		this->note = new int[length];
		this->noteDuration = new int[length];
		this->length = length;

		for(unsigned short i = 0; i < length; i++){
			this->note[i] = note[i];
			this->noteDuration[i] = noteDuration[i];
		}
	}
	Melody(){}

	void play(unsigned short speed, unsigned short pauseBetweenNotes){
		for (int i = 0; i < length; i++) {
			tone(GATE, note[i], noteDuration[i] * speed);
			delay(pauseBetweenNotes);
			noTone(GATE);
	 	}
	}
};

class Playlist{


	unsigned short pauseBetweenNotes = 0;
	double speed = 1;

public:

	Melody *melodies[];

	void init();

	void run(int actionNumber){
		if (actionNumber == 0)// Clacson normal
			digitalWrite(GATE, HIGH);

		else if(actionNumber < MELODY_NUMBER)
			melodies[actionNumber]->play(speed, pauseBetweenNotes);
		
		delay(10);
	}
};
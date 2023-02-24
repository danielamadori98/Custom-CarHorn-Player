#include "notes.h"

#define MELODY_NUMBER 10

class Playlist{
	struct Melody{
		int note[], noteDurations[];
		unsigned short length;
	};

	Melody melodies[MELODY_NUMBER];
	
	int pauseBetweenNotes = 0;

	void play(Melody &melody) {
	  for (int i = 0; i < melody.length; i++) {
		tone(GATE, melody.note[i], melody.noteDuration[i]);
		delay(pauseBetweenNotes);

		noTone(GATE);
	  }
	}


void run(int actionNumber);
	if(!clacson_listner())
		return;

	if (actionNumber == 0){// Clacson normale
		while (digitalRead(SWDX))
			digitalWrite(GATE, HIGH);
	
		digitalWrite(GATE, LOW);

	}else if(actionNumber < MELODY_NUMBER)
		play(melodies[actionNumber]);
	
	else//BL
		bl();
	
  
	delay(10);
};


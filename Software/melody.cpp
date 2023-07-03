#include "Melody.h"

Melody::Melody(String name, unsigned short length, unsigned short* notes, unsigned short* notesDuration){
	this->name = name;
	this->length = length;
	this->notes = notes;
	this->notesDuration = notesDuration;
}
	
void Melody::play(unsigned short speed, unsigned short pauseBetweenNotes){
	unsigned int i = 0;

	do{
		if(i < length)
			i++;
		else
			i = 0;

		tone(OUTPUT_CLACSON, notes[i], notesDuration[i] * speed);
		delay(pauseBetweenNotes);
		noTone(OUTPUT_CLACSON);

	}while(clacsonListener());
}

short Melody::preview(unsigned short speed, unsigned short pauseBetweenNotes){
	unsigned int i = 0;

	//Stop if clacson is pressed!!!
	while(!clacsonListener() && i < length){

		if(encoder.clickListener())// Stop if encoder confirm the melody
			return 0;

		if(encoder.valueListener())// Stop if encoder value change
			return 1;

		tone(BUZZER, notes[i], notesDuration[i] * speed);
		delay(pauseBetweenNotes);
		noTone(BUZZER);

		i++;
 	}

 	return -1;
}

String Melody::getName(void){
	return name;
}
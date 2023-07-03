#include "Melody.hpp"

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

		tone(HORN, notes[i], notesDuration[i] * speed);
		delay(pauseBetweenNotes);
		noTone(HORN);

	}while(hornButton());
}

short Melody::preview(unsigned short speed, unsigned short pauseBetweenNotes){
	unsigned int i = 0;

	//Stop if hornButton is pressed!!!
	while(!hornButton() && i < length){

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
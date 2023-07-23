#include "Melody.hpp"

Melody::Melody(String name, unsigned short totalDuration, unsigned short length, unsigned short* notes, unsigned short* notesDuration){
	this->name = name;
	this->totalDuration = totalDuration;
	this->length = length;
	this->notes = notes;
	this->notesDuration = notesDuration;
}
	
void Melody::play(unsigned short pauseBetweenNotes){
	unsigned short i = 0, duration;

	do{
		duration = totalDuration / notesDuration[i];
		tone(HORN, notes[i], duration);
		delay(pauseBetweenNotes * duration);
		noTone(HORN);
		
	}while(i++ < length);
}

short Melody::preview(unsigned short pauseBetweenNotes){
	unsigned short i = 0, duration;

	//Stop if hornButton is pressed!!!
	while(!hornButton()){
		duration = totalDuration / notesDuration[i];
		tone(BUZZER, notes[i], duration);
		delay(pauseBetweenNotes * duration);
		noTone(BUZZER);

		if(++i == length)
			break;

		if(encoder.clickListener())// Stop if encoder confirm the melody
			return 0;

		if(encoder.valueListener()){// Stop if encoder value change
			Serial.println("Cambio canzione");
			return 1;
		}
	}
	Serial.println("Fine canzone");
	return 2;
}

String Melody::getName(void){
	return name;
}
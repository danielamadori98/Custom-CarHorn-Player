#include "Display.h"

void Display::write(unsigned short digit) {
	if(digit > DIGITS_NUMBER)
		turnOff();
	else
		for (unsigned short segCount = 0; segCount < SEGMENT_NUMBER; ++segCount)
			digitalWrite(sevSeg[segCount], digits[digit][segCount]);
}

void Display::loading(unsigned short repetNumber){
	if(--repetNumber > 0)
		loading(repetNumber);

	//TODO
	//Serpentina iniziale
	/*int snake[] = {a, b, g, e, d, c, g, f};

	for(unsigned short i = 0; i < sizeof(snake) / sizeof(snake[0]); i++) {
		digitalWrite(snake[i], HIGH);
		delay(100);
		digitalWrite(snake[i], LOW);
	}
	*/	
}

void Display::setup(void){
	for(unsigned short i = 0; i < SEGMENT_NUMBER; i++)
		pinMode(sevSeg[i], OUTPUT);

	loading(3);
}


void Display::turnOff(void){
	for (unsigned short segCount = 0; segCount < SEGMENT_NUMBER; ++segCount)
		digitalWrite(sevSeg[segCount], 0);
}

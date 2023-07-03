#ifndef DISPLAY_H
#define DISPLAY_H
#pragma once

#include <Arduino.h>

class Display{
	#define SEGMENT_NUMBER 7
	#define DIGITS_NUMBER 17

	// La numerazione parte dal pin a fino alla g, dal segmento in alto e ruotando in senso orario
	int pins[SEGMENT_NUMBER] = {32, 33, 25, 26, 27, 14, 12};//TODO check orfer

	// https://www.hacktronics.com/Tutorials/arduino-and-7-segment-led.html
	byte digits[DIGITS_NUMBER][SEGMENT_NUMBER] = {
		{ 1, 1, 1, 1, 1, 1, 0 }, // = 0
		{ 0, 1, 1, 0, 0, 0, 0 }, // = 1
		{ 1, 1, 0, 1, 1, 0, 1 }, // = 2
		{ 1, 1, 1, 1, 0, 0, 1 }, // = 3
		{ 0, 1, 1, 0, 0, 1, 1 }, // = 4
		{ 1, 0, 1, 1, 0, 1, 1 }, // = 5
		{ 1, 0, 1, 1, 1, 1, 1 }, // = 6
		{ 1, 1, 1, 0, 0, 0, 0 }, // = 7
		{ 1, 1, 1, 1, 1, 1, 1 }, // = 8
		{ 1, 1, 1, 0, 0, 1, 1 }, // = 9
		{ 1, 1, 1, 0, 1, 1, 1 }, // = A
		{ 0, 0, 1, 1, 1, 1, 1 }, // = B
		{ 1, 0, 0, 1, 1, 1, 0 }, // = C
		{ 0, 1, 1, 1, 1, 0, 1 }, // = D
		{ 1, 0, 0, 1, 1, 1, 1 }, // = E
		{ 1, 0, 0, 0, 1, 1, 1 }	 // = F
	};

public:
	
	void write(unsigned short digit);

	void loading(unsigned short repetNumber);

	void setup(void);

	void turnOff(void);
};

extern 	Display display;

#endif
#ifndef DISPLAY_H
#define DISPLAY_H
#pragma once

#include <Arduino.h>

class Display{
	#define SEGMENT_NUMBER 7
	#define DIGITS_NUMBER 17

	// La numerazione parte dal pin a fino alla g, dal segmento in alto e ruotando in senso orario
	int pins[SEGMENT_NUMBER] = {32, 33, 25, 26, 27, 14, 12};//TODO check orfer
/*
	 2	7 (A)
	 3	6 (B)
	 4	4 (C)
	 5	2 (D)
	 6	1 (E)
	 7	9 (F)
	 8 	 10 (G)
	 9 	5 (DP)
*/
	// https://www.hacktronics.com/Tutorials/arduino-and-7-segment-led.html
	byte digits[DIGITS_NUMBER][SEGMENT_NUMBER] = {
		{ 0, 0, 0, 0, 0, 0, 1 }, // 0
		{ 1, 0, 0, 1, 1, 1, 1 }, // 1
		{ 0, 0, 1, 0, 0, 1, 0 }, // 2
		{ 0, 0, 0, 0, 1, 1, 0 }, // 3
		{ 1, 0, 0, 1, 1, 0, 0 }, // 4
		{ 0, 1, 0, 0, 1, 0, 0 }, // 5
		{ 0, 1, 0, 0, 0, 0, 0 }, // 6
		{ 0, 0, 0, 1, 1, 1, 1 }, // 7
		{ 0, 0, 0, 0, 0, 0, 0 }, // 8
		{ 0, 0, 0, 1, 1, 0, 0 }, // 9
		{ 0, 0, 0, 1, 0, 0, 0 }, // A
		{ 1, 1, 0, 0, 0, 0, 0 }, // B
		{ 0, 1, 1, 0, 0, 0, 1 }, // C
		{ 1, 0, 0, 0, 0, 1, 0 }, // D
		{ 0, 1, 1, 0, 0, 0, 0 }, // E
		{ 0, 1, 1, 1, 0, 0, 0 }  // F
	};

public:
	
	void write(unsigned short digit);

	void loading(unsigned short repetNumber);

	void setup(void);

	void turnOff(void);
};

extern 	Display display;

#endif
#ifndef MELODY_H
#define MELODY_H
#pragma once

#include <list>
#include "Notes.h"
#include "Encoder.h"
#include "Clacson.h"

#define OUTPUT_CLACSON 31 // define the pin number for OUTPUT_CLACSON
#define BUZZER 27

class Melody{
public:
	unsigned int length;
	int *note, *noteDuration;

	Melody(std::list<int> notes, std::list<int> notesDuration);
	
	void play(unsigned short speed, unsigned short pauseBetweenNotes);

	short preview(unsigned short speed, unsigned short pauseBetweenNotes);
};


#endif
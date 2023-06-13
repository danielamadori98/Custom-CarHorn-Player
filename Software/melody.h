#ifndef MELODY_H
#define MELODY_H
#pragma once

#include "notes.h"
#include "encoder.h"
#include "clacson.h"
#include <list>

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
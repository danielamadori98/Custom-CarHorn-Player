#ifndef MELODY_H
#define MELODY_H
#pragma once

#include "Notes.h"
#include "Encoder.h"
#include "Clacson.h"

#define OUTPUT_CLACSON 19
#define BUZZER 16

class Melody{
	unsigned short length;
	unsigned short *notes, *notesDuration;
	
	String name;

public:

	Melody(String name, unsigned short length, unsigned short* notes, unsigned short* notesDuration);
	
	void play(unsigned short speed, unsigned short pauseBetweenNotes);

	short preview(unsigned short speed, unsigned short pauseBetweenNotes);

	String getName(void);

};

#endif
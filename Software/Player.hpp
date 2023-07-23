#ifndef PLAYER_H
#define PLAYER_H
#pragma once

#include "Melody.hpp"

#define MELODY_NUMBER 10

class Player{
	unsigned short pauseBetweenNotes = 1.30;

	Melody *melodies[MELODY_NUMBER];

public:

	void setup(void);

	void play(unsigned short actionNumber);

	short preview(unsigned short actionNumber);

	Melody *getMelody(unsigned short i);
};

extern Player player;

#endif
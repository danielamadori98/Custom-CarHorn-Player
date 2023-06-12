#ifndef MENU_H
#define MENU_H
#pragma once

#include "BL.h"
#include "display.h"
#include "player.h"

extern Encoder encoder;

class Menu{
	Display display;
	Player player;
	BL bl;

	unsigned short actionNumber = 0;

	void write(unsigned short actionNumberTmp);

	short confirmChoose(void);

	void choose(void);
	
public:
	void setup(void);
	
	void run(void);
};

#endif
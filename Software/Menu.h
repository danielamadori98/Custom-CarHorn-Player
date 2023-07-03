#ifndef MENU_H
#define MENU_H
#pragma once

#include "Display.h"
#include "Player.h"

class Menu{
	unsigned short actionNumber;

	void updateDisplay(unsigned short value);

	short confirmChoose(void);

	void choose(void);

public:
	void setup(void);
	
	void choose(unsigned short melodyNumber);

	void idle(void);
};

extern Menu menu;

#endif
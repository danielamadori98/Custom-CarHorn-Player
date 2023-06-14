#ifndef MENU_H
#define MENU_H
#pragma once

#include "Bluetooth.h"
#include "Display.h"
#include "Player.h"

class Menu{
	Display display;
	Player player;
	Bluetooth bluetooth;

	unsigned short actionNumber = 0;

	void updateDisplay(unsigned short value);

	short confirmChoose(void);

	void choose(void);
	
public:
	void setup(void);
	
	void idle(void);
};

extern Menu menu;

#endif
#ifndef MENU_H
#define MENU_H
#pragma once

#include "bluetooth.h"
#include "display.h"
#include "player.h"

class Menu{
	Display display;
	Player player;
	Bluetooth bluetooth;

	unsigned short actionNumber = 0;

	void write(unsigned short actionNumberTmp);

	short confirmChoose(void);

	void choose(void);
	
public:
	void setup(void);
	
	void run(void);
};

extern Menu menu;

#endif
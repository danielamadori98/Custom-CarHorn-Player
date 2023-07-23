#ifndef MENU_H
#define MENU_H
#pragma once

#include "Display.hpp"
#include "Player.hpp"

class Menu{
	bool choseAgain = false;

	unsigned short actionNumberSelected, actionNumberSelector;//Used for encoder

	unsigned short actionNumberWebServer;

	unsigned long lastActionTime;

	void updateDisplay(unsigned short value);

	void confirmChoose(void);

	bool choose(void);

public:
	void setup(void);

	void idle(void);

	void choose(unsigned short melodyNumber){ // used by WebServer
		Serial.println(melodyNumber);

		actionNumberWebServer = melodyNumber;
	}
};

extern Menu menu;

#endif
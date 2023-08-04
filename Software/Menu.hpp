#ifndef MENU_H
#define MENU_H
#pragma once

#include "Display.hpp"
#include "Player.hpp"

#define WAIT_TIME_UNTIL_REPEAT 5 * 10000 //is in Seconds

class Menu{
	bool choseAgain = false;

	unsigned short actionNumberSelected, actionNumberSelector;//Used for encoder

	unsigned short actionNumberWebServer, waitTimeUntilRepeat;

	unsigned long lastActionTime;


	void confirmChoose(void);

	bool choose(void);

	void webServerIdle(void);

public:
	void updateDisplay(unsigned short value);
	void setup(void);

	void idle(void);

	void choose(unsigned short melodyNumber){ // used by WebServer
		actionNumberWebServer = melodyNumber;
		waitTimeUntilRepeat = 0;
	}
};

extern Menu menu;

#endif
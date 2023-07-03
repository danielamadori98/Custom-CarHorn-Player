#ifndef ENCODER_H
#define ENCODER_H
#pragma once

#include <Arduino.h>

class Encoder{
	unsigned short value = 0;
	int currentStateCLK, lastStateCLK;

public:
	void setup(void);

	unsigned int getValue(void);

	bool valueListener(void);

	bool clickListener(void);
};

extern Encoder encoder;

#endif
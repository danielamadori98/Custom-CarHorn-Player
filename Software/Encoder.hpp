#ifndef ENCODER_H
#define ENCODER_H
#pragma once

#include <Arduino.h>

#define ENCODER_CLK 23
#define ENCODER_DT 22
#define ENCODER_SW 21

#include "AiEsp32RotaryEncoder.h"


class Encoder{
unsigned short value = 0;

public:
	void setup(unsigned short maxValue);

	short getValue(void);

	bool valueListener(void);

	bool clickListener(void);
};

extern Encoder encoder;

#endif
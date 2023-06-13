#include <Arduino.h>
#include "encoder.h"

#define ENCODER_CLK 23
#define ENCODER_DT 22
#define ENCODER_SW 21

Encoder encoder;

void Encoder::setup() {
	pinMode(ENCODER_CLK, INPUT);
	pinMode(ENCODER_DT, INPUT);
	pinMode(ENCODER_SW, INPUT_PULLUP);

	lastStateCLK = digitalRead(ENCODER_CLK);
}

unsigned int Encoder::getValue(void){
	return value;
}

bool Encoder::valueListener(void){
	currentStateCLK = digitalRead(ENCODER_CLK);

	// If last and current state of CLK are different, then pulse occurred
	// React to only 1 state change to avoid double count
	bool result = currentStateCLK != lastStateCLK && currentStateCLK == 1;
	lastStateCLK = currentStateCLK;// Remember last CLK state

	if(!result)
		return false;

	value += (digitalRead(ENCODER_DT) != currentStateCLK)? -1 : +1;
	
	return true;
}

bool Encoder::clickListener(void){
	for(unsigned short i = 0; i < 3; i++){
		if(digitalRead(ENCODER_SW) != LOW)
			return false;
		delay(1);
	}

	return true;		
}
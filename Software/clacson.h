#ifndef CLACSON_H
#define CLACSON_H
#pragma once

#include <Arduino.h>

#define INPUT_CLACSON 17

inline bool clacsonListener(void){
	for(unsigned short i = 0; i < 5; i++){
		if(digitalRead(INPUT_CLACSON) == HIGH)
			return true;

		delay(1);
	}

	return false;
}

#endif
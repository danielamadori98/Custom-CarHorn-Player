#ifndef HORNBUTTON_h
#define HORNBUTTON_h
#pragma once

#include <Arduino.h>

#define HORN_BUTTON 17

inline bool hornButton(void){
	for(unsigned short i = 0; i < 5; i++){
		if(digitalRead(HORN_BUTTON) == HIGH)
			return true;

		delay(1);
	}

	return false;
}

#endif
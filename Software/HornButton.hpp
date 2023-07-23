#ifndef HORNBUTTON_h
#define HORNBUTTON_h
#pragma once

#include <Arduino.h>

#define HORN_BUTTON 17

inline bool hornButton(void){
	unsigned char result = 0;

	for(unsigned short i = 0; i < 10; i++)
		if(digitalRead(HORN_BUTTON) == HIGH)
			if(result++ > 3)
				return true;
	
	return false;
}

#endif
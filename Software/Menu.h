#include <Arduino.h>

#include "BL.h"
#include "display.h"
#include "playlist.h"

#define MELODY_NUMBER 10 // define the number of melodies in the playlist

class Menu{
	Display display;
	Playlist playlist;

	unsigned short actionNumber = 0;

	unsigned short get(void){
		return 0;
	};
	
public:
	void init(){
		pinMode(GATE, OUTPUT);
		digitalWrite(GATE, LOW);

		display.init();
		playlist.init();
	}

	void choose(void){
		unsigned short actionNumber = get() % MELODY_NUMBER + 2;//Plus normal clason and BL

		if(this->actionNumber == actionNumber)
			return;

		this->actionNumber = actionNumber;

		if (actionNumber != 0)
		  	display.write(actionNumber);
	}

	void run(void){
		if(actionNumber < MELODY_NUMBER)
			playlist.run(actionNumber);
		else
			bl();
	}
};
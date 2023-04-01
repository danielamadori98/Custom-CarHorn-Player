#include <Arduino.h>

#include "BL.h"
#include "display.h"
#include "playlist.h"


#define MELODY_NUMBER 10 // define the number of melodies in the playlist

class Menu{
	Display display;
	Player player;
	BL bl;

	unsigned short actionNumber = 0;
	
public:
	void init(){
		pinMode(GATE, OUTPUT);
		digitalWrite(GATE, LOW);

		display.init();
		player.init();
	}

	void choose(void){
		if(!encoder.valueListener())
			return;

		unsigned short actionNumberTmp = encoder.getValue() % MELODY_NUMBER + 2;//Plus normal clason and BL

		if (actionNumberTmp == 0)
			return;

		display.write(actionNumberTmp);

		if(actionNumberTmp <= MELODY_NUMBER && player.preview(actionNumberTmp))
			actionNumber = actionNumberTmp;
		else
			bl.preview();
	}

	void run(void){
		if(!clacsonListener())
			return;

		if(actionNumber < MELODY_NUMBER)
			player.play(actionNumber);
		else
			bl.run();
	}
};
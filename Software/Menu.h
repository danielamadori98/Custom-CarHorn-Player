#include <Arduino.h>

#include "BL.h"
#include "display.h"
#include "player.h"

class Menu{
	Display display;
	Player player;
	BL bl;

	unsigned short actionNumber = 0;

	void write(unsigned short actionNumberTmp){
		if(actionNumberTmp < MELODY_NUMBER)
			display.write(actionNumberTmp);

		else if(actionNumberTmp == MELODY_NUMBER)
			display.write(11);//B for BL

		else
			display.turnOff();//Off if normal clacson is selected
	}

	short confirmChoose(){
		unsigned short waitingTime = 5 * 1000; //Seconds
		
		//Stop if clacson is pressed!!!
		while(!clacsonListener() && --waitingTime > 0){

			if(encoder.clickListener())//Stop if encoder confirm the choose
				return 0;

			if(encoder.valueListener())// Stop if encoder value change
				return 1;

			delay(1);
		}

		return -1;
	}

	void choose(void){
		unsigned short actionNumberTmp = encoder.getValue() % MELODY_NUMBER + 2;//Plus BL and normal clason

		display.write(actionNumberTmp);

		short result = actionNumberTmp < MELODY_NUMBER?
			player.preview(actionNumberTmp) : confirmChoose();

		if(result == 0)
			actionNumber = actionNumberTmp;
		else if(result == 1)
			choose();
		else
			display.write(actionNumber);
	}

	
public:
	void init(void){
		pinMode(GATE, OUTPUT);
		digitalWrite(GATE, LOW);

		display.init();
		player.init();
	}

	
	void run(void){
		if(clacsonListener()){
			if(actionNumber == MELODY_NUMBER + 1)
				do
					digitalWrite(GATE, HIGH);// Clacson normal
				while(clacsonListener());
			
			else if(actionNumber < MELODY_NUMBER)
				player.play(actionNumber);
			else
				bl.run();

		}else{
			if(encoder.valueListener())
				choose();
			else
				delay(1);
		}
	}
};
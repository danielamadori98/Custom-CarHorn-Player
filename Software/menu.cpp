#include <Arduino.h>
#include "menu.h"

Menu menu;

void Menu::write(unsigned short actionNumberTmp){
	if(actionNumberTmp < MELODY_NUMBER)
		display.write(actionNumberTmp);

	else if(actionNumberTmp == MELODY_NUMBER)
		display.write(11);//B for BL

	else
		display.turnOff();//Off if normal clacson is selected
}

short Menu::confirmChoose(){
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

void Menu::choose(void){
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

void Menu::setup(void){
	pinMode(OUTPUT_CLACSON, OUTPUT);
	digitalWrite(OUTPUT_CLACSON, LOW);

	display.setup();
	player.setup();
}

	
void Menu::run(void){
	if(clacsonListener()){
		if(actionNumber >= MELODY_NUMBER + 1)
			digitalWrite(OUTPUT_CLACSON, HIGH);//Enable normal Clacson 			
		else if(actionNumber == MELODY_NUMBER)
			bluetooth.run();
		else
			player.play(actionNumber);

	}else{
		digitalWrite(OUTPUT_CLACSON, LOW);//Disable normal Clacson

		if(encoder.valueListener())
			choose();
		else
			delay(1);
	}
}
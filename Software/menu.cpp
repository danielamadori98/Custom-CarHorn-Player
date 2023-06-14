#include "Menu.h"

Menu menu;

void Menu::updateDisplay(unsigned short value){
	if(value < MELODY_NUMBER)
		display.write(value);

	else if(value == MELODY_NUMBER)
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

	updateDisplay(actionNumberTmp);

	short result = actionNumberTmp < MELODY_NUMBER?
		player.preview(actionNumberTmp) : confirmChoose();

	if(result == 0) //Confirm Choose (Melody, BL, Clacson)
		actionNumber = actionNumberTmp;
	else if(result == 1) //The encoder value changed
		choose();
	else
		updateDisplay(actionNumber);
}

void Menu::setup(void){
	pinMode(OUTPUT_CLACSON, OUTPUT);
	digitalWrite(OUTPUT_CLACSON, LOW);

	display.setup();
	player.setup();
}

	
void Menu::idle(void){
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
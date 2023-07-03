#include "Menu.h"

Menu menu;

void Menu::updateDisplay(unsigned short value){
	if(value < MELODY_NUMBER)
		display.write(value);
	else
		display.turnOff();//Off if normal horn is selected
}

short Menu::confirmChoose(){
	unsigned short waitingTime = 5 * 1000; //Seconds
		
	//Stop if hornButton is pressed!!!
	while(!hornButton() && --waitingTime > 0){
		if(encoder.clickListener())//Stop if encoder confirm the choose
			return 0;

		if(encoder.valueListener())// Stop if encoder value change
			return 1;

		delay(1);
	}

	return -1;
}

void Menu::choose(void){
	unsigned short actionNumberTmp = encoder.getValue() % MELODY_NUMBER + 1;//Plus normal clason

	updateDisplay(actionNumberTmp);

	short result = actionNumberTmp < MELODY_NUMBER?
		player.preview(actionNumberTmp) : confirmChoose();

	if(result == 0) //Confirm Choose (Melody, Clacson)
		actionNumber = actionNumberTmp;
	else if(result == 1) //The encoder value changed
		choose();
	else
		updateDisplay(actionNumber);
}

void Menu::choose(unsigned short melodyNumber){
	updateDisplay(melodyNumber);
	player.play(melodyNumber);
	updateDisplay(actionNumber);
}

void Menu::setup(void){
	pinMode(HORN, OUTPUT);
	digitalWrite(HORN, LOW);

	actionNumber = MELODY_NUMBER + 1;
	
	player.setup();
	display.setup();

	updateDisplay(actionNumber);
}

	
void Menu::idle(void){
	if(hornButton()){
		if(actionNumber >= MELODY_NUMBER)
			digitalWrite(HORN, HIGH);//Enable normal Clacson
		else
			player.play(actionNumber);

	}else{
		digitalWrite(HORN, LOW);//Disable normal Clacson

		if(encoder.valueListener())
			choose();
		else
			delay(1);
	}
}
#include "Menu.hpp"

Menu menu;

void Menu::setup(void){
	pinMode(HORN, OUTPUT);
	digitalWrite(HORN, LOW);

	actionNumberSelected = actionNumberSelector = MELODY_NUMBER + 1;
	actionNumberWebServer = 0;

	lastActionTime = millis();
	
	player.setup();
	display.setup();

	updateDisplay(actionNumberSelected);
}

void Menu::updateDisplay(unsigned short value){
	if(value < MELODY_NUMBER)
		display.write(value);
	else
		display.turnOff();//Off if normal horn is selected
}

void Menu::confirmChoose(){
	if(actionNumberSelector == actionNumberSelected)
		return;

	if(millis() - lastActionTime > 5 * 1000){// 5 Seconds
		updateDisplay(actionNumberSelected);
		actionNumberSelected = actionNumberSelector;
		Serial.println("confirm: time is over (not confirmed)");
		return;
	}

	if(encoder.clickListener()){
		actionNumberSelected = actionNumberSelector;
		Serial.println("confirm: Confirmed");
	}
}

bool Menu::choose(void){
	unsigned short tmp = encoder.getValue();

	if(actionNumberSelector == tmp || actionNumberSelected == tmp)
		return false;

	actionNumberSelector = tmp;
	lastActionTime = millis();

	updateDisplay(actionNumberSelector);

	if(actionNumberSelector == MELODY_NUMBER)//If horn is selected
		return false;

	short result = player.preview(actionNumberSelector);
	
	if(result == 1)//if the value is changed again
		return true;

	if(result == 0) //Confirm Choose (Melody, Clacson)
		actionNumberSelected = actionNumberSelector;

	return false;
}


void Menu::idle(void){
	if(hornButton()){
		Serial.print("beep:");
		Serial.println(actionNumberSelected);

		if(actionNumberSelected >= MELODY_NUMBER)
			digitalWrite(HORN, HIGH);//Enable normal horn
		else
			player.play(actionNumberSelected);
		
	}else
		digitalWrite(HORN, LOW);//Disable normal horn

	//Encoder part
	if(encoder.valueListener() || choseAgain)
		choseAgain = choose();

	confirmChoose();

	//WebServer part
	if (actionNumberWebServer == 1)
		digitalWrite(HORN, HIGH);//Enable normal horn
	else if(actionNumberWebServer == 0){
		//stop(); TODO
		digitalWrite(HORN, LOW);//Disable normal horn
		actionNumberWebServer = MELODY_NUMBER + 2;

	} else if(actionNumberWebServer < MELODY_NUMBER + 2)//Plus normal horn and stop function
		player.play(actionNumberWebServer - 2);
}
#include "Menu.h"

Menu menu;

void setup() {
	menu.init();
}

bool clacson_listner(void){
	return true; //return digitalRead("1");
	//digitalWrite(GATE, LOW);
}

void loop() {
	menu.choose();

	if(clacson_listner())
		menu.run();
}
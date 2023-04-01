#include "Menu.h"

Menu menu;

void setup() {
	menu.init();
}


void loop() {
	menu.choose();

	menu.run();		
}
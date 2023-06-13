#include "menu.h"

void setup() {
	menu.setup();
	encoder.setup();
}

void loop() {
	menu.run();		
}
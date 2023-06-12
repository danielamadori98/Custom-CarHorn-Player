#include "menu.h"

Menu menu;
extern Encoder encoder;

void setup() {
	menu.setup();
	encoder.setup();
}

void loop() {
	menu.run();		
}
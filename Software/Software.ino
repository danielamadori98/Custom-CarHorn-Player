#include "WiFiManager.hpp"

void setup() {
	EEPROM.begin(512);
	Serial.begin(115200);

	encoder.setup();
	menu.setup();

	httpServer.begin();
	wiFiManager.begin();
}

void loop() {
	if(httpServer.reboot())
		ESP.restart();

	menu.idle();	
	wiFiManager.idle();	
}
#include "WiFiManager.hpp"

void setup() {
	EEPROM.begin(512);
	Serial.begin(115200);

	encoder.setup(MELODY_NUMBER + 1);
	menu.setup();

	wiFiManager.begin();
	httpServer.begin();//Must be preceded by by wifi.begin()
}

void loop() {
	if(httpServer.reboot())
		ESP.restart();

	menu.idle();	
	wiFiManager.idle();	
}
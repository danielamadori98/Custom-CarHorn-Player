#include "Settings.hpp"

Settings settings;

void Settings::load(void){
	EEPROM.get(ssidLenAdr, ssidLen);

	if(ssidLen > SIZE) {
		reset();
		return;
	}
	EEPROM.get(passwordLenAdr, passwordLen);

	if(passwordLen > SIZE) {
		reset();
		return;
	}

	for(uint8_t i = 0; i < ssidLen; i++)
		EEPROM.get(ssidAdr + i, ssid[i]);
	
	for(uint8_t i = 0; i < passwordLen; i++)
		EEPROM.get(passwordAdr + i, password[i]);
}
	
void Settings::save(void){
	EEPROM.put(ssidLenAdr, ssidLen);
	for(uint8_t i = 0; i < ssidLen; i++)
		EEPROM.put(ssidAdr + i, ssid[i]);
	 
	EEPROM.put(passwordLenAdr, passwordLen);
	for(uint8_t i = 0; i < passwordLen; i++)
		EEPROM.put(passwordAdr + i, password[i]);
			
	EEPROM.commit();
}
	
void Settings::reset(void){
	String _ssid = ssid;
	_ssid.toCharArray(ssid, SIZE);
	ssidLen = _ssid.length();

	String _pswd = password;
	_pswd.toCharArray(password, SIZE);
	passwordLen = _pswd.length();
		
	save();
}
	
void Settings::print(void){
	Serial.println("\nSettings:");
	Serial.println("SSID = "+(String)ssid);
	Serial.println("Password = " + (String)password);
}

Settings::Settings(void){
	reset();
	load();
}

const char* Settings::getSSID(void) {
	if(defaultSettings())
		return ssid;

	return HOSTNAME;
}

const char* Settings::getPassword(void) {
	if(defaultSettings())
		return password;

	return RECOVERY_PASSWORD;
}

bool Settings::defaultSettings(void){
	return ssidLen > 0 && passwordLen >= 8;
}

void Settings::setSSID(const char* newSSID) {
	strncpy(ssid, newSSID, sizeof(ssid) - 1);
	ssid[sizeof(ssid) - 1] = '\0'; // Ensure null-termination
	ssidLen = strlen(ssid);
}

void Settings::setPassword(const char* newPassword) {
	strncpy(password, newPassword, sizeof(password) - 1);
	password[sizeof(password) - 1] = '\0'; // Ensure null-termination
	passwordLen = strlen(password);
}

void Settings::set(const char* newSSID, const char* newPassword){
	setSSID(newSSID);
	setPassword(newPassword);

	save();
	load();//To be sure they are written
}

#ifndef Settings_hpp
#define Settings_hpp
#pragma once

#include "Arduino.h"
#include <EEPROM.h>

#define HOSTNAME "Car-Horn"
#define RECOVERY_PASSWORD "password"

//Memory Addres
#define ssidLenAdr 0
#define ssidAdr 1
#define passwordLenAdr 33
#define passwordAdr 34
#define FREESPACE 66


class Settings{
private:
	#define SIZE 32

	uint8_t ssidLen;
	char ssid[SIZE];

	uint8_t passwordLen;
	char password[SIZE];

	void setSSID(const char* newSSID);

	void setPassword(const char* newPassword);

	void save(void);

public:

	bool defaultSettings(void);

	void load(void);
	
	void reset(void);
	
	void print(void);

	Settings(void);

	const char* getSSID(void);

	const char* getPassword(void);

	void set(const char* newSSID, const char* newPassword);

};

extern Settings settings;

#endif
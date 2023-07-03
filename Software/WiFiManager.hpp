#ifndef WiFiManager_hpp
#define WiFiManager_hpp
#pragma once

#include "WebServer.hpp"

#include <WiFi.h>//ESP8266WiFi
#include <DNSServer.h>

extern DNSServer dnsServer;// port 53

class WiFiManager{
public:

	void begin(void);

	void idle(void);

};

extern WiFiManager wiFiManager;

#endif

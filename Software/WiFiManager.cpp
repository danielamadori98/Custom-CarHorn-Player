#include "WiFiManager.hpp"

WiFiManager wiFiManager;

DNSServer dnsServer;// port 53

void WiFiManager::begin(void){
	WiFi.mode(WIFI_STA);
	WiFi.softAP(settings.getSSID(), settings.getPassword());
	WiFi.hostname(HOSTNAME);

	dnsServer.setErrorReplyCode(DNSReplyCode::NoError);
	dnsServer.start(53, "*", IPAddress(192, 168, 4, 1));
}

void WiFiManager::idle(void){
	dnsServer.processNextRequest();
}

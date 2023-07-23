#include "WebServer.hpp"

WebServer httpServer(80);

void WebServer::sendToIndex(AsyncWebServerRequest *request){
	AsyncWebServerResponse *response = request->beginResponse_P(200, "text/html", data_indexHTML, sizeof(data_indexHTML));
	//request->beginResponse(302, "text/plain", "");
	response->addHeader("Location","/");
	request->send(response);
}
	
void WebServer::begin(void){
	server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
		request->redirect("/index.html");
		//request->send(request->beginResponse_P(200, "text/html", data_indexHTML, sizeof(data_indexHTML)));
	});

	server.on("/index.html", HTTP_GET, [this](AsyncWebServerRequest *request) {
		sendToIndex(request);
	});

	server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request) {
		request->send(request->beginResponse_P(200, "text/css", data_styleCSS, sizeof(data_styleCSS)));
	});

	server.on("/normalize.css", HTTP_GET, [](AsyncWebServerRequest *request) {
		request->send(request->beginResponse_P(200, "text/css", data_nomalizeCSS, sizeof(data_nomalizeCSS)));
	});

	server.on("/skeleton.css", HTTP_GET, [](AsyncWebServerRequest *request) {
		request->send(request->beginResponse_P(200, "text/css", data_skeletonCSS, sizeof(data_skeletonCSS)));
	});

	server.on("/functions.js", HTTP_GET, [](AsyncWebServerRequest *request) {
		request->send(request->beginResponse_P(200, "text/javascript", data_functionsJS, sizeof(data_functionsJS)));
	});

	server.on("/settings.html", HTTP_GET, [](AsyncWebServerRequest *request) {
		request->send(request->beginResponse_P(200, "text/html", data_settings, sizeof(data_settings)));
	});

	server.on("/settings.html", HTTP_POST, [this](AsyncWebServerRequest *request) {
		String ssid = settings.getSSID(), password = settings.getPassword();

		if(request->hasArg("ssid")) {
			ssid = request->arg("ssid");
			Serial.println("new SSID = '" + ssid + "'");
		}
		if(request->hasArg("pswd")) {
			password = request->arg("pswd");
			Serial.println("new password = '" + password + "'");
		}
			
		settings.set(ssid.c_str(), password.c_str());
		settings.print();

		request->send(request->beginResponse_P(200, "text/html", data_indexHTML, sizeof(data_indexHTML)));
	});
	
	server.on("/playlist.json", HTTP_GET, [](AsyncWebServerRequest *request) {
		String output = "{\"list\":[ \"Horn\",";
				
		for(unsigned short i = 0; i < MELODY_NUMBER - 1; i++)
			output += "\"" + player.getMelody(i)->getName() + "\",";

		output += "\"" + player.getMelody(MELODY_NUMBER - 1)->getName() + "\"]}";

		request->send(200, "text/json", output);
	});

	server.on("/play", HTTP_POST, [](AsyncWebServerRequest *request) {
		int melodyNumber = -1;

		if(request->hasArg("number"))
			melodyNumber = request->arg("number").toInt();
		
		if(melodyNumber < 0 || melodyNumber > MELODY_NUMBER + 1)//Plus normal horn
			request->send(200, "text/plain", "false");
		else{
			request->send(200, "text/plain", "true");
			
			menu.choose((unsigned short)melodyNumber);			
		}
	});

	server.on("/settings.json", HTTP_GET, [this](AsyncWebServerRequest *request) {
		String output = "{";
		output += "\"ssid\":\"" + String(settings.getSSID()) + "\",";
		output += "\"password\":\"" + String(settings.getPassword()) + "\"";
		output += "}";
		request->send(200, "text/json", output);
	});
		
	server.on("/upload", HTTP_POST, [this](AsyncWebServerRequest *request){
		sendToIndex(request);
		}, [](AsyncWebServerRequest *request, String filename, size_t index, uint8_t *data, size_t len, bool final){
			File f;

			if(!filename.startsWith("/"))
				filename = "/" + filename;

			if(!index)
				f = SPIFFS.open(filename, "w"); //create or trunicate file
			else
				f = SPIFFS.open(filename, "a"); //append to file (for chunked upload)

			f.write(data, len);
	
			if(final)
				f.close();
		}
	);

	// ===== Captive Portal ===== //
	//ANDROID   http://connectivitycheck.gstatic.com/generate_204
	server.on("/generate_204", HTTP_GET, [this](AsyncWebServerRequest *request){
		sendToIndex(request);
	});
	//WIN10     http://www.msftconnecttest.com/redirect
	server.on("/redirect", HTTP_GET, [this](AsyncWebServerRequest *request){
		sendToIndex(request);
	});

	server.onNotFound([this](AsyncWebServerRequest *request){
		request->send(request->beginResponse_P(404, "text/html", data_error404, sizeof(data_error404)));
	});

	server.on("/restart", HTTP_GET, [this](AsyncWebServerRequest *request) { ESP.restart();	});

	server.on("/reset", HTTP_GET, [this](AsyncWebServerRequest *request) {
		settings.reset();
		request->send(200, "text/plain", "true");
		sendToIndex(request);
	});

	server.on("/update", HTTP_GET, [](AsyncWebServerRequest *request) {
		AsyncWebServerResponse *response = request->beginResponse(302, "text/plain", "");
		response->addHeader("Location", "/index.html");
		request->send(response);
	});

	server.on("/update", HTTP_POST,
		[this](AsyncWebServerRequest *request){
			shouldReboot = !Update.hasError();

			AsyncWebServerResponse *response;
			if(shouldReboot)//if okay
				response = request->beginResponse(200, "text/html", "<!Doctype html><html><head><meta charset='utf-8'><title>" + String(HOSTNAME) + "</title><meta http-equiv='refresh' content='10;url=http://" + String(HOSTNAME) + ".local/' /></head><body><h1 align='center'>Upload done</h1><br><p align='center'>The device is rebooting, please wait 10 seconds, you will be redirected to <a href='http://" + String(HOSTNAME) + ".local/'>index</a></p></body></html>");
			else
				response = request->beginResponse(200, "text/html", "<!Doctype html><html><head><meta charset='utf-8'><meta name='viewport' content='width=device-width, initial-scale=0.8'><title>" + String(HOSTNAME) + "</title></head><body><h1 align='center''>Upload failed</h1><br><p align='center'>Something went wrong, you need to flash it manually</p></body></html>");
			response->addHeader("Connection", "close");
			request->send(response);

		},
		[](AsyncWebServerRequest *request, String filename, size_t index, uint8_t *data, size_t len, bool final){
			if(!index){
				Serial.printf("Update Start: %s\n", filename.c_str());
				//Update.runAsync(true); //TODO fix (is different for esp32 and esp8266)
					
				if(!Update.begin((ESP.getFreeSketchSpace() - 0x1000) & 0xFFFFF000))
					Update.printError(Serial);
					
			}
			if(!Update.hasError() && Update.write(data, len) != len)
				Update.printError(Serial);
					
			if(final){
				if(Update.end(true))
					Serial.printf("Update Success: %uB\n", index+len);
				else
					Update.printError(Serial);
			}

		}
	);


	server.begin();
	MDNS.begin(HOSTNAME);
	MDNS.addService("http", "tcp", port);
}

bool WebServer::reboot(void){
	return shouldReboot;
}

WebServer::WebServer(uint16_t port) : server(port) {
	this->port = port;
	shouldReboot = false;
}

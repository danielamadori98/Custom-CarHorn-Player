#include "display.h"
#include "playlist.h"

Menu menu;
Playlist playlist;

void setup() {
  pinMode(GATE, OUTPUT);
  digitalWrite(GATE, LOW);
  pinMode(SWDX, INPUT);
  pinMode(SWSX, INPUT);
  display.init();
}

bool clacson_listner(){
  return digitalRead(SWDX);
}

void loop() {
  menu.chose();

  if(clacson_listner())
	menu.run();
}

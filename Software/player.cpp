#include "Player.h"

unsigned short melody0[] = {NOTE_G5, NOTE_F5, NOTE_E5, NOTE_F5};
unsigned short melodyDuration0[] = {8,8,8,8};

unsigned short melody1[] = {NOTE_E5, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_A4, NOTE_C5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_B4, 0, NOTE_C5,NOTE_D5, NOTE_E5, NOTE_C5, NOTE_A4, NOTE_A4};
unsigned short melodyDuration1[] = {4,8,8,4,8,8,4,8,8,4,8,8,4,8,8,4,4,4,4,2};

unsigned short melody2[] = {NOTE_G5, NOTE_E5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_E5};
unsigned short melodyDuration2[] = {8, 8, 4, 4, 8, 8, 8, 8, 4, 4, 4, 4};

unsigned short melody3[] = {NOTE_F5, NOTE_F5, NOTE_GS5, NOTE_F5, NOTE_DS5, NOTE_CS5, NOTE_C5};
unsigned short melodyDuration3[] = {6, 16, 12, 12, 16, 4, 4};

unsigned short melody4[] = {NOTE_C5, NOTE_F5, NOTE_F5, NOTE_A5, NOTE_F5, NOTE_F5, NOTE_A5, NOTE_G5, NOTE_A5, NOTE_F5};
unsigned short melodyDuration4[] = {8, 8, 4, 8, 8, 4, 8, 3, 8, 3};

unsigned short melody5[] = {NOTE_A5, NOTE_F5, NOTE_A5, NOTE_F5, NOTE_A5, NOTE_F5, NOTE_A5, NOTE_F5, NOTE_A5, NOTE_G5, NOTE_G5, NOTE_A5, NOTE_AS5, NOTE_AS5, NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_A5, NOTE_F5, NOTE_F5, NOTE_A5, NOTE_G5, NOTE_C5, NOTE_E5, NOTE_G5, NOTE_F5};
unsigned short melodyDuration5[] = {8, 4, 8, 4, 8, 8, 8, 8, 8, 4, 16, 16, 8, 4, 16, 16, 16, 8, 4, 16, 16, 8, 8, 8, 8, 4};

unsigned short melody6[] = {NOTE_G5, NOTE_G5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_B5, NOTE_C6};
unsigned short melodyDuration6[] = {8, 16, 8, 8, 4, 8, 8};

unsigned short melody7[] = {NOTE_G5, NOTE_G5, NOTE_E5, NOTE_A5, NOTE_G5, NOTE_G5, NOTE_E5};
unsigned short melodyDuration7[] = {8, 8, 8, 8, 8, 8, 4};

unsigned short melody8[] = {NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_CS4, NOTE_CS4, NOTE_CS4, NOTE_CS4, NOTE_CS4, NOTE_CS4, NOTE_CS4, NOTE_CS4};
unsigned short melodyDuration8[] = {16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16};

unsigned short melody9[] = {NOTE_A6};
unsigned short melodyDuration9[] = {1};


Player player;

void Player::play(unsigned short actionNumber){
	melodies[actionNumber % MELODY_NUMBER]->play(speed, pauseBetweenNotes);
}

bool Player::preview(unsigned short actionNumber){
	return melodies[actionNumber % MELODY_NUMBER]->preview(speed, pauseBetweenNotes);
}

Melody* Player::getMelody(unsigned short i){
	if(i >= MELODY_NUMBER)
		i = MELODY_NUMBER-1;
	
	return melodies[i];
}

void Player::setup(void){
	melodies[0] = new Melody("Clacson Corriera", sizeof(unsigned short)/sizeof(melody0), melody0, melodyDuration0);
		
	melodies[1] = new Melody("Tetris", sizeof(unsigned short)/sizeof(melody1), melody1, melodyDuration1);
	
	melodies[2] = new Melody("Hazard (Dixie)", sizeof(unsigned short)/sizeof(melody2), melody2, melodyDuration2);
	
	melodies[3] = new Melody("Seven Nation Army", sizeof(unsigned short)/sizeof(melody3), melody3, melodyDuration3);
	
	melodies[4] = new Melody("Campioni del mondo", sizeof(unsigned short)/sizeof(melody4), melody4, melodyDuration4);

	melodies[5] = new Melody("Bevo Bevo", sizeof(unsigned short)/sizeof(melody5), melody5, melodyDuration5);
	
	melodies[6] = new Melody("Maza la vecia", sizeof(unsigned short)/sizeof(melody6), melody6, melodyDuration6);
	
	melodies[7] = new Melody("Gne gne gne gne gne gne gnee", sizeof(unsigned short)/sizeof(melody7), melody7, melodyDuration7);
	
	melodies[8] = new Melody("Koala", sizeof(unsigned short)/sizeof(melody8), melody8, melodyDuration8);
	
	melodies[9] = new Melody("Rumore", sizeof(unsigned short)/sizeof(melody9), melody9, melodyDuration9);
}
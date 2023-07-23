#include "Player.hpp"

unsigned short melody0[4] = {NOTE_G5, NOTE_F5, NOTE_E5, NOTE_F5};
unsigned short melodyDuration0[4] = {8,8,8,8};

unsigned short melody1[20] = {NOTE_E5, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_A4, NOTE_C5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_B4, 0, NOTE_C5,NOTE_D5, NOTE_E5, NOTE_C5, NOTE_A4, NOTE_A4};
unsigned short melodyDuration1[20] = {4,8,8,4,8,8,4,8,8,4,8,8,4,8,8,4,4,4,4,2};

unsigned short melody2[12] = {NOTE_G5, NOTE_E5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_E5};
unsigned short melodyDuration2[12] = {8, 8, 4, 4, 8, 8, 8, 8, 4, 4, 4, 4};

unsigned short melody3[7] = {NOTE_F5, NOTE_F5, NOTE_GS5, NOTE_F5, NOTE_DS5, NOTE_CS5, NOTE_C5};
unsigned short melodyDuration3[7] = {6, 16, 12, 12, 16, 4, 4};

unsigned short melody4[10] = {NOTE_C5, NOTE_F5, NOTE_F5, NOTE_A5, NOTE_F5, NOTE_F5, NOTE_A5, NOTE_G5, NOTE_A5, NOTE_F5};
unsigned short melodyDuration4[10] = {8, 8, 4, 8, 8, 4, 8, 3, 8, 3};

unsigned short melody5[26] = {NOTE_A5, NOTE_F5, NOTE_A5, NOTE_F5, NOTE_A5, NOTE_F5, NOTE_A5, NOTE_F5, NOTE_A5, NOTE_G5, NOTE_G5, NOTE_A5, NOTE_AS5, NOTE_AS5, NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_A5, NOTE_F5, NOTE_F5, NOTE_A5, NOTE_G5, NOTE_C5, NOTE_E5, NOTE_G5, NOTE_F5};
unsigned short melodyDuration5[26] = {8, 4, 8, 4, 8, 8, 8, 8, 8, 4, 16, 16, 8, 4, 16, 16, 16, 8, 4, 16, 16, 8, 8, 8, 8, 4};

unsigned short melody6[7] = {NOTE_G5, NOTE_G5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_B5, NOTE_C6};
unsigned short melodyDuration6[7] = {8, 16, 8, 8, 4, 8, 8};

unsigned short melody7[7] = {NOTE_G5, NOTE_G5, NOTE_E5, NOTE_A5, NOTE_G5, NOTE_G5, NOTE_E5};
unsigned short melodyDuration7[7] = {8, 8, 8, 8, 8, 8, 4};

unsigned short melody8[32] = {NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_CS4, NOTE_CS4, NOTE_CS4, NOTE_CS4, NOTE_CS4, NOTE_CS4, NOTE_CS4, NOTE_CS4};
unsigned short melodyDuration8[32] = {16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16};

unsigned short melody9[1] = {NOTE_A6};
unsigned short melodyDuration9[1] = {1};


Player player;

void Player::play(unsigned short actionNumber){
	melodies[actionNumber % MELODY_NUMBER]->play(pauseBetweenNotes);
}

short Player::preview(unsigned short actionNumber){
	return melodies[actionNumber % MELODY_NUMBER]->preview(pauseBetweenNotes);
}

Melody* Player::getMelody(unsigned short i){
	if(i >= MELODY_NUMBER)
		i = MELODY_NUMBER-1;
	
	return melodies[i];
}

void Player::setup(void){
	//1.30
	melodies[0] = new Melody("Clacson Corriera", 1000, 4, melody0, melodyDuration0);
	//1.30 
	melodies[1] = new Melody("Tetris", 1000, 20, melody1, melodyDuration1);
	//800, 1.30
	melodies[2] = new Melody("Hazard (Dixie)", 800, 12, melody2, melodyDuration2);
	//3200, 1.20
	melodies[3] = new Melody("Seven Nation Army", 3200, 7, melody3, melodyDuration3);
	//2400, 1.30
	melodies[4] = new Melody("Campioni del mondo", 2400, 10, melody4, melodyDuration4);
	//2400, 1.20
	melodies[5] = new Melody("Bevo Bevo", 2400, 26, melody5, melodyDuration5);
	//1400, 1.30
	melodies[6] = new Melody("Maza la vecia", 1400, 7, melody6, melodyDuration6);
	//1000, 1.30
	melodies[7] = new Melody("Gne gne gne", 1000, 7, melody7, melodyDuration7);
	//800, 1.30
	melodies[8] = new Melody("Koala", 800, 32, melody8, melodyDuration8);
	//6000, 1.30
	melodies[9] = new Melody("Rumore", 50, 1, melody9, melodyDuration9);
}
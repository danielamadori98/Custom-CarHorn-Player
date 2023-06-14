#include "Player.h"

void Player::play(unsigned short actionNumber){
	if(actionNumber < MELODY_NUMBER)
		melodies[actionNumber]->play(speed, pauseBetweenNotes);
}

bool Player::preview(unsigned short actionNumber){
	if(actionNumber > MELODY_NUMBER)
		return false;

	return melodies[actionNumber]->preview(speed, pauseBetweenNotes);
}

void Player::setup(void){
	melodies[0] = new Melody(
		{NOTE_G5, NOTE_F5, NOTE_E5, NOTE_F5},
		{8,8,8,8});

	//Tetris
	melodies[1] = new Melody(
		{NOTE_E5, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_A4, NOTE_C5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_B4, 0, NOTE_C5,NOTE_D5, NOTE_E5, NOTE_C5, NOTE_A4, NOTE_A4},
		{4,8,8,4,8,8,4,8,8,4,8,8,4,8,8,4,4,4,4,2});

	//Hazard (Dixie)
	melodies[2] = new Melody(
		{NOTE_G5, NOTE_E5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_E5},
		{8,8,4,4,8,8,8,8,4,4,4,4});

	//Seven nation army
	melodies[3] = new Melody(
		{NOTE_F5, NOTE_F5, NOTE_GS5, NOTE_F5, NOTE_DS5, NOTE_CS5, NOTE_C5},
		{6,16,12,12,16,4,4});

	//Campioni del mondo
	melodies[4] = new Melody(
		{NOTE_C5, NOTE_F5, NOTE_F5, NOTE_A5, NOTE_F5, NOTE_F5, NOTE_A5, NOTE_G5, NOTE_A5, NOTE_F5},
		{8,8,4,8,8,4,8,3,8,3});

	//Bevo Bevo
	melodies[5] = new Melody(
		{NOTE_A5, NOTE_F5, NOTE_A5, NOTE_F5, NOTE_A5, NOTE_F5, NOTE_A5, NOTE_F5, NOTE_A5, NOTE_G5, NOTE_G5, NOTE_A5, NOTE_AS5, NOTE_AS5, NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_A5, NOTE_F5, NOTE_F5, NOTE_A5, NOTE_G5, NOTE_C5, NOTE_E5, NOTE_G5, NOTE_F5},
		{8,4,8,4,8,8,8,8,8,4,16,16,8,4,16,16,16,8,4,16,16,8,8,8,8,4});

	//Maza la vecia
	melodies[6] = new Melody(
		{NOTE_G5, NOTE_G5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_B5, NOTE_C6},
		{8,16,8,8,4,8,8});

	//Gne gne gne gne gne gne gnee
	melodies[7] = new Melody(
		{NOTE_G5, NOTE_G5, NOTE_E5, NOTE_A5, NOTE_G5, NOTE_G5, NOTE_E5},
		{8,8,8,8,8,8,4});

	//Koala
	melodies[8] = new Melody(
		{NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_CS4, NOTE_CS4, NOTE_CS4, NOTE_CS4, NOTE_CS4, NOTE_CS4, NOTE_CS4, NOTE_CS4},
		{16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16});

	//Rumore piu fastioso del mondo
	melodies[9] = new Melody(
		{NOTE_A6},
		{1});
}
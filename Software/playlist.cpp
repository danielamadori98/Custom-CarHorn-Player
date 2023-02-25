#include "playlist.h"

//Clacson corriera
void Playlist::init(){
	melodies = new Melody[MELODY_NUMBER];

	melodies[0] = new Melody(4,
		{NOTE_G5, NOTE_F5, NOTE_E5, NOTE_F5},
		{8,8,8,8});

	//Tetris
	melodies[1] = new Melody(20,
		{NOTE_E5, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_A4, NOTE_C5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_B4, 0, NOTE_C5,NOTE_D5, NOTE_E5, NOTE_C5, NOTE_A4, NOTE_A4},
		{4,8,8,4,8,8,4,8,8,4,8,8,4,8,8,4,4,4,4,2});

	//Hazard (Dixie)
	melodies[2] = new Melody(12,
		{NOTE_G5, NOTE_E5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_E5},
		{8,8,4,4,8,8,8,8,4,4,4,4});

	//Seven nation army
	melodies[3] = new Melody(7,
		{NOTE_F5, NOTE_F5, NOTE_GS5, NOTE_F5, NOTE_DS5, NOTE_CS5, NOTE_C5},
		{6,16,12,12,16,4,4});

	//Campioni del mondo
	melodies[4] = new Melody(10,
		{NOTE_C5, NOTE_F5, NOTE_F5, NOTE_A5, NOTE_F5, NOTE_F5, NOTE_A5, NOTE_G5, NOTE_A5, NOTE_F5},
		{8,8,4,8,8,4,8,3,8,3});

	//Bevo Bevo
	melodies[5] = new Melody(26, //10+16
		{NOTE_A5, NOTE_F5, NOTE_A5, NOTE_F5, NOTE_A5, NOTE_F5, NOTE_A5, NOTE_F5, NOTE_A5, NOTE_G5, NOTE_G5, NOTE_A5, NOTE_AS5, NOTE_AS5, NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_A5, NOTE_F5, NOTE_F5, NOTE_A5, NOTE_G5, NOTE_C5, NOTE_E5, NOTE_G5, NOTE_F5},
		{8,4,8,4,8,8,8,8,8,4,16,16,8,4,16,16,16,8,4,16,16,8,8,8,8,4});

	//Maza la vecia
	melodies[6] = new Melody(7,
		{NOTE_G5, NOTE_G5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_B5, NOTE_C6},
		{8,16,8,8,4,8,8});

	//Gne gne gne gne gne gne gnee
	melodies[7] = new Melody(7,
		{NOTE_G5, NOTE_G5, NOTE_E5, NOTE_A5, NOTE_G5, NOTE_G5, NOTE_E5},
		{8,8,8,8,8,8,4});

	//Koala
	melodies[8] = new Melody(32,
		{ NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_CS4, NOTE_CS4, NOTE_CS4, NOTE_CS4, NOTE_CS4, NOTE_CS4, NOTE_CS4, NOTE_CS4},
		{16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16});

	//Rumore piu fastioso del mondo
	melodies[9] = new Melody(1,
		{NOTE_A6},
		{1});
}
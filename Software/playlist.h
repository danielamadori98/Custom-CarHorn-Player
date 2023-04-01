#include "melody.h"


#define MELODY_NUMBER 10


class Player{
	unsigned short pauseBetweenNotes = 0;
	double speed = 1;

	Melody *melodies[];

public:

	void init();

	void play(int actionNumber);

	bool preview(int actionNumber);
};
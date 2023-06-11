#include "melody.h"

#define MELODY_NUMBER 10

class Player{
	unsigned short pauseBetweenNotes = 0;
	float speed = 1;

	Melody *melodies[MELODY_NUMBER];

public:

	void init(void);

	void play(unsigned short actionNumber);

	bool preview(unsigned short actionNumber);
};
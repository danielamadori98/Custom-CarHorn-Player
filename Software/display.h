class Display{
	#define SEGMENT_NUMBER 7
	#define DIGITS_NUMBER 16

	// Array per i pin dello schermo a 7 segmenti
	// La numerazione parte dal pin a fino alla g, dal segmento in alto e ruotando in senso orario
	// int sevSeg[SEGMENT_NUMBER] = {1, 2, 3, 4, 5, 6, 7};

	// https://www.hacktronics.com/Tutorials/arduino-and-7-segment-led.html
	byte digits[DIGITS_NUMBER][SEGMENT_NUMBER] = {
		{ 1, 1, 1, 1, 1, 1, 0 }, // = 0
		{ 0, 1, 1, 0, 0, 0, 0 }, // = 1
		{ 1, 1, 0, 1, 1, 0, 1 }, // = 2
		{ 1, 1, 1, 1, 0, 0, 1 }, // = 3
		{ 0, 1, 1, 0, 0, 1, 1 }, // = 4
		{ 1, 0, 1, 1, 0, 1, 1 }, // = 5
		{ 1, 0, 1, 1, 1, 1, 1 }, // = 6
		{ 1, 1, 1, 0, 0, 0, 0 }, // = 7
		{ 1, 1, 1, 1, 1, 1, 1 }, // = 8
		{ 1, 1, 1, 0, 0, 1, 1 }, // = 9
		{ 1, 1, 1, 0, 1, 1, 1 }, // = A
		{ 0, 0, 1, 1, 1, 1, 1 }, // = B
		{ 1, 0, 0, 1, 1, 1, 0 }, // = C
		{ 0, 1, 1, 1, 1, 0, 1 }, // = D
		{ 1, 0, 0, 1, 1, 1, 1 }, // = E
		{ 1, 0, 0, 0, 1, 1, 1 }	 // = F
	};

public:
	
	void write(unsigned short digit) {
		if(digit > DIGITS_NUMBER)
			return;

		//for (unsigned short segCount = 0; segCount < segmentNumber; ++segCount)
		//	digitalWrite(sevSeg[segCount], digitss[digit][segCount]);
	}

	void loading(unsigned short repetNumber){
		if(--repetNumber > 0)
			loading(repetNumber);

		// Serpentina iniziale
		/*int snake[] = {a, b, g, e, d, c, g, f};

		for(unsigned short i = 0; i < sizeof(snake) / sizeof(snake[0]); i++) {
			digitalWrite(snake[i], HIGH);
			delay(100);
			digitalWrite(snake[i], LOW);
		}
		*/	
	}

	void init(){
		//for(unsigned short i = 0; i < segmentNumber; i++)
		//	pinMode(sevSeg[i], OUTPUT);

		loading(3);
	}

};
class Diplay{
	unsigned short segmentNumber = 7,
					digitsNumber = 16;

	// Array per i pin dello schermo a 7 segmenti
	
	// La numerazione parte dal pin a fino alla g, dal segmento in alto e ruotando in senso orario
	int sevSeg[segmentNumber] = {a, b, c, d, e, f, g};

	// https://www.hacktronics.com/Tutorials/arduino-and-7-segment-led.html
	byte seven_seg_digits[digitsNumber][segmentNumber] = {
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
		if(digit > digitsNumber)
			return;

		for (unsigned short segCount = 0; segCount < segmentNumber; ++segCount)
			digitalWrite(sevSeg[segCount], seven_seg_digits[digit][segCount]);
	}

	void init(){
		for(unsigned short i = 0; i < segmentNumber; i++)
			pinMode(sevSeg[i], OUTPUT);

		// Serpentina iniziale
		int snake[] = {a, b, g, e, d, c, g, f, a, b, g, e, d, c, g, f, a, b, g, e, d, c, g, f, a, b, g, e, d, c, g, f};

		for(unsigned short i = 0; i < (sizeof(snake) / sizeof(snake[0])); i++) {
			digitalWrite(snake[i], HIGH);
			delay(100);
			digitalWrite(snake[i], LOW);
		}
	}

};

Display display;
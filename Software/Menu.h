class Menu{
	unsigned short actionNumber = 0;

	unsigned short get(){
		return 0;
	};
	
public:
	void choose(void){
		unsigned short actionNumber = get() % MELODY_NUMBER + 2;//Plus normal clason and BL

		if(this.actionNumber == actionNumber)
			return;

		this.actionNumber = actionNumber;
	  	display.write(actionNumber);
	}

	void run(void){
		if(actionNumber < MELODY_NUMBER)
			playlist.run(actionNumber);
		else
		bl();
	}
}
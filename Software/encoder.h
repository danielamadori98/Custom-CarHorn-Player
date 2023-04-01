
class Encoder{
	unsigned short value = 0;

	unsigned short get(){
		return 0;
	}

public:
	unsigned short getValue(){
		return value;
	}

	bool valueListener(){
		unsigned short value = get();
		if(value == this->value)
			return false;

		this->value = value;

		return true;
	}

	bool clickListener(){
		return true;
	}

};

Encoder encoder;


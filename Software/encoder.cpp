#include "Encoder.hpp"

Encoder encoder;

#define ROTARY_ENCODER_A_PIN 23
#define ROTARY_ENCODER_B_PIN 22
#define ROTARY_ENCODER_BUTTON_PIN 21
#define ROTARY_ENCODER_VCC_PIN -1
#define ROTARY_ENCODER_STEPS 4 //With 4 works, don't change

//instead of changing here, rather change numbers above

AiEsp32RotaryEncoder rotaryEncoder = AiEsp32RotaryEncoder(ROTARY_ENCODER_A_PIN, ROTARY_ENCODER_B_PIN, ROTARY_ENCODER_BUTTON_PIN, ROTARY_ENCODER_VCC_PIN, ROTARY_ENCODER_STEPS);


void IRAM_ATTR readEncoderISR(){
	rotaryEncoder.readEncoder_ISR();
}

void Encoder::setup(unsigned short maxValue) {
	rotaryEncoder.begin();
	rotaryEncoder.setup(readEncoderISR);
	//set boundaries and if values should cycle or not
	//in this example we will set possible values between 0 and 1000;
	bool circleValues = true;
	rotaryEncoder.setBoundaries(0, maxValue, circleValues); //minValue, maxValue, circleValues true|false (when max go to min and vice versa)

	/*Rotary acceleration introduced 25.2.2021.
	   * in case range to select is huge, for example - select a value between 0 and 1000 and we want 785
	   * without accelerateion you need long time to get to that number
	   * Using acceleration, faster you turn, faster will the value raise.
	   * For fine tuning slow down.
	*/
	rotaryEncoder.disableAcceleration(); //acceleration is now enabled by default - disable if you dont need it
	//rotaryEncoder.setAcceleration(maxValue/4); //or set the value - larger number = more accelearation; 0 or 1 means disabled acceleration
}

short Encoder::getValue(void){
	unsigned short tmp = rotaryEncoder.readEncoder();
	Serial.print("encoder value: ");
	Serial.println(tmp);

	return tmp;
}

bool Encoder::valueListener(void){
	return rotaryEncoder.encoderChanged();
}

bool Encoder::clickListener(void){
	return rotaryEncoder.isEncoderButtonClicked();	
}
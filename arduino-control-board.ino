//INPUTS ----------------------

#define BUTTON_SHOOT 7

#define POT_MOTOR_LEFT 0
#define POT_MOTOR_RIGHT 1

//VALS -------------------------

//SETUP ------------------------

void setup() {
	Serial.begin(9600);

	pinMode(BUTTON_SHOOT, INPUT);
}

//LOOP ----------------------------

void loop() {
	
	int left = analogRead(POT_MOTOR_LEFT);
	int right = analogRead(POT_MOTOR_RIGHT);
	int shoot;
	
	if(digitalRead(BUTTON_SHOOT) == HIGH) {
		shoot = 1;
	} else {
		shoot = 0;
	}
	
	//if(Serial.availableForWrite > 2)
	
	Serial.write((byte)(left / 4));
	Serial.write((byte)(right / 4));
	Serial.write(byte)(shoot));
	
	Serial.flush();
	delay(10);

}
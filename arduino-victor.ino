//MOTORS -----------------
#define MOTOR_LEFT_1 1
#define MOTOR_LEFT_2 2
#define MOTOR_RIGHT_1 3
#define MOTOR_RIGHT_2 4

#define MOTOR_SHOOT_LEFT 9
#define MOTOR_SHOOT_RIGHT 10

//INPUTS ----------------------

#define BUTTON_SHOOT 7

#define POT_MOTOR_LEFT 0
#define POT_MOTOR_RIGHT 1

//VALS -------------------------

int leftDriveTime = 1500;
int rightDriveTime = 1500;
int leftShootTime = 1500;
int rightShootTime = 1500;
int delayTime = 3000;

int q_leftDrive = 1500;
int q_rightDrive = 1500;
int q_leftShoot = 1500;
int q_rightShoot = 1500;
int q_delayTime = 3000;

int increment = 50;

//SETUP ------------------------

void setup() {
	pinMode(MOTOR_LEFT_1, OUTPUT);
	pinMode(MOTOR_LEFT_2, OUTPUT);
	pinMode(MOTOR_RIGHT_1, OUTPUT);
	pinMode(MOTOR_RIGHT_2, OUTPUT);
	pinMode(MOTOR_SHOOT_LEFT, OUTPUT);
	pinMode(MOTOR_SHOOT_RIGHT, OUTPUT);

	pinMode(BUTTON_SHOOT, INPUT);
}

//LOOP ----------------------------

void loop() {
	
	leftDriveTime = calcTime(analogRead(POT_MOTOR_LEFT) / 1024);
	rightDriveTime = calcTime(analogRead(POT_MOTOR_RIGHT) / 1024);
	
	if(digitalRead(BUTTON_SHOOT) == HIGH) {
		leftShootTime = calcTime(0.8);
		rightShootTime = calcTime(1); //They need to be run at different speeds?
	} else {
		leftShootTime = calcTime(0);
		leftShootTime = calcTime(0);
	}

	checkQueue();
}

void checkQueue() {
	
	//QUEUE RESET
	
	if(q_delayTime <= 0) {
		resetVals();
		setHigh();
	}

	//DETERMINE OFF SWITCHES
	
	if(q_leftDrive <= 0) {
		digitalWrite(MOTOR_LEFT_1, LOW);
		digitalWrite(MOTOR_LEFT_2, LOW);
	}

	if(q_rightDrive <= 0) {
		digitalWrite(MOTOR_RIGHT_1, LOW);
		digitalWrite(MOTOR_RIGHT_2, LOW);
	}

	if(q_leftShoot <= 0) {
		digitalWrite(MOTOR_SHOOT_LEFT, LOW);
	}

	if(q_rightShoot <= 0) {
		digitalWrite(MOTOR_SHOOT_RIGHT, LOW);
	}
	
	//DECREMENT AND DELAY
	
	decrementVals();
	delayMicroseconds(increment);
}

void decrementVals() {
	q_leftDrive -= increment;
	q_rightDrive -= increment;
	q_leftShoot -= increment;
	q_rightShoot -= increment;
	q_delayTime -= increment;
}

void resetVals() {
	q_leftDrive = leftDriveTime;
	q_rightDrive = rightDriveTime;
	q_leftShoot = leftShootTime;
	q_rightShoot = rightShootTime;
	q_delayTime = delayTime;
}

void setHigh() {
	digitalWrite(MOTOR_LEFT_1, HIGH);
	digitalWrite(MOTOR_LEFT_2, HIGH);

	digitalWrite(MOTOR_RIGHT_1, HIGH);
	digitalWrite(MOTOR_RIGHT_2, HIGH);

	digitalWrite(MOTOR_SHOOT_LEFT, HIGH);
	digitalWrite(MOTOR_SHOOT_RIGHT, HIGH);
}

int calcTime(double power) {
	if(power > 1 || power < -1) { //not necessary, motor won't run with invalid values
		return 1500;
	} else {
		return 1500 + (450 * power);
	}
}


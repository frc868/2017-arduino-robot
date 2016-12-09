//MOTORS -----------------
#define LEFT_MOTOR_1 1
#define LEFT_MOTOR_2 2
#define RIGHT_MOTOR_1 3
#define RIGHT_MOTOR_2 4

#define MOTOR_SHOOT_LEFT 9
#define MOTOR_SHOOT_RIGHT 10

//INPUTS ----------------------

#define BUTTON_FORWARD 5
#define BUTTON_BACKWARD 6

#define BUTTON_MOTOR_ON 7
#define BUTTON_MOTOR_OFF 8

//VARS ----------------------

#define DRIVE_POWER_FW 1800
#define DRIVE_POWER_BK 1200
#define DRIVE_POWER_NIL 1500
#define SHOOT_POWER 1800
#define SHOOT_POWER_NIL 1500

int driveDelay = 1500;
int shootDelay = 1500;

//SETUP ------------------------

void setup() {
  pinMode(LEFT_MOTOR_1, OUTPUT);
  pinMode(LEFT_MOTOR_2, OUTPUT);
  pinMode(RIGHT_MOTOR_1, OUTPUT);
  pinMode(RIGHT_MOTOR_2, OUTPUT);

  pinMode(MOTOR_SHOOT_LEFT, OUTPUT);
  pinMode(MOTOR_SHOOT_RIGHT, OUTPUT);

  pinMode(BUTTON_FORWARD, INPUT);
  pinMode(BUTTON_BACKWARD, INPUT);

  pinMode(BUTTON_MOTOR_ON, INPUT);
  pinMode(BUTTON_MOTOR_OFF, INPUT);
}

//LOOP ----------------------------

void loop() {
  //drive
  if(digitalRead(BUTTON_FORWARD) == HIGH) {
    driveDelay = DRIVE_POWER_FW;
  } else if(digitalRead(BUTTON_BACKWARD) == HIGH) {
    driveDelay = DRIVE_POWER_BK;
  } else {
    driveDelay = DRIVE_POWER_NIL;
  }

  //shoot
  if(digitalRead(BUTTON_MOTOR_ON) == HIGH) {
    shootDelay = SHOOT_POWER;
  } else if(digitalRead(BUTTON_MOTOR_OFF) == HIGH) {
    shootDelay = SHOOT_POWER_NIL;
  }

  //DRIVE
  digitalWrite(LEFT_MOTOR_1, HIGH);
  digitalWrite(LEFT_MOTOR_2, HIGH);
  digitalWrite(RIGHT_MOTOR_1, HIGH);
  digitalWrite(RIGHT_MOTOR_2, HIGH);
  delayMicroseconds(driveDelay);
  digitalWrite(LEFT_MOTOR_1, LOW);
  digitalWrite(LEFT_MOTOR_2, LOW);
  digitalWrite(RIGHT_MOTOR_1, LOW);
  digitalWrite(RIGHT_MOTOR_2, LOW);

  //SHOOT
  
  digitalWrite(MOTOR_SHOOT_LEFT, HIGH);
  digitalWrite(MOTOR_SHOOT_RIGHT, HIGH);
  delayMicroseconds(shootDelay);
  digitalWrite(MOTOR_SHOOT_LEFT, LOW);
  digitalWrite(MOTOR_SHOOT_RIGHT, LOW);

  delayMicroseconds(1000);
}


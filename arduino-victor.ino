#include <Victor.h>
#include <VictorQueue.h>

#define DRIVE_LEFT 5
#define DRIVE_RIGHT 6
#define SHOOT_LEFT 7
#define SHOOT_RIGHT 8

#define BUTTON_SHOOT 3
#define POT_LEFT 0
#define POT_RIGHT 1

Victor dl(DRIVE_LEFT);
Victor dr(DRIVE_RIGHT);
Victor sl(SHOOT_LEFT);
Victor sr(SHOOT_RIGHT);
  
Victor *victors[4] = {&dl, &dr, &sl, &sr}; 

VictorQueue queue(4, victors);

void setup() {
  pinMode(BUTTON_SHOOT, INPUT);
}

void loop () {
  dl.setSpeed(analogRead(POT_LEFT) / 1024);
  dr.setSpeed(analogRead(POT_RIGHT) / 1024);

  if(digitalRead(BUTTON_SHOOT) == HIGH) {
    sl.setSpeed(1);
    sr.setSpeed(0.8);
  }

  queue.checkQueue();
}


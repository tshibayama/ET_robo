#include "Tracer.h" // <1>

#define DELTA_T 0.05
#define Kp  0.83
#define addTurn 30
/*#define Ki  0
#define Kd  0*/

static int diff[2];
//static float integral;
static int flag = 0;

Tracer::Tracer():
  leftWheel(PORT_C), rightWheel(PORT_B), colorSensor(PORT_2), soner(PORT_3), gyro(PORT_4) { // <2>
  }

void Tracer::init() {
  init_f("Tracer");
}

void Tracer::terminate() {
  msg_f("Stopped.", 1);
  leftWheel.stop();  // <1>
  rightWheel.stop();
}

void Tracer::run() {
  msg_f("running...", 1);
  int motorCount = leftWheel.getCount();
  if ((motorCount <= 3600) || (motorCount >= 7300)) {
    edgeRight();
  } else {
    edgeLeft();
  }

  printf("[%d]", leftWheel.getCount());
}

void Tracer::run2() {
  msg_f("running...", 1);
  //gyro.reset();
  int pwm_l, pwm_r;
  float turn = calc_prop_value();
  int distance = soner.getDistance();
  int motorCount = 0;
  int motorCount2 = 0;
  int angle = gyro.getAngle();
  if ((distance <= 7) && (distance != 0)) {
    turnRight();
    flag = 1;
    motorCount = leftWheel.getCount();
  } else if (flag == 1) {
    motorCount2 = leftWheel.getCount();
    turnLeft();
  } else {
    edgeLeft();
    //controlAngle();
  }

  printf("[%d]", motorCount2 - motorCount);
}

void Tracer::turnRight() {
  int pwm_l, pwm_r;
  float turn = calc_prop_value();
  pwm_l = pwm + (turn + addTurn);
  pwm_r = pwm - turn;
  leftWheel.setPWM(pwm_l);
  rightWheel.setPWM(pwm_r);
}

void Tracer::turnLeft() {
  int pwm_l, pwm_r;
  float turn = calc_prop_value();
  pwm_l = pwm - turn;
  pwm_r = pwm + (turn + addTurn);
  leftWheel.setPWM(pwm_l);
  rightWheel.setPWM(pwm_r);
}

void Tracer::edgeLeft() {
  int pwm_l, pwm_r;
  float turn = calc_prop_value();
  pwm_l = pwm + turn;
  pwm_r = pwm - turn;
  leftWheel.setPWM(pwm_l);
  rightWheel.setPWM(pwm_r);
}

void Tracer::edgeRight() {
  int pwm_l, pwm_r;
  float turn = calc_prop_value();
  pwm_l = pwm - turn;
  pwm_r = pwm + turn;
  leftWheel.setPWM(pwm_l);
  rightWheel.setPWM(pwm_r);
}

void Tracer::controlAngle() {
  int angle = gyro.getAngle();
  int pwm_l, pwm_r;
  float turn = calc_prop_value();

  if (angle < 0) {
    pwm_l = pwm + (turn + addTurn);
    pwm_r = pwm - turn;
  } else if (angle > 0) {
    pwm_l = pwm - turn;
    pwm_r = pwm + (turn + addTurn);
  }
  leftWheel.setPWM(pwm_l);
  rightWheel.setPWM(pwm_r);
}

float Tracer::calc_prop_value() {
  const int target = 20;
  float p; //i, d;

  //diff[0] = diff[1];
  diff[1] = colorSensor.getBrightness() - target;
  //integral += (diff[1] + diff[0]) / 2.0 * DELTA_T;
  p = Kp * diff[1];
  /*i = Ki * integral;
  d = Kd * (diff[1] - diff[0]) / DELTA_T;*/


  return (p);
}
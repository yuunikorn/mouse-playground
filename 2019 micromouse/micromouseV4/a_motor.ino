#include <Adafruit_MotorShield.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); // Create the motor shield object with the default I2C address
Adafruit_DCMotor *rightMotor = AFMS.getMotor(2); // Select which 'port' M1, M2, M3 or M4. In this case, M1
Adafruit_DCMotor *leftMotor = AFMS.getMotor(1);

//initialize constant speed at 100
int MotorLeft = 100;
int MotorRight = 100;

void MotorSetup(){
  AFMS.begin();  // create with the default frequency 1.6KHz
  // Set the speed to start, from 0 (off) to 255 (max speed)
  leftMotor->setSpeed(0);
  rightMotor->setSpeed(0);
  leftMotor->run(FORWARD);
  rightMotor->run(FORWARD);
}

void Forward(int leftspeed , int rightspeed){
  leftMotor->run(FORWARD);
  rightMotor->run(FORWARD);
  leftMotor->setSpeed(leftspeed);
  rightMotor->setSpeed(rightspeed);
  
}

void Reverse(int leftspeed , int rightspeed){
  leftMotor->run(BACKWARD);
  rightMotor->run(BACKWARD);
  leftMotor->setSpeed(leftspeed);
  rightMotor->setSpeed(rightspeed);
}


void Stop(){
  leftMotor->run(FORWARD);
  rightMotor->run(FORWARD);
  leftMotor->setSpeed(0);
  rightMotor->setSpeed(0);
}

void Left(int turnspeed){
  leftMotor->run(FORWARD);
  rightMotor->run(BACKWARD);
  leftMotor->setSpeed(turnspeed);
  rightMotor->setSpeed(turnspeed);
}

void Right(int turnspeed){
  leftMotor->run(BACKWARD);
  rightMotor->run(FORWARD);
  leftMotor->setSpeed(turnspeed);
  rightMotor->setSpeed(turnspeed);
}

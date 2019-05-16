/* Initializing Motors Hardware w/ Motorsheild
*
* Functions that can be called:
* --> Setup:
*     MotorSetup();
*          -Initialized AdaFruitMotorShield(AFMS)
*          -Refer to comments below for Motor Port specification
*
* --> Loop:
*     Forward(int leftspeed , int rightspeed);
*          -Both motors set to forward with user input speeds left/right speeds between 0(off) and 255(max speed)
*     Reverse(int leftspeed , int rightspeed);
*          --Both motors set to reverse with user input speeds left/right speeds between 0(off) and 255(max speed)
*     Left(int turnspeed);
*          -Motors turn left at user designated speeds between 0(off) and 255(max speed)
*     Right(int turnspeed);
*          -Motors turn right at user designated speeds between 0(off) and 255(max speed)
*     Stop();
*          -Motors directio set to forward with speed of 0
*/


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

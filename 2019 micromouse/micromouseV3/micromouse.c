#include <bluefruit.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include <Adafruit_L3GD20.h>

#define SENSORFRONT A0
#define SENSORLEFT A1
#define SENSORRIGHT A2
#define ENCODERLEFT A3
#define ENCODERRIGHT A4

//sets up gyro, attach SLC/SDA/Vin/GND pin using I2C
Adafruit_L3GD20 gyro;

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61);

// Select which 'port' M1, M2, M3 or M4. In this case, M1
Adafruit_DCMotor *rightMotor = AFMS.getMotor(2);
// You can also make another motor on port M2
Adafruit_DCMotor *leftMotor = AFMS.getMotor(1);

int MotorLeft = 100;
int MotorRight = 100;
int rawsensorValueR = 0;
int sensorcountR0 = 0;
int sensorcountR1 = 0;
int countR = 0;
int rawsensorValueL = 0;
int sensorcountL0 = 0;
int sensorcountL1 = 0;
int countL = 0;
int IRrange = 200;

void setup() {

  AFMS.begin();  // create with the default frequency 1.6KHz
  //  AFMS.begin(1000);  // OR with a different frequency, say 1KHz
  Serial.begin(9600);
  gyro.begin();

  // Set the speed to start, from 0 (off) to 255 (max speed)
  leftMotor->setSpeed(0);
  rightMotor->setSpeed(0);

  leftMotor->run(FORWARD);
  rightMotor->run(FORWARD);


  // initialize gyro; warn if not detected
  if (!gyro.begin(gyro.L3DS20_RANGE_500DPS)){
    Serial.println("Unable to initialize L3GD20H");
  }
}

void loop() {
//  Serial.println("Front: " + String(analogRead(SENSORFRONT)));
//  Serial.println("Left: " + String(analogRead(SENSORLEFT)) + " |  Right: " + String(analogRead(SENSORRIGHT)) );


  if(analogRead(SENSORFRONT) > IRrange && analogRead(SENSORRIGHT) > IRrange && analogRead(SENSORLEFT) > IRrange) {
    turn180();
  }
  else if (analogRead(SENSORRIGHT) > IRrange && analogRead(SENSORLEFT) <= IRrange){ //if there is a space on left,
    turnLeft();
  }

  else if (analogRead(SENSORRIGHT) <= IRrange && analogRead(SENSORLEFT) > IRrange){
    turnRight();
  }

  else if (analogRead(SENSORFRONT) <= IRrange && analogRead(SENSORRIGHT) <= IRrange && analogRead(SENSORLEFT) <= IRrange){

    int num = random(1, 4);
    Serial.print(num);

    if (num == 1){

      turnLeft();
    }
    else if(num == 2){
      turnRight();
    }
    else{
      moveforward();
    }


  }

  else {

      moveforward();


  }

}


void turnright(){

}


void turnleft(){

}




/////////////////////////////////////////////////////
void turnRight() {

  double angle = 0;
  rightMotor->setSpeed(70);
  leftMotor->run(BACKWARD);
  leftMotor->setSpeed(70);

  while (angle >= -45 && analogRead(SENSORFRONT) < 225){
    //sensors_event_t event;
    //gyro.getEvent(&event);
    gyro.read();
    double angleSpeed = gyro.data.z;
    double angleTraveled = angleSpeed * 0.015;

    //Serial.print("AngularSpeed: ");
    //Serial.println(gyro.data.z);
    //delay(1500);
    angle = angle + angleTraveled;
    Serial.println(angle);
   }
   rightMotor->setSpeed(0);
   leftMotor->run(FORWARD);
   leftMotor->setSpeed(0);
}


void turnLeft() {
  double angle = 0;
  leftMotor->setSpeed(70);
  rightMotor->run(BACKWARD);
  rightMotor->setSpeed(70);

  while (angle <= 45){

    gyro.read();
    double angleSpeed = gyro.data.z;
    double angleTraveled = angleSpeed * 0.015;
    //Serial.print("AngularSpeed: ");
    //Serial.println(gyro.data.z);
    //delay(1500);
    angle = angle + angleTraveled;
    Serial.println(angle);
   }
   leftMotor->setSpeed(0);
   rightMotor->run(FORWARD);
   rightMotor->setSpeed(0);
}


void turn180() {
  double angle = 0;
  leftMotor->setSpeed(70);
  rightMotor->run(BACKWARD);
  rightMotor->setSpeed(70);

  while (angle <= 90){

    gyro.read();
    double angleSpeed = gyro.data.z;
    double angleTraveled = angleSpeed * 0.015;
    //Serial.print("AngularSpeed: ");
    //Serial.println(gyro.data.z);
    //delay(1500);
    angle = angle + angleTraveled;
    Serial.println(angle);
   }
   leftMotor->setSpeed(0);
   rightMotor->run(FORWARD);
   rightMotor->setSpeed(0);
}




void moveforward(){

  for(int i = 0 ; (i < 2000  && analogRead(SENSORFRONT) < 225); i ++ ){
    leftMotor->setSpeed(70);
    rightMotor->setSpeed(70);
  }
    leftMotor->setSpeed(0);
    rightMotor->setSpeed(0);

}




//////////////////////////////////////////////

void leftRead() {
  rawsensorValueL = analogRead(ENCODERLEFT);
  if (rawsensorValueL < 800) {
    sensorcountL1 = 1;
  }
  else {
    sensorcountL1 = 0;
  }
  if (sensorcountL1 != sensorcountL0) {
    countL++;
  }
  sensorcountL0 = sensorcountL1;
  Serial.println("Left Encoder Count: " + String(countL));
}


void rightRead() {
  rawsensorValueR = analogRead(ENCODERRIGHT);
    if (rawsensorValueR < 800) {
      sensorcountR1 = 1;
    }
    else {
      sensorcountR1 = 0;
    }
    if (sensorcountR1 != sensorcountR0) {
      countR++;
    }
    sensorcountR0 = sensorcountR1;
    //Serial.println("Right Encoder Count: " + String(countR));
}




//////////////////////////////////////////////
void stepforward(){

  leftMotor->setSpeed(MotorLeft);
  rightMotor->setSpeed(MotorRight);
  if (analogRead(SENSORLEFT) >= 290) {
    MotorLeft += 3;
    MotorRight -= 3;
  }

  if (analogRead(SENSORRIGHT) >= 290) {
    MotorRight += 5;
    MotorLeft -= 5;
  }
  for(int i = 0; i < 200; i++) {
    leftMotor->setSpeed(MotorLeft);
    rightMotor->setSpeed(MotorRight);
    //Serial.println("Left Encoder: " + String(analogRead(ENCODERLEFT)) + "  | Right Encoder: " + String(analogRead(ENCODERRIGHT)) );

    leftRead();
    rightRead();
  }
  leftMotor->setSpeed(0);
  rightMotor->setSpeed(0);
  delay(500);
}

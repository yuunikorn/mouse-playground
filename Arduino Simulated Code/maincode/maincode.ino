#include <A4990MotorShield.h>
A4990MotorShield motors;

#define LED_PIN 13
#define center A0
#define right 4
#define left 3
int inputValCenter = 0;
int inputValLeft = 0;
int inputValRight = 0;


void stopIfFault(){
  if (motors.getFault()){
    motors.setSpeeds(0,0);
    Serial.println("Fault");
    while(1);
  }
}

void turnLeft(){
  Serial.println("robot is turning LEFT");
  for (int speed = 0; speed <= 200; speed++){
    motors.setM1Speed(speed);
    stopIfFault();
    delay(2);
      
    }
}

//void turnRight(){
//  Serial.println("robot is turning RIGHT");  
//}

//void turnAROUND(){
//  Serial.println("robot is turning 180 degrees");
//}

//void detectsides(){
//if front is free
  //if left side is free, and right side is not
  //turn left
  //if right side is free, and left sied is not
  //turn right
  //if both sides are free
  //randomly generate 
//  () 
//}



void setup(){
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
  Serial.println("Pololu A4990 Dual Motor Driver Shield for Arduino");
  
  // uncomment one or both of the following lines if your motors' directions need to be flipped
  motors.flipM1(true);
  Serial.println("M1 work");
  motors.flipM2(true);
  Serial.println("M2 work");

  pinMode(center, INPUT);
  pinMode(center, INPUT);
  pinMode(center, INPUT);
  Serial.begin(115200);

  Serial.println("IR sensors will run here");
  
}

void loop() {
    inputValCenter = analogRead(center);
    inputValLeft = analogRead(right);
    inputValRight = analogRead(left);


    Serial.println("\nCenter");
    Serial.println(inputValCenter);
    Serial.println("\nLeft");
    Serial.println(inputValLeft);
    Serial.println("\nRight");
    Serial.println(inputValRight);

    delay(3000);
}






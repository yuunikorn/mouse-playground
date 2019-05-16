/* Initializing IR Sensor Hardware
*
* Functions that can be called:
* --> Setup:
*
* --> Loop:
*     IRPrint();
*          -Reads Front/Left/Right IR sensor and serial prints values for hardware testing
*/


#define SENSORFRONT A0
#define SENSORLEFT A2
#define SENSORRIGHT A1

int IRrange = 290;
int frontIR, rightIR, leftIR;

void IRPrint(){
  frontIR = analogRead(SENSORFRONT);
  rightIR = analogRead(SENSORRIGHT);
  leftIR = analogRead(SENSORLEFT);
  Serial.println("Left" + String(leftIR) + ", Center" + String(frontIR) + ", Right" + String(rightIR) );
}



void leftAvailable(){

}

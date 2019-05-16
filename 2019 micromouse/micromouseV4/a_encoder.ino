/* Initializing Encoder Hardware
 *
 * Functions that can be called:
 * --> Setup:
 * 
 * --> Loop:
 *     ReadLeft();
 *          -Reads Left encoder, increments encoder sensor val (countL) when motors move
 *     ReadRight();
 *          -Reads Right encoder, increments encoder sensor val (countR) when motors move
 *     EncoderStraight(int steps);
 *          -Utilizes ReadLeft/ReadRight to move straight forward until steps is reached
*/

#define ENCODERLEFT A5
#define ENCODERRIGHT A4

int rawsensorValueR = 0;
int sensorcountR0 = 0;
int sensorcountR1 = 0;
int countR = 0;

int rawsensorValueL = 0;
int sensorcountL0 = 0;
int sensorcountL1 = 0;
int countL = 0;


void ReadLeft() {
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

void ReadRight() {
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
    Serial.println("Right Encoder Count: " + String(countR));
}

////////////////////////////////////////////////////////////////



void EncoderStraight(int steps) {
  int currEncoderLeft = countL;
  int currEncoderRight = countR;
  int rightVal = 0;
  int leftVal = 0;

  while(steps > rightVal || steps > leftVal){

    ReadRight();
    ReadLeft();
    Forward(70 , 70);
    rightVal = countR - currEncoderRight;
    leftVal = countL - currEncoderLeft;
  }
  Stop();

}

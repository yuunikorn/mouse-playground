/* Functions for motors to move straight
 *
 * Functions that can be called:
 * --> Hardware Tester:
 *     encoderTest();
 *          -Naive Forward(70 , 70); while reading L/R encoder values
 *          -Incorporates: a_encoder, a_motor
 *
 * --> Loop Functions:
 *     Straight(int steps);
 *          -use encoder data to calculate distance of steps, IR for compensation, wheels for movement
 *          -Incorporates: a_encoder, a_ir, a_motor
 *
*/


void encoderTest(){
  for(int i = 0; i < 10; i++){
    Forward(70 , 70);
    ReadRight();
    ReadLeft();
  }
  Stop();
  delay(1000);
}

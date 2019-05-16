/* Yu Chang Ou | Union College | May 2019
* Joule-ius Cheeser | Micromouse Version 4
*
* Headerfiles and variables initialized individually
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>
#include <Wire.h>

void setup() {
  // put your setup code here, to run once:
  BlinkSetup();
  GyroSetup();
  MotorSetup();
  Serial.begin(9600);
}

void loop() {
  //initialization requires stop at front
  reactivestraight(700); // 700 = one square block
  Stop();
  delay(1000);
}

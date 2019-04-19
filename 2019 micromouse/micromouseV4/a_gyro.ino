#include <Adafruit_L3GD20.h>
Adafruit_L3GD20 gyro;

void GyroSetup(){
  gyro.begin();
    // initialize gyro; warn if not detected
  if (!gyro.begin(gyro.L3DS20_RANGE_500DPS)){
    Serial.println("Unable to initialize L3GD20H");
  }
}


void TurnAngle(int angle){
  double target = 0;
    while (target <= angle){
      gyro.read();
      double angleSpeed = gyro.data.z;
      double angleTraveled = angleSpeed * 0.015;
      target = target + angleTraveled;
      Serial.println(target);
   }
}

int angularVel = 70;

void TurnAngle(int angle , bool directionality){
  double target = 0;

  if (directionality){      // directionality = 1 = left
    Left(angularVel);
    while (target <= angle){
    gyro.read();
    double angleSpeed = gyro.data.z;
    double angleTraveled = angleSpeed * 0.008879;
    target = target + angleTraveled;
    Serial.println(target);
   }
  }
  else{                     // directionality = 0 = right (Note: 180 turns default to right turns)
    Right(angularVel);
    
    while (target >= -angle){
    gyro.read();
    double angleSpeed = gyro.data.z;
    double angleTraveled = angleSpeed * 0.0102;
    target = target + angleTraveled;
    Serial.println(target);
   }
  }
   Stop();
}

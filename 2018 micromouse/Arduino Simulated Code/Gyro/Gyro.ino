

/*******************************************************************
  gyroV2.ino
********************************************************************
  This program is designed to use the Adafruit L3GD20H gyroscope to 
  monitor and record angular acceleration along the 3 axis of 
  rotation.
********************************************************************
  Sensors use I2C communication protocol.
********************************************************************
  Original: May 23, 2016
  Modified: May 31, 2016
********************************************************************/

#include <Wire.h>
#include <Adafruit_L3GD20.h>

// Use I2C communication protocal
Adafruit_L3GD20 gyro;

void setup() {
  
  // set baud rate
  Serial.begin(9600);

  // initialize gyro; warn if not detected
  if (!gyro.begin(gyro.L3DS20_RANGE_500DPS))
  {
    Serial.println("Unable to initialize L3GD20H");
  }
  
}

void loop() {
  
  // read gyro data and print to serial monitor
  gyro.read();
  Serial.print(" X: "); Serial.print((int)gyro.data.x);   Serial.print(" ");
  Serial.print(" Y: "); Serial.print((int)gyro.data.y);   Serial.print(" ");
  Serial.print(" Z: "); Serial.println((int)gyro.data.z); Serial.print(" ");
  
  // delay between data points for stability
  delay(100);
  
}

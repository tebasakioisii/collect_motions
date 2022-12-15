#include <M5StickCPlus.h>

float accX = 0.0F;
float accY = 0.0F;
float accZ = 0.0F;

typedef union {
  float val;
  byte bytes[4];
} f2b;

f2b fb;

void setup() {
  M5.begin();
  M5.Imu.Init();
  Serial.begin( 57600, SERIAL_8N1, 32, 33 );
}

void loop() {
  M5.IMU.getAccelData(&accX,&accY,&accZ);
  fb.val = accX;
  Serial.write(fb.bytes, 4);
  fb.val = accY;
  Serial.write(fb.bytes, 4);
  fb.val = accZ;
  Serial.write(fb.bytes, 4);
  delay(5);
}

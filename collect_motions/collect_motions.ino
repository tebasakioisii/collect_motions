#include <M5Core2.h>

// 加速度のみ使用
float accX = 0.0F;
float accY = 0.0F;
float accZ = 0.0F;

typedef union {
  float val;
  byte bytes[4];
} f2b;

f2b fb;
void setup()
{
  M5.begin();
  M5.IMU.Init();
  Serial.begin( 57600, SERIAL_8N1, 13, 14 );
  M5.IMU.getAccelData(&accX, &accY, &accZ);
  fb.val = accX;
  M5.lcd.setCursor(0, 0);
  M5.lcd.setTextFont(4);
  M5.lcd.printf("%f", accX);
  M5.lcd.setCursor(0, 40);
  M5.lcd.printf("%02x %02x %02x %02x", fb.bytes[0], fb.bytes[1], fb.bytes[2], fb.bytes[3]);
  Serial.write(fb.bytes, 4);
}

void loop()
{
  M5.IMU.getAccelData(&accX, &accY, &accZ);
  fb.val = accX;
  Serial.write(fb.bytes, 4);
  fb.val = accY;
  Serial.write(fb.bytes, 4);
  fb.val = accZ;
  Serial.write(fb.bytes, 4);
  delay(5);
}

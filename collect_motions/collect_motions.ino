#include <M5Core2.h>

#define FRONT 2

#define X_LOCAL 0
#define Y_LOCAL 0
#define X_OFFSET 160
#define Y_OFFSET 34

// 加速度のみ使用
float accX = 0.0F;
float accY = 0.0F;
float accZ = 0.0F;
char buf[150];

typedef union {
  float val;
  byte bytes[4];
} f2b;

void setup()
{
  M5.begin();
  M5.IMU.Init();
  M5.Lcd.setTextFont(4);
  M5.Lcd.setTextColor(TFT_WHITE, TFT_BLACK);
  Serial.begin( 57600, SERIAL_8N1, 13, 14 );

  M5.IMU.getAccelData(&accX, &accY, &accZ);
  sprintf(buf, " %5.3f   %5.3f   %5.3f   ", accX, accY, accZ);
  M5.Lcd.setCursor(X_LOCAL, Y_LOCAL + Y_OFFSET * 1 , FRONT);
  M5.Lcd.printf(buf);
}

void loop()
{
  f2b fb;
  fb.val = accX;
  Serial.write(fb.bytes, 4);
  M5.Lcd.setCursor(X_LOCAL, Y_LOCAL + Y_OFFSET * 2 , FRONT);
  M5.Lcd.printf("%x %x %x %x", fb.bytes[0], fb.bytes[1], fb.bytes[2], fb.bytes[3]);
  fb.val = accY;
  Serial.write(fb.bytes, 4);
  M5.Lcd.setCursor(X_LOCAL, Y_LOCAL + Y_OFFSET * 3 , FRONT);
  M5.Lcd.printf("%x %x %x %x", fb.bytes[0], fb.bytes[1], fb.bytes[2], fb.bytes[3]);
  fb.val = accZ;
  Serial.write(fb.bytes, 4);
  M5.Lcd.setCursor(X_LOCAL, Y_LOCAL + Y_OFFSET * 4 , FRONT);
  M5.Lcd.printf("%x %x %x %x", fb.bytes[0], fb.bytes[1], fb.bytes[2], fb.bytes[3]);
  delay(500);
}

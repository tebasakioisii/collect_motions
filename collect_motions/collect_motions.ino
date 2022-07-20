
#include <M5Core2.h>
#include "ClosedCube_TCA9548A.h"

#define FRONT 2

#define X_LOCAL 0
#define Y_LOCAL 0
#define X_OFFSET 160
#define Y_OFFSET 34

#define PaHub_I2C_ADDRESS  0x70

ClosedCube::Wired::TCA9548A tca9548a;

// 加速度のみ使用
float accX = 0.0F;
float accY = 0.0F;
float accZ = 0.0F;

void setup()
{
  M5.begin();
  M5.IMU.Init();
  M5.Lcd.setTextFont(4);
  M5.Lcd.setTextColor(TFT_WHITE,TFT_BLACK);
}

void loop()
{
  // 内臓IMUから取得
  M5.IMU.getAccelData(&accX,&accY,&accZ);
  M5.Lcd.setCursor(X_LOCAL, Y_LOCAL + Y_OFFSET*4 , FRONT);
  M5.Lcd.printf("                                                                ");
  M5.Lcd.setCursor(X_LOCAL, Y_LOCAL + Y_OFFSET*4 , FRONT);
  Serial.print("Internal IMU = ");
  M5.Lcd.printf("Internal %5.2f %5.2f %5.2f", accX, accY, accZ);
  delay(1);
}

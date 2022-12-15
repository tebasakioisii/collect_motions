#include <M5StickCPlus.h>

// 加速度のみ使用
float accX = 0.0F;
float accY = 0.0F;
float accZ = 0.0F;

char buf[50];

void setup() {
  M5.begin();
  M5.Imu.Init();
  Serial.begin( 57600, SERIAL_8N1, 32, 33 );
  M5.IMU.getAccelData(&accX, &accY, &accZ);
  M5.lcd.setCursor(0, 0);
  M5.lcd.setTextFont(2);
  M5.lcd.printf("%f, %f, %f", accX, accY, accZ);
  M5.lcd.setCursor(0, 40);
}

void loop() {
  M5.IMU.getAccelData(&accX,&accY,&accZ);
  sprintf(buf,"%f,%f,%f", accX, accY, accZ);
  Serial.println(buf);
  delay(5);
}

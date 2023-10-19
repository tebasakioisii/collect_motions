#include <Wire.h>

void send_command(int addr, int data) {
  Wire.beginTransmission(0x28);
  Wire.write(addr);
  Wire.write(data);
  Wire.endTransmission();
}

void setup() {
  Serial.begin(115200);
  Wire.begin();

  // set mode to config
  send_command(0x3D, 0x00);
  delay(10);

  // reset
  send_command(0x3F, 0x20);
  delay(10);

  // set normal power mode
  send_command(0x3E, 0x0);
  delay(10);

  // set page address 0
  send_command(0x07, 0x00);
  delay(10);

  // turn off reset
  send_command(0x3F, 0x00);
  delay(10);

  // set Mode to NDOF (get all data)
  send_command(0x3D, 0x0C);
  delay(20);

}

void loop() {

  // read acc and then send to PC via serial

  // read mag and then send to PC via serial

  // read gyr and then send to PC via serial

  Wire.requestFrom(0x28, 8, true);

  while (Wire.available()) {
    byte val = Wire.read();
    Serial.print(val);
  }

  delay(1000);
}

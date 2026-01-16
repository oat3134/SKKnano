#include<SKKnano.h>
SSD1306AsciiAvrI2c OLED;
#define I2C_ADDRESS 0x3C
#define RST_PIN -1
//////////////////////////////////////////////////////

void setup() {

  #if RST_PIN >= 0
    OLED.begin(&Adafruit128x32, I2C_ADDRESS, RST_PIN);
  #else // RST_PIN >= 0
    OLED.begin(&Adafruit128x32, I2C_ADDRESS);
  #endif // RST_PIN >= 0
  OLED.setI2cClock(200000); // ลดความเร็วลงเพื่อความเสถียร
  OLED.setFont(Adafruit5x7);
  OLED.clear();

}

void loop() {

  /////////// ตั้งค่าเซนเซอร์ตามการอ่านพอร์ตอนาล็อก S0,S1,S2,S3
  int s0 = analogRead(0);
  int s1 = analogRead(1);
  int s2 = analogRead(2);
  int s3 = analogRead(3);

 ////////////////////////////////////////////////////////

  OLED.setCursor(0, 0);       // เซตตำแหน่ง 0,0
  OLED.set1X();        // เซตขนาดอักษรมีขนาดเป็น 1
  OLED.print("       S0 = "); OLED.println(s0);  // แสดงค่าเซนเซอร์ S0
  OLED.print("       S1 = "); OLED.println(s1);  // แสดงค่าเซนเซอร์ S1
  OLED.print("       S2 = "); OLED.println(s2);  // แสดงค่าเซนเซอร์ S2
  OLED.print("       S3 = "); OLED.println(s3);  // แสดงค่าเซนเซอร์ S3
  delay(100);  // เปลี่ยนค่าเซนเซอร์ทุก 0.1 วินาที

}
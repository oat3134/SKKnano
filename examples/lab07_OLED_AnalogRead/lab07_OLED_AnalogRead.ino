#include<SKKnano.h>
//////////////////////////////////////////////////////

void setup() {

  OLED_begin(); // กำหนดแอดเดรสของพอร์ตจอเป็น 0x3C (for the 128x64)

}

void loop() {

  /////////// ตั้งค่าเซนเซอร์ตามการอ่านพอร์ตอนาล็อก S0,S1,S2,S3
  int s0 = analogRead(0);
  int s1 = analogRead(1);
  int s2 = analogRead(2);
  int s3 = analogRead(3);

 ////////////////////////////////////////////////////////

  OLED.clear();
  OLED.setCursor(0, 0);       // เซตตำแหน่ง 0,0
  OLED_setTextSize(1);        // เซตขนาดอักษรมีขนาดเป็น 1
  OLED.print("       S0 = "); OLED.println(s0);  // แสดงค่าเซนเซอร์ S0
  OLED.print("       S1 = "); OLED.println(s1);  // แสดงค่าเซนเซอร์ S1
  OLED.print("       S2 = "); OLED.println(s2);  // แสดงค่าเซนเซอร์ S2
  OLED.print("       S3 = "); OLED.println(s3);  // แสดงค่าเซนเซอร์ S3
  delay(100);  // เปลี่ยนค่าเซนเซอร์ทุก 0.1 วินาที

}
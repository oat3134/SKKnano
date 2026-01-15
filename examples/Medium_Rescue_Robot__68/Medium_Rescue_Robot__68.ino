////////////////////// เปิดใช้งาน เซอร์โว(Servo)บรรทัดที่ 20,21,22 //////////////////
#include <SKKnano.h>
Servo sv1, sv2, sv3;
///////////ตั้งค่าปุ่มกด///////////////////
int button = 2;  /// กำหนดปุ่มกดสวิตซ์ขา 2
////////ตัวแปรเก็บค่าแสงจากเซนเซอร์
int s0;
int s1;
int s2;
int s3;
int s4;
///////////////ตั้งพอร์ตเซอร์โว//////////////////////////////////
uint8_t servo1 = 10;
uint8_t servo2 = 11;
uint8_t servo3 = 12;

void setup() {
  Serial.begin(9600);
  OLED_begin();  // กำหนดแอดเดรสของพอร์ตจอเป็น 0x3C (for the 128x64)
  Motor_begin();
  ///////////// ตั้งพอร์ตเซอร์โว////////////
  sv_begin();
  sv_set(90);
}

bool sw;
uint16_t nob;
uint16_t menu;

void loop() {
  bool sw = digitalRead(button);        // ให้ sw อ่านค่า digital จากพอร์ต 2(button)
  uint16_t nob = analogRead(7);             // ให้ nob เทียบเท่าค่า A7
  uint16_t menu = map(nob, 0, 1023, 0, 5);  // เทียบอัตราส่วนของพอร์ต A7 จาก 0-1023 เพื่อทำเป็นเมนู 0-12
  OLED.setCursor(0, 0);                // เซตตำแหน่ง 0,0
  OLED.set2X();                 // เซตขนาดอักษรมีขนาดเป็น 2
  OLED.print(F("    "));                   // วรรค
  OLED.println(menu);                  // แสดงค่า Menu ที่ได้จากการ map nob ให้เหลือ 0-12
  OLED.set1X();                 // เซตขนาดอักษรมีขนาดเป็น 2
  OLED.println(F("  SKK--UTHAI--ROBOT  "));
  OLED.println(F(" "));
  OLED.print(nob);
  OLED.print(F("  "));  // วรรค
  OLED.print(F("MeNu"));
  OLED.print(F("  "));  // วรรค

  Serial.println(menu);
  #define switchs 1
  if ((sw == switchs) and (menu == 0)) {
    sensor();
  }
  if ((sw == switchs) and (menu == 1)) {
    set_servo();
  }
  if ((sw == switchs) and (menu == 2)) {
    menu2();
  }
  if ((sw == switchs) and (menu == 3)) {
    menu3();
  }
  if ((sw == switchs) and (menu == 4)) {
    menu4();
  }
  if ((sw == switchs) and (menu == 5)) {
    menu5();
  }
  delay(100);
}
///////////////////////////////////////////////////////////////////////

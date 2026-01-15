#include<SKKnano.h>

Servo sv1; // กำหนดชื่อเซอโวตัวที่ 1 ว่า sv1
const int buttonPin = 2; //ประกาศตัวแปร buttonPin แทน Pin ของปุ่มกด ซึ่งต่อไว้กับ D2

void setup() {
  OLED_begin(); // กำหนดแอดเดรสของพอร์ตจอเป็น 0x3C (for the 128x64)
  sv1.attach(10); //กำหนดขา Servo ตัวที่ 1 ต่อกับ Pin
}

void loop() {
  while(true){
    int vr = analogRead(A7);  // กำหนดตัวแปรจำนวนเต็มอ่านค่าอนาล็อกที่พอร์ต 7
    int nob = map(vr, 0, 1023, 0, 180); // ทำการ map อัตราส่วนจากสัญญาณ analog 0-1023 เป็น 0-180
    OLED.clear();    // เคลียร์หน้าจอ oled
    OLED.setCursor(0, 0);       // เซตตำแหน่ง 0,0
    OLED_setTextSize(2);        // เซตขนาดอักษรมีขนาดเป็น 2
    OLED.print("SV1 = ");     // พิมพ์คำว่า SV1 =
    OLED.println(nob);     // นำค่า nob มาแสดงใน oled
    sv1.write(nob);        // สั่งเซอร์โวมอเตอร์ให้หมุนไปตามค่าองศาที่ทำการ nob ไว้
    delay(100);             // หน่วงเวลา 0.05 วินาที
  }
}
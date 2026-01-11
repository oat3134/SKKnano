#include<SKKnano.h>

Servo sv1; // กำหนดชื่อเซอโวตัวที่ 1 ว่า sv1
const int buttonPin = 2; //ประกาศตัวแปร buttonPin แทน Pin ของปุ่มกด ซึ่งต่อไว้กับ D2

void setup() {
  sv1.attach(10); //กำหนดขา Servo ตัวที่ 1 ต่อกับ Pin
}

void loop(){
  int sw = digitalRead(buttonPin);
  if (sw == 1){		// ถ้าปุ่ม ถูกกด
    sv1.write(90); // เซอโว 1 หมุนไปที่ ตำแหน่ง 90 ํ
    delay(300); // หน่วงเวลาเพื่อรอให้เซอโวเคลื่อนที่ไปยังตำแหน่ง
    sv1.write(120); // เซอโว 1 หมุนไปที่ ตำแหน่ง 120 ํ
    delay(300); // หน่วงเวลาเพื่อรอให้เซอโวเคลื่อนที่ไปยังตำแหน่ง
  }
}

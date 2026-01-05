////////////////////// เปิดใช้งาน เซอร์โว(Servo)บรรทัดที่ 20,21,22 //////////////////
#include <SKKnano.h>
Servo sv1, sv2, sv3;
///////////ตั้งค่าปุ่มกด///////////////////
int button = 2;  /// กำหนดปุ่มกดสวิตซ์ขา 2
////////ตัวแปรเก็บค่าแสงจากเซนเซอร์
int S0;
int S1;
int S2;
int S3;
int S4;
///////////////ตั้งพอร์ตเซอร์โว//////////////////////////////////
int servo1 = 10;
int servo2 = 11;
int servo3 = 12;

void setup() {
  OLED_Begin();  // กำหนดแอดเดรสของพอร์ตจอเป็น 0x3C (for the 128x64)
  MotorBegin();
  ///////////// ตั้งพอร์ตเซอร์โว////////////
  sv1.attach(servo1);  // เรียกใช้งานเตรียมตอบสนองเซอร์โว sv1
  sv2.attach(servo2);  // เรียกใช้งานเตรียมตอบสนองเซอร์โว sv2
  sv3.attach(servo3);  // เรียกใช้งานเตรียมตอบสนองเซอร์โว sv3
  sv_set();
}
void set_servo() {
  while (1) {
    int vr = analogRead(A7);             // กำหนดตัวแปรจำนวนเต็มอ่านค่าอนาล็อกที่พอร์ต 7
    int nob = map(vr, 0, 1023, 0, 180);  // ทำการ map อัตราส่วนจากสัญญาณ analog 0-1023 เป็น 0-180
    setTextSize(2);
    OLED_println(0,0,nob);
    sv1.write(nob);  // สั่งเซอร์โวมอเตอร์ให้หมุนไปตามค่าองศาที่ทำการ nob ไว้
    sv2.write(nob);  // สั่งเซอร์โวมอเตอร์ให้หมุนไปตามค่าองศาที่ทำการ nob ไว้
    sv3.write(nob);  // สั่งเซอร์โวมอเตอร์ให้หมุนไปตามค่าองศาที่ทำการ nob ไว้
    delay(50);       // หน่วงเวลา 0.05 วินาที
  }
}
void analogs() {
  S0 = analogRead(0);  // กำหนดตัวแปรเพื่อเก็บค่า ADC Ch0
  S1 = analogRead(1);  // กำหนดตัวแปรเพื่อเก็บค่า ADC Ch1
  S2 = analogRead(2);  // กำหนดตัวแปรเพื่อเก็บค่า ADC Ch2
  S3 = analogRead(3);  // กำหนดตัวแปรเพื่อเก็บค่า ADC Ch3
  S4 = analogRead(6);  // กำหนดตัวแปรเพื่อเก็บค่า ADC Ch4
}
void sensor() {
  while (true) {
    analogs();
    OLED.clearDisplay();   //ล้างหน้าจอ
    OLED.setTextColor(WHITE,BLACK);   //สีอักษรเป็นสีขาว ,พื้นหลังดำ  จอที่ใช้ไม่สามารถเปลี่ยนสีได้
    OLED.setCursor(0, 0);       // เซตตำแหน่ง 0,0
    OLED.setTextSize(1);        // เซตขนาดอักษรมีขนาดเป็น 2
    OLED.print(" S0 : ");              //  แสดงข้อความ S0 :
    OLED.print(S0,DEC);      //  แสดงค่า S0
    OLED.print(" S1 : ");          //  แสดงข้อความ S1 :
    OLED.println(S1,DEC);      //  แสดงค่า S1
    OLED.print(" S2 : ");          //  แสดงข้อความ S2 :
    OLED.println(S2,DEC);      //  แสดงค่า S2
    OLED.print(" S3 : ");          //  แสดงข้อความ S3 :
    OLED.print(S3,DEC);      //  แสดงค่า S3
    OLED.print(" S4 : ");          //  แสดงข้อความ S5 :
    OLED.println(S4,DEC);
    delay(100);
  }
}
void loop() {
  int sw = digitalRead(button);        // ให้ sw อ่านค่า digital จากพอร์ต 2(button)
  int nob = analogRead(7);             // ให้ nob เทียบเท่าค่า A7
  int menu = map(nob, 0, 1023, 0, 5);  // เทียบอัตราส่วนของพอร์ต A7 จาก 0-1023 เพื่อทำเป็นเมนู 0-12
  OLED.clearDisplay();                 // ล้างค่าหน้าจอ
  OLED.setTextColor(WHITE, BLACK);     //สีอักษรเป็นสีขาว ,พื้นหลังดำ
  OLED.setCursor(0, 0);                // เซตตำแหน่ง 0,0
  OLED.setTextSize(3);                 // เซตขนาดอักษรมีขนาดเป็น 2
  OLED.print("   ");                   // วรรค
  OLED.println(menu);                  // แสดงค่า Menu ที่ได้จากการ map nob ให้เหลือ 0-12
  OLED.setTextSize(1);                 // เซตขนาดอักษรมีขนาดเป็น 2
  OLED.println(" ");
  OLED.println("  SKK--UTHAI--ROBOT  ");
  OLED.println(" ");
  OLED.print("  ");  // วรรค
  OLED.println("      MeNu");
  OLED.display();
  int switchs = 1;
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

//////// ผนวกไลบรารี่ ////////////
#include<SKKnano.h>

///////////ตั้งค่าปุ่มกด///////////////////
int button =  2; /// กำหนดปุ่มกดสวิตซ์ขา 2

int ss1 = 10;  // เปิดใช้งาน s1 ที่พอร์ต 10
Servo sv1;     // ประกาศการใช้งาน sv1

////////////ตั้งค่าพอร์ตมอเตอร์////////////////////
#define DR1  7  /// กำหนดสัญญาณดิจิตอลขวาที่ 1 พอร์ต 7
#define DR2  8  /// กำหนดสัญญาณดิจิตอลขวาที่ 2 พอร์ต 8
#define PWMR 6 /// กำหนดสัญญาณ PWM ขวาพอร์ต 6
/////////////////////////////////
#define DL1  4  // กำหนดสัญญาณดิจิตอลซ้ายที่ 1 พอร์ต 9
#define DL2  9  // กำหนดสัญญาณดิจิตอลซ้ายที่ 2 พอร์ต 4
#define PWML 5  /// กำหนดสัญญาณ PWM ซ้ายพอร์ต 5

/////////////////ตั้งค่าพอร์ต Analog//////////////
#define a0 500 // ค่ากลางเซนเซอร์ A0 (ซ้ายสุด)
#define a1 500// ค่ากลางเซนเซอร์ A1 (ซ้ายกลาง)
#define a2 500 // ค่ากลางเซนเซอร์ A2 (ขวากลาง)
#define a3 500// ค่ากลางเซนเซอร์ A3 (ขวาสุด)

///////////////////////////////////////////////
int s0,s1,s2,s3,s4 ;

//////////////////////////////////////////////

void setup() {
  OLED_begin(); // กำหนดแอดเดรสของพอร์ตจอ
  pinMode(2, INPUT); // ตั้งค่าขา 2 เป็น INPUT
  ////////กำหนดสัญญาณทุกขาเป็น OUTPUT /////////
  pinMode(DL1, OUTPUT);
  pinMode(DL2, OUTPUT);
  pinMode(PWML, OUTPUT);
  pinMode(DR1, OUTPUT);
  pinMode(DR2, OUTPUT);
  pinMode(PWMR, OUTPUT);
  sv1.attach(ss1); // เรียกใช้งานเตรียมตอบสนองเซอร์โว sv1
  sv_set();
}

void loop() {
  int sw = digitalRead(button);     // ให้ sw อ่านค่า digital จากพอร์ต 2(button)
  int nob = analogRead(7);          // ให้ nob เทียบเท่าค่า A7
  int menu = map(nob, 0, 1023, 0, 10); // เทียบอัตราส่วนของพอร์ต A7 จาก 0-1023 เพื่อทำเป็นเมนู 0-12
  OLED.clear();              // ล้างค่าหน้าจอ
  OLED.setCursor(0, 0);       // เซตตำแหน่ง 0,0
  OLED_setTextSize(2);        // เซตขนาดอักษรมีขนาดเป็น 2
  OLED.print("   ");         // วรรค
  OLED.println(menu);        // แสดงค่า Menu ที่ได้จากการ map nob ให้เหลือ 0-12
  OLED_setTextSize(1);        // เซตขนาดอักษรมีขนาดเป็น 2
  OLED.println("  SKK");     // พิมพ์คำว่า kruro
  OLED.print("  ");                      // วรรค
  OLED.print(nob);                     // แสดงค่าที่อ่านได้จาก nob หรือ Analog7
  OLED.println(" Robot");     // พิมพ์คำว่า Robot
  #define mode 1
  if ((sw == mode) and (menu == 0)){sensor_linef();}
  if ((sw == mode) and (menu == 1)){sv_knob();}
  if ((sw == mode) and (menu == 2)){menu2();}
  if ((sw == mode) and (menu == 3)){menu3();}
  if ((sw == mode) and (menu == 4)){menu4();}
  if ((sw == mode) and (menu == 5)){menu5();}
  if ((sw == mode) and (menu == 6)){menu6();}
  if ((sw == mode) and (menu == 7)){menu7();}
  if ((sw == mode) and (menu == 8)){menu8();}
  if ((sw == mode) and (menu == 9)){menu9();}
  if ((sw == mode) and (menu == 10)){menu10();}
  delay(100);
}

void sensor_linef(){
  while (true) {
    analogs();
    OLED.clear();
    OLED.setCursor(0, 0);       // เซตตำแหน่ง 0,0
    OLED_setTextSize(1);        // เซตขนาดอักษรมีขนาดเป็น 1
    OLED.print("       S0 = "); OLED.println(s0);  // แสดงค่าเซนเซอร์ S0
    OLED.print("       S1 = "); OLED.println(s1);  // แสดงค่าเซนเซอร์ S1
    OLED.print("       S2 = "); OLED.println(s2);  // แสดงค่าเซนเซอร์ S2
    OLED.print("       S3 = "); OLED.println(s3);  // แสดงค่าเซนเซอร์ S3
    delay(50);
  }
}

/////////////////////////////ฟังก์ชันเซอร์โว////////////////////////////////////////
void sv_knob() {
  while(true){
    int vr = analogRead(A7);  // กำหนดตัวแปรจำนวนเต็มอ่านค่าอนาล็อกที่พอร์ต 7
    int nob = map(vr, 0, 1023, 0, 180); // ทำการ map อัตราส่วนจากสัญญาณ analog 0-1023 เป็น 0-180
    OLED.clear();    // เคลียร์หน้าจอ oled
    OLED.setCursor(0, 0);       // เซตตำแหน่ง 0,0
    OLED_setTextSize(2);        // เซตขนาดอักษรมีขนาดเป็น 2
    OLED.print("SV = ");     // พิมพ์คำว่า SV1 =
    OLED.println(nob);     // นำค่า nob มาแสดงใน oled
    sv1.write(nob);        // สั่งเซอร์โวมอเตอร์ให้หมุนไปตามค่าองศาที่ทำการ nob ไว้
    delay(50);             // หน่วงเวลา 0.05 วินาที
  }
}

/////////////////////////ฟังก์ชันเส้นทาง////////////////////////////////////////
void P()     ///////////// ฟังก์ชันแทกเส้นเจอคู่ดำหยุด/////////////////////////////
{
  while (1){
    analogs();
    if (((s0<a0)and(s1<a1))or((s2<a2)and(s3<a3))){
      run(100, 100);delay(180);run(0, 0);delay(100);break; // หยุดคำสั่ง
    }
    else if(s0<a0){ // S0
      run(-40,100);
    }
    else if(s1<a1){ // S1
      run(70,100);
    }
    else if(s2<a2){ // S2
      run(100,70);
    }
    else if(s3<a3){ // S3
      run(100,-40);
    }
    else{
      run(100,100);
    }
  }
}
//////////////////////////////////////////////////////////////////////////////////
void P(unsigned long t)
{
  unsigned long start = millis();
  while (1) {
    analogs();
    if (millis() - start >= t){
      run(0, 0);break;          //หยุดคำสั่ง
    }
    else if(((s0<a0)and(s1<a1))or((s2<a2)and(s3<a3))){
      run(100,100);
    }
    else if(s0<a0){ // S0
      run(-40,100);
    }
    else if(s1<a1){ // S1
      run(70,100);
    }
    else if(s2<a2){ // S2
      run(100,70);
    }
    else if(s3<a3){ // S3
      run(100,-40);
    }
    else{
      run(100,100);
    }

  }
}

//////////////////////////////////////////////////////////////////////////////////

void b(){run(-75,-70);delay(1000);run(0,0);delay(600);} // ถอยหลัง

/////////////////////// ฟังก์ชันเซฮร์โว //////////////////////////
void sv_set()   // เซตเซอร์โว
{
  sv1.write(90); // ค่าองศาเซอร์โวตอนเปิดบอร์ด
}

void up(){ // เซอร์โวยก
  sv1.write(30);
  delay(500);
}

void down(){ // เซอร์โววาง
  sv1.write(60);
  delay(500);
}

/////////////////////////เลี้ยวซ้าย///////////////////////////////////////////
void L(){L0();L1();delay(100);} /////// เลี้ยวซ้าย
void L0(){while (1){analogs();run(-150,150);if(s0<A0){run(0,0);break;}}} //S0
void L1(){while (1){analogs();run(-150,150);if(s1<A1){run(0,0);break;}}} //S1
void L2(){while (1){analogs();run(-150,150);if(s2<A2){run(0,0);break;}}} //S2

//////////////////////เลี้ยวขวา//////////////////////////////////////////
void R(){R0();R1();delay(100);} ///////// เลี้ยว
void R0(){while (1){analogs();run(150,-150);if(s3<A3){run(0,0);break;}}} //S0
void R1(){while (1){analogs();run(150,-150);if(s2<A2){run(0,0);break;}}} //S1
void R2(){while (1){analogs();run(150,-150);if(s1<A1){run(0,0);break;}}} //S2

//////////////////////////////// เรียกใช้ code menu ////////////////////////////////////////
/*
  P();
  P(เวลา);
  b();
  L();
  R();
  up();
  down();
*/
void menu2()   /// code 2 ที่นี่
{

  //ใส่คำสั่ง

}

void menu3()   /// code 3 ที่นี่
{

  down();P();R();P();L();P();up();R();down();

}

void menu4()   /// code 4 ที่นี่
{

  P();

}

void menu5()   /// code 5 ที่นี่
{

  L();

}

void menu6()   /// code 6 ที่นี่
{

  R();

}

void menu7()   /// code 7 ที่นี่
{

  b();

}

void menu8()   /// code 8 ที่นี่
{

  down();

}

void menu9()   /// code 9 ที่นี่
{

  up();

}

void menu10()   /// code 9 ที่นี่
{

  run(200,200);delay(1000);run(0,0);delay(1000);
  run(-200,200);delay(1000);run(0,0);delay(1000);
  run(200,-200);delay(1000);run(0,0);delay(1000);
  run(-200,-200);delay(1000);run(0,0);delay(1000);

}

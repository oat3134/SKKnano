#include "SKKnano.h"

SSD1306AsciiAvrI2c OLED;
#define I2C_ADDRESS 0x3C
#define RST_PIN -1

byte size_Text_OLED = 0;

// ฟังก์ชัน OLED
void OLED_begin() {
  OLED.begin(&Adafruit128x32, I2C_ADDRESS, RST_PIN);
  OLED.setI2cClock(400000); // ลดความเร็วลงเพื่อความเสถียร
  OLED.setFont(Adafruit5x7);
}

void OLED_setTextSize(byte size_t) {
  if(size_t == 1){
    OLED.set1X();
  }
  else{
    OLED.set2X();
  }
}

// ฟังก์ชัน Motor
void Motor_begin() {
  pinMode(DL1, OUTPUT);
  pinMode(DL2, OUTPUT);
  pinMode(PWML, OUTPUT);
  pinMode(DR1, OUTPUT);
  pinMode(DR2, OUTPUT);
  pinMode(PWMR, OUTPUT);
}

void run(int spl, int spr) {
  // ซ้าย
  if (spl > 0) {
    digitalWrite(DL1, LOW);
    digitalWrite(DL2, HIGH);
    analogWrite(PWML, spl);
  } else if (spl < 0) {
    digitalWrite(DL1, HIGH);
    digitalWrite(DL2, LOW);
    analogWrite(PWML, abs(spl));
  } else {
    digitalWrite(DL1, HIGH);
    digitalWrite(DL2, HIGH);
  }
  // ขวา
  if (spr > 0) {
    digitalWrite(DR1, LOW);
    digitalWrite(DR2, HIGH);
    analogWrite(PWMR, spr);
  } else if (spr < 0) {
    digitalWrite(DR1, HIGH);
    digitalWrite(DR2, LOW);
    analogWrite(PWMR, abs(spr));
  } else {
    digitalWrite(DR1, HIGH);
    digitalWrite(DR2, HIGH);
  }
}

void test_motor(){
  run(100,100);delay(500);run(0,0);delay(500);
  run(-100,100);delay(500);run(0,0);delay(500);
  run(100,-100);delay(500);run(0,0);delay(500);
  run(-100,-100);delay(500);run(0,0);delay(500);
}

///////////////////////////////////////////////////////////////////////////////////////////

extern Servo sv1, sv2, sv3;
extern uint8_t servo1,servo2,servo3;

void sv_begin(){
  sv1.attach(servo1);  // เรียกใช้งานเตรียมตอบสนองเซอร์โว sv1
  sv2.attach(servo2);  // เรียกใช้งานเตรียมตอบสนองเซอร์โว sv2
  sv3.attach(servo3);  // เรียกใช้งานเตรียมตอบสนองเซอร์โว sv3
}

void set_servo() {
  OLED.clear();
  while (1) {
    int vr = analogRead(A7);             // กำหนดตัวแปรจำนวนเต็มอ่านค่าอนาล็อกที่พอร์ต 7
    uint8_t nob = map(vr, 0, 1023, 0, 180);  // ทำการ map อัตราส่วนจากสัญญาณ analog 0-1023 เป็น 0-180
    OLED.set2X();
    OLED.setCursor(0,0);
    OLED.print(nob);
    OLED.print(F(" "));
    sv1.write(nob);  // สั่งเซอร์โวมอเตอร์ให้หมุนไปตามค่าองศาที่ทำการ nob ไว้
    sv2.write(nob);  // สั่งเซอร์โวมอเตอร์ให้หมุนไปตามค่าองศาที่ทำการ nob ไว้
    sv3.write(nob);  // สั่งเซอร์โวมอเตอร์ให้หมุนไปตามค่าองศาที่ทำการ nob ไว้
    delay(50);       // หน่วงเวลา 0.05 วินาที
  }
}

void sv_set(byte angle)   // เซตเซอร์โว
{
  sv1.write(angle);// ค่าองศาเซอร์โวตอนเปิดบอร์ด....ยกมือลง
  sv2.write(angle);
  sv3.write(angle);
}

extern uint8_t v_go;
extern uint8_t v_standby;

void paste() //ทิ้งถุงยังชีพ==
{
  sv1.write(v_go);delay(500);
  sv1.write(v_standby);delay(500); 
}

void UP() //ยก==
{
  sv1.write(v_go);delay(500);
}

void DOWN() //ลง==
{
  sv1.write(v_standby);delay(500);
}

///////////////////////////////////////////////////////////////////////////////////////////

extern int s0,s1,s2,s3,s4;

void analogs() {
  s0 = analogRead(0);  // กำหนดตัวแปรเพื่อเก็บค่า ADC Ch0
  s1 = analogRead(1);  // กำหนดตัวแปรเพื่อเก็บค่า ADC Ch1
  s2 = analogRead(2);  // กำหนดตัวแปรเพื่อเก็บค่า ADC Ch2
  s3 = analogRead(3);  // กำหนดตัวแปรเพื่อเก็บค่า ADC Ch3
  s4 = analogRead(6);  // กำหนดตัวแปรเพื่อเก็บค่า ADC Ch4
}

void sensor()
{
  OLED.clear();
  
  while (true) {
    uint16_t vr = analogRead(7);
    analogs();
    
    int s_values[] = {s0, s1, s2, s3, s4}; 
    int total_items = 5;
    
    int lines_per_screen = 4; 
    
    int startIndex = map(vr, 0, 1023, 0, (total_items - lines_per_screen) + 1); 
    
    if (startIndex > total_items - lines_per_screen) {
        startIndex = total_items - lines_per_screen;
    }
    if (startIndex < 0) startIndex = 0;

    OLED.set1X(); 
    for (int i = 0; i < lines_per_screen; i++) {
      int currentDataIndex = startIndex + i; 

      OLED.setCursor(0, i); 
      
      OLED.print(F("    S"));
      OLED.print(currentDataIndex);
      OLED.print(F(" : "));
      OLED.print(s_values[currentDataIndex]);
      
      OLED.clearToEOL(); 
    }
    
    delay(50); 
  }
}

///////////////////////////////////////////////////////////////////////////////////////////

extern int cen0,cen1,cen2,cen3,cen4;
extern uint8_t fl,fr,bl,br;
extern uint8_t mfl,mfr,mbl,mbr;

void T() //ตัวหลักสำหรับแก้ความเร็วบนเส้นทางท้งหมด
{
  analogs();    
  if (s0 < cen0) {run(mfl, -mfr);}
  else if (s2 < cen2) {run(-mfl, mfr);}
  else{run(fl,fr);}
}

void T(byte sp) //ตัวหลักสำหรับแก้ความเร็วบนเส้นทางท้งหมด
{
  analogs();    
  if (s0 < cen0) {run(mfl, -mfr);}
  else if (s2 < cen2) {run(-mfl, mfr);}
  else{run(sp,sp);}
}

void FT() //เดินหน้า==ถ้าเซนเซอร์ S1 เจอดำ หยุดและถอยหลังมากลางช่อง==
{
  while (1){
    analogs();  
    if (s1 < cen1) {
      run(-100,-100); delay(400);
      run(0,0); delay(100); break;
    }
    else{
      T();
    }
  }
}

void FT(byte sp) //เดินหน้า==ถ้าเซนเซอร์ S1 เจอดำ หยุดและถอยหลังมากลางช่อง==
{
  while (1){
    analogs();  
    if (s1 < cen1) {
      run(-100,-100); delay(400);
      run(0,0); delay(100); break;
    }
    else{
      T(sp);
    }
  }
}

void FF(int T)  //เดินหน้า=กรณีที่จุด start เป็นพื้นที่ที่เซ็นเซอร์ไม่สามารถวัดค่าแบบตายตัวได้
{ 
 run(fl,fr);delay(T); run(0,0); delay(10);  
}

void FF(int T,byte sp)  //เดินหน้า=กรณีที่จุด start เป็นพื้นที่ที่เซ็นเซอร์ไม่สามารถวัดค่าแบบตายตัวได้
{ 
 run(sp,sp);delay(T); run(0,0); delay(10);  
}

void FD(unsigned long t) //เดินหน้า=โดยใช้เซนเซอร์จนกว่าจะหมดเวลา
{
  unsigned long start = millis();
  while (1) {
    if (millis() - start >= t) {run(0, 0);break;} //หยุดคำสั่ง
    else{
      T();
    }
    
  }
}

void FD(unsigned long t,byte sp) //เดินหน้า=โดยใช้เซนเซอร์จนกว่าจะหมดเวลา
{
  unsigned long start = millis();
  while (1) {
    if (millis() - start >= t) {run(0, 0);break;} //หยุดคำสั่ง
    else{
      T(sp);
    }
    
  }
}

void FPP() //เดินหน้า ==ถ้าเซนเซอร์ทั้ง 3 ตัวเจอดำ หยุดนิ่ง เพื่อที่จะทิ้งถุงยังชีพ==
{
  while (1){
    analogs();
    if ((s0 < cen0) and (s2 < cen2)) {run(0,0); break;}
    else if (s0 < cen0) {run(-mfl,mfr);}
    else if (s2 < cen2) {run(mfl,-mfr);}
    else{run(fl,fr);}   
  }    
}

void FPP(byte sp) //เดินหน้า ==ถ้าเซนเซอร์ทั้ง 3 ตัวเจอดำ หยุดนิ่ง เพื่อที่จะทิ้งถุงยังชีพ==
{
  while (1){
    analogs();
    if ((s0 < cen0) and (s2 < cen2)) {run(0,0); break;}
    else if (s0 < cen0) {run(-mfl,mfr);}
    else if (s2 < cen2) {run(mfl,-mfr);}
    else{run(sp,sp);}
  }    
}

void LD(int T) {run(-170,170);delay(T); run(0,0); delay(10);}
void LD(int T,byte sp) {run(-sp,sp);delay(T); run(0,0); delay(10);}
void RD(int T) {run(170,-170);delay(T); run(0,0); delay(10);}
void RD(int T,byte sp) {run(sp,-sp);delay(T); run(0,0); delay(10);}

void B() //ถอยหลัง==โดยใช้เซนเซอร์ 2 ตัวข้างหลัง
{
  while(1) {
    analogs();
    if ((s3 < cen3) and (s4 < cen4)) {
      run(0,0);delay(100);run(100,100);delay(200);run(0,0);delay(100); break;
    }
    else if (s3 < cen3) {run(mbl, -mbr);}
    else if (s4 < cen4) {run(-mbl, mbr);}
    else {run(bl,br);} 
  }
}

void B(byte sp) //ถอยหลัง==โดยใช้เซนเซอร์ 2 ตัวข้างหลัง
{
  while(1) {
    analogs();
    if ((s3 < cen3) and (s4 < cen4)) {
      run(0,0);delay(100);run(100,100);delay(200);run(0,0);delay(100); break;
    }
    else if (s3 < cen3) {run(mbl, -mbr);}
    else if (s4 < cen4) {run(-mbl, mbr);}
    else {run(sp,sp);} 
  }
}

void BD(int t){
    run(-bl,-br);delay(t);run(0,0);delay(100);
}

void BD(int t,byte sp){
    run(-sp,-sp);delay(t);run(0,0);delay(100);
}
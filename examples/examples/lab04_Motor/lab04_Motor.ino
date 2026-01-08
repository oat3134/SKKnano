#define PWML  5  //   motor L
#define IN1L  4  //
#define IN2L  9  //

#define PWMR  6  //   motor R
#define IN1R  7  //
#define IN2R  8  //

#define buttonPin 2

void setup() {
  pinMode(buttonPin,INPUT);
  pinMode(PWML,OUTPUT);
  pinMode(IN1L,OUTPUT);
  pinMode(IN2L,OUTPUT);
  pinMode(PWMR,OUTPUT);
  pinMode(IN1R,OUTPUT);
  pinMode(IN2R,OUTPUT);
}

void loop(){
  int sw = digitalRead(buttonPin);  //กำหนดตัวแปร sw ให้มีค่าเท่ากับ ค่าที่อ่านได้จาก digital Pin 2  หรือ ปุ่ม OK บนบอร์ด
  if (sw==1){
    run(100,100);delay(500);    //มอเตอร์ ซ้ายและขวาหมุนไปข้างหน้า        ความเร็ว 100 หน่วงเวลา 500 มิลลิวินาที
    run(100,-100);delay(500);   //มอเตอร์ ซ้ายเดินหน้า มอเตอร์ขวาถอยหลัง    ความเร็ว 100 หน่วงเวลา 500 มิลลิวินาที
    run(100,100);delay(500);    //มอเตอร์ ซ้ายและขวาหมุนไปข้างหน้า         ความเร็ว 100 หน่วงเวลา 500 มิลลิวินาที
    run(100,-100);delay(500);   //มอเตอร์ ซ้ายเดินหน้า มอเตอร์ขวาถอยหลัง    ความเร็ว 100 หน่วงเวลา 500 มิลลิวินาที
    run(100,100);delay(500);    //มอเตอร์ ซ้ายและขวาหมุนไปข้างหน้า         ความเร็ว 100 หน่วงเวลา 500 มิลลิวินาที
    run(100,-100);delay(500);   //มอเตอร์ ซ้ายเดินหน้า มอเตอร์ขวาถอยหลัง    ความเร็ว 100 หน่วงเวลา 500 มิลลิวินาที
    run(100,100);delay(500);    //มอเตอร์ ซ้ายและขวาหมุนไปข้างหน้า         ความเร็ว 100 หน่วงเวลา 500 มิลลิวินาที
    run(100,-100);delay(500);   //มอเตอร์ ซ้ายเดินหน้า มอเตอร์ขวาถอยหลัง    ความเร็ว 100 หน่วงเวลา 500 มิลลิวินาที
    run(0,0);                   //มอเตอร์ซ้ายและขวาหยุด
  }                 
}

void run(int spl, int spr)   // ประกาศฟังก์ชัน run(กำลังมอเตอร์ซ้าาย,กำลังมอเตอร์ขวา);
{
  if (spl > 0){
    digitalWrite(IN1L, LOW);
    digitalWrite(IN2L, HIGH);
    analogWrite(PWML, spl);
  }
  else if (spl < 0){ 
    spl= abs(spl);
    digitalWrite(IN1L, HIGH);
    digitalWrite(IN2L, LOW);
    analogWrite(PWML, spl);
  }
  else{
    digitalWrite(IN1L, HIGH);
    digitalWrite(IN2L, HIGH);
  }
  //////////////////////////////////////
  if (spr > 0){
    digitalWrite(IN1R, LOW);
    digitalWrite(IN2R, HIGH);
    analogWrite(PWMR, spr);
  }
  else if (spr < 0){
    spr= abs(spr);
    digitalWrite(IN1R, HIGH);
    digitalWrite(IN2R, LOW);
    analogWrite(PWMR, spr);
  }
  else{
    digitalWrite(IN1R, HIGH);
    digitalWrite(IN2R, HIGH);
  }
}
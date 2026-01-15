#include <Wire.h>
#include <SPI.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 OLED(-1);


#define PWML  5  //   motor L
#define IN1L  4  //
#define IN2L  9  //

#define PWMR  6  //   motor R
#define IN1R  7  //
#define IN2R  8  //

#define buttonPin 2

void setup() {
  OLED.begin(SSD1306_SWITCHCAPVCC, 0x3C); // กำหนดแอดเดรสของพอร์ตจอเป็น 0x3C (for the 128x64)
  pinMode(buttonPin,INPUT);
  pinMode(PWML,OUTPUT);
  pinMode(IN1L,OUTPUT);
  pinMode(IN2L,OUTPUT);
  pinMode(PWMR,OUTPUT);
  pinMode(IN1R,OUTPUT);
  pinMode(IN2R,OUTPUT);
}

void loop(){
  OLED.clearDisplay();              // ล้างค่าหน้าจอ
  OLED.setTextColor(WHITE, BLACK);  //สีอักษรเป็นสีขาว ,พื้นหลังดำ
  OLED.setCursor(0, 0);       // เซตตำแหน่ง 0,0
  OLED.setTextSize(1);        // เซตขนาดอักษรมีขนาดเป็น 2
  OLED.print("LAB Motor");         // วรรค
  OLED.display();
  int sw = digitalRead(buttonPin);  //กำหนดตัวแปร sw ให้มีค่าเท่ากับ ค่าที่อ่านได้จาก digital Pin 2  หรือ ปุ่ม OK บนบอร์ด
  if (sw==1){
    run(200,200);delay(500);run(0,0);delay(500);
    run(-200,200);delay(500);run(0,0);delay(500);
    run(200,-200);delay(500);run(0,0);delay(500);
    run(-200,-200);delay(500);run(0,0);delay(500);
    run(0,0);                   //มอเตอร์ซ้ายและขวาหยุด
  }                 
}

void run(int spl, int spr)   // ประกาศฟังก์ชัน run(กำลังมอเตอร์ซ้าาย,กำลังมอเตอร์ขวา);
{
  if (spl > 0){
    spl= abs(spl);
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
    spr= abs(spr);
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
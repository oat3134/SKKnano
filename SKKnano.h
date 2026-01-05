#ifndef SKKnano
#define SKKnano

#include"SPI.h"
#include"Wire.h"
#include"Servo.h"
#include"Adafruit_GFX.h"
#include"Adafruit_SSD1306.h"
#include"Adafruit_MCP3008.h"
#include"MechaQMC5883.h"

///////////////////////////////////////////////////////////////////////////
Adafruit_SSD1306 OLED(-1);

byte size_Text_OLED = 0;

void OLED_Begin(){
   OLED.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}

void setTextSize(byte size_t){
      size_Text_OLED = size_t;
}

void OLED_println(byte x,byte y,String word){
    OLED.clearDisplay();
    OLED.setTextColor(WHITE, BLACK);
    OLED.setCursor(x, y);
    OLED.setTextSize(size_Text_OLED);
    OLED.println(word);
    OLED.display();
}

void OLED_println(byte x,byte y,int number){
    OLED_println(x,y,String(number));
}

void OLED_print(byte x,byte y,String word){
    OLED.clearDisplay();
    OLED.setTextColor(WHITE, BLACK);
    OLED.setCursor(x, y);
    OLED.setTextSize(size_Text_OLED);
    OLED.print(word);
    OLED.display();
}

void OLED_print(byte x,byte y,int number){
    OLED_print(x,y,String(number));
}

///////////////////////////////////////////////////////////////////////////
#define DR1  7  /// กำหนดสัญญาณดิจิตอลขวาที่ 1 พอร์ต 7
#define DR2  8  /// กำหนดสัญญาณดิจิตอลขวาที่ 2 พอร์ต 8
#define PWMR 6 /// กำหนดสัญญาณ PWM ขวาพอร์ต 6

#define DL1  4  // กำหนดสัญญาณดิจิตอลซ้ายที่ 1 พอร์ต 9
#define DL2  9  // กำหนดสัญญาณดิจิตอลซ้ายที่ 2 พอร์ต 4
#define PWML 5  /// กำหนดสัญญาณ PWM ซ้ายพอร์ต 5

void MotorBegin(){
      pinMode(DL1, OUTPUT);
      pinMode(DL2, OUTPUT);
      pinMode(PWML, OUTPUT);
      pinMode(DR1, OUTPUT);
      pinMode(DR2, OUTPUT);
      pinMode(PWMR, OUTPUT);
}

void run(int spl, int spr)
{
  if (spl > 0)
  {
    digitalWrite(DL1, LOW);
    digitalWrite(DL2, HIGH);
    analogWrite(PWML, spl);
  }

  else if (spl < 0)
  {
    spl=abs(spl);
    digitalWrite(DL1, HIGH);
    digitalWrite(DL2, LOW);
    analogWrite(PWML, spl);
  }
  else
  {
    digitalWrite(DL1, HIGH);
    digitalWrite(DL2, HIGH);
  }
  if (spr > 0)
  {
    digitalWrite(DR1, LOW);
    digitalWrite(DR2, HIGH);
    analogWrite(PWMR, spr);
  }
  else if (spr < 0)
  {
    spr=abs(spr);
    digitalWrite(DR1, HIGH);
    digitalWrite(DR2, LOW);
    analogWrite(PWMR, spr);
  }
  else
  {
    digitalWrite(DR1, HIGH);
    digitalWrite(DR2, HIGH);
  }
}

///////////////////////////////////////////////////////////////////////////
MechaQMC5883 qmc;

void cpset() {
  Wire.begin();
  qmc.init();
}

int cp()
{     int x, y, z;
      int a;
      qmc.read(&x, &y, &z,&a);
	return (a);
}
int cpx()
{     int x, y, z;
      int a;
      qmc.read(&x, &y, &z,&a);
	return (x);
}
int cpy()
{     int x, y, z;
      int a;
      qmc.read(&x, &y, &z,&a);
	return (y);
}
int cpz()
{     int x, y, z;
      int a;
      qmc.read(&x, &y, &z,&a);
	return (z);
}
/////////////////////////////////


#endif
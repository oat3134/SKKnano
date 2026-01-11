#ifndef SKKnano_h
#define SKKnano_h

#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Servo.h>
#include <MechaQMC5883.h>
#include <SSD1306Ascii.h>
#include <SSD1306AsciiAvrI2c.h>

// ประกาศตัวแปรภายนอก (ใช้ extern เพื่อให้แชร์ตัวแปรร่วมกันได้)
extern SSD1306AsciiAvrI2c OLED;
extern MechaQMC5883 qmc;

// ส่วน OLED
void OLED_begin();
void OLED_setTextSize(byte size_t);
void OLED_println(byte x, byte y, String word);
void OLED_println(byte x, byte y, int number);
void OLED_print(byte x, byte y, String word);
void OLED_print(byte x, byte y, int number);
void OLED_startMenu();

// ส่วน Motor
#define DR1  7
#define DR2  8
#define PWMR 6
#define DL1  4
#define DL2  9
#define PWML 5

void Motor_begin();
void run(int spl, int spr);
void test_motor();

// ส่วน Compass
void cpset();
int cp();
int cpx();
int cpy();
int cpz();

// ส่วน Servo
void sv_begin();
void set_servo();
void sv_set(byte angle);
void paste();
void UP();
void DOWN();

// ส่วน Sensor
void analogs();
void sensor();

// ส่วน ฟังชัน หุ่นยนต์ระดับกลาง
void T();
void T(byte sp);
void FT();
void FT(byte sp);
void FF(int T);
void FF(int T,byte sp);
void FD(unsigned long t);
void FD(unsigned long t,byte sp);
void FPP();
void FPP(byte sp);
void LD(int T);
void LD(int T,byte sp);
void RD(int T);
void RD(int T,byte sp);
void B();
void B(byte sp);
void BD(int t);
void BD(int t,byte sp);


#endif

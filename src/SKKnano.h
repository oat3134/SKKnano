#ifndef SKKnano_h
#define SKKnano_h

#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Servo.h>
#include <SSD1306Ascii.h>
#include "SSD1306AsciiAvrI2c.h"
#include <I2Cdev.h>
#include <MPU6050.h>

extern SSD1306AsciiAvrI2c;
extern MPU6050;

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

// ส่วน mpu6050
void Set_mpu6050();
void sensor_with_mpu6050();
void cpl(float targetAngle);
void cpl(float targetAngle,uint8_t speed);
void cpl_OLED(float targetAngle);
void cpl_OLED(float targetAngle,uint8_t speed);
void cpr(float targetAngle);
void cpr(float targetAngle,uint8_t speed);
void cpr_OLED(float targetAngle);
void cpr_OLED(float targetAngle,uint8_t speed);
void FDcp(int baseSpeed,float Kp,unsigned long t);


#endif

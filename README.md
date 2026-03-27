# SKKnano

ไลบรารีสำหรับบอร์ดหุ่นยนต์ SKK (สาย AVR/Arduino Nano) ที่รวมความสามารถหลักไว้ในชุดเดียว ได้แก่

- ควบคุมมอเตอร์ซ้าย/ขวา
- จอ OLED I2C (SSD1306Ascii)
- Servo
- อ่านเซนเซอร์เส้นหลายช่อง
- ชุดฟังก์ชันเดินเส้นระดับกลาง
- ฟังก์ชัน MPU6050 สำหรับหมุนตามองศาและช่วยคุมทิศทาง

Repository: https://github.com/oat3134/SKKnano

## การติดตั้ง

1. วางโฟลเดอร์ `SKKnano` ลงใน `Arduino/libraries`
2. เปิด Arduino IDE ใหม่
3. เลือกบอร์ดที่ตรงกับฮาร์ดแวร์ (กลุ่ม AVR)
4. เปิดตัวอย่างจาก `File > Examples > SKKnano`

## เริ่มใช้งานอย่างเร็ว

```cpp
#include <SKKnano.h>

// OLED/MPU6050 ถูกอ้างผ่าน extern ในไลบรารี จึงต้องประกาศในสเก็ตช์
SSD1306AsciiAvrI2c OLED;
MPU6050 accelgyro;
int16_t ax, ay, az;
int16_t gx, gy, gz;
float gyroErrorZ = 0;

// Servo globals
Servo sv1, sv2, sv3;
uint8_t servo1 = 10, servo2 = 11, servo3 = 12;

// Sensor globals
int s0, s1, s2, s3, s4;
int cen0 = 500, cen1 = 500, cen2 = 500, cen3 = 500, cen4 = 500;

// Speed profile globals
uint8_t fl = 120, fr = 120, bl = 100, br = 100;
uint8_t mfl = 90, mfr = 90, mbl = 80, mbr = 80;

uint8_t v_go = 30, v_standby = 90;

#define I2C_ADDRESS 0x3C
#define RST_PIN -1

void setup() {
	pinMode(2, INPUT);

#if RST_PIN >= 0
	OLED.begin(&Adafruit128x32, I2C_ADDRESS, RST_PIN);
#else
	OLED.begin(&Adafruit128x32, I2C_ADDRESS);
#endif
	OLED.setI2cClock(200000);
	OLED.setFont(Adafruit5x7);
	OLED.clear();

	Motor_begin();
	sv_begin();
	sv_set(90);
	Set_mpu6050();
}

void loop() {
	run(100, 100);
	delay(300);
	run(0, 0);
	delay(500);
}
```

## ฟังก์ชันหลัก

- Motor/Servo/Sensor
	- `Motor_begin()`, `run(left, right)`, `test_motor()`
	- `sv_begin()`, `sv_set(angle)`, `set_servo()`, `paste()`, `UP()`, `DOWN()`
	- `analogs()`, `sensor()`
- ฟังก์ชันช่วยเดินเส้น
	- `T()`, `FT()`, `FF()`, `FD()`, `FPP()`
	- `LD()`, `RD()`, `B()`, `BD()`
	- หลายฟังก์ชันมี overload รับค่าความเร็ว
- MPU6050
	- `Set_mpu6050()` คาลิเบรตไจโร (ห้ามขยับบอร์ดช่วงคาลิเบรต)
	- `sensor_with_mpu6050()` ดูค่าเซนเซอร์ร่วมกับมุม
	- หมุนซ้าย/ขวาตามองศา: `cpl(...)`, `cpr(...)`
	- หมุนแบบลดกำลังล้อข้างเดียว: `cpll(...)`, `cprr(...)`
	- แสดงมุมบน OLED: `cpl_OLED(...)`, `cpr_OLED(...)`
	- ช่วยคุมทิศแบบ proportional: `FDcp(...)`, `FPPcp(...)`, `BDcp(...)`

## ขา I/O ที่ใช้งาน

- มอเตอร์
	- ขวา: `DR1=7`, `DR2=8`, `PWMR=6`
	- ซ้าย: `DL1=4`, `DL2=9`, `PWML=5`
- เซนเซอร์แอนะล็อกหลัก: `A0, A1, A2, A3, A6`
- ปุ่มกดในตัวอย่าง: `D2`
- ปรับเมนู/ทดสอบบางตัวอย่าง: `A7`

## ตัวอย่างที่แนะนำ

- `lab01_Digital_OUTPUT`
- `lab04_Motor`
- `lab06_OLED`
- `lab08_Linefollow`
- `lab11_Mission_Linefollow`
- `Medium_Rescue_Robot__68`
- `Medium_Rescue_Robot__68_mpu6050`

## หมายเหตุสำคัญ

- โค้ดหลายฟังก์ชันในไลบรารีอ้างตัวแปรแบบ `extern` ถ้าไม่ประกาศ global ให้ครบจะลิงก์ไม่ผ่าน
- ฟังก์ชันบางตัวเป็นลูปต่อเนื่อง (`while(1)`) ควรออกแบบเงื่อนไขหยุดให้เหมาะกับสนามจริง
- ก่อนเรียกฟังก์ชันหมุนด้วย MPU6050 ควรเรียก `Set_mpu6050()` ทุกครั้งหลังเปิดเครื่อง

## License

ดูรายละเอียดในไฟล์ `LICENSE`

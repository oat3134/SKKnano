#include <SKKnano.h>

////////////ตั้งค่าพอร์ตมอเตอร์////////////////////
#define DR1  7  /// กำหนดสัญญาณดิจิตอลขวาที่ 1 พอร์ต 7
#define DR2  8  /// กำหนดสัญญาณดิจิตอลขวาที่ 2 พอร์ต 8
#define PWMR 6 /// กำหนดสัญญาณ PWM ขวาพอร์ต 6

/////////////////////////////////
#define DL1  4  // กำหนดสัญญาณดิจิตอลซ้ายที่ 1 พอร์ต 9
#define DL2  9  // กำหนดสัญญาณดิจิตอลซ้ายที่ 2 พอร์ต 4
#define PWML 5  /// กำหนดสัญญาณ PWM ซ้ายพอร์ต 5

#define buttonPin 2

void setup() {

  pinMode(buttonPin,INPUT);

  Motor_begin();

}

void loop(){
  int sw = digitalRead(buttonPin);  //กำหนดตัวแปร sw ให้มีค่าเท่ากับ ค่าที่อ่านได้จาก digital Pin 2  หรือ ปุ่ม OK บนบอร์ด
  if (sw==1){
    run(200,200);delay(500);run(0,0);delay(500);
    run(-200,200);delay(500);run(0,0);delay(500);
    run(200,-200);delay(500);run(0,0);delay(500);
    run(-200,-200);delay(500);run(0,0);delay(500);
    run(0,0);                   //มอเตอร์ซ้ายและขวาหยุด
  }                 
}

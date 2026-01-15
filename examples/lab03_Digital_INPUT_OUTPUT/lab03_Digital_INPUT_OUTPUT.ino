int ledPin = 10;  //  เชื่อมต่อ LED digital pin 10
int inPin = 2;    // ปุ่มกดบนบอร์ด เชื่อมต่อกับ digital pin 2

bool val = 0;      // ประกาศตัวแปรเพื่อเก็บค่าที่อ่านได้ กำหนดค่าเริ่มต้นเท่ากับ 0

void setup() {

  pinMode(ledPin, OUTPUT);  // กำหนด digital pin 10 เป็น output
  pinMode(inPin, INPUT);    // กำหนด digital pin 2 เป็น input

}

void loop() {

 val = digitalRead(inPin);   // อ่านค่าจาก inPin (ในที่นี้คือ D2) เก็บไว้ในตัวแปรชื่อว่า val
 digitalWrite(ledPin, val);  // สั่งให้ ledPin (ในที่นี้คือ D10) มีค่าเป็นไปตามตัวแปรชื่อ val

}
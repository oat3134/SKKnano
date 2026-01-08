int analogPin = A7; // ตัวต้านทานปรับค่าได้ที่อยู่บนบอร์ด เชื่อมต่ออยู่กับ Pin A7
int val = 0;  // กำหนดตัวแปรเพื่อเก็บค่าและมีค่าเริ่มต้น เป็น 0

void setup() {
  Serial.begin(9600);           //  เริ่มใช้งาน Serial 
}

void loop() {
  val = analogRead(analogPin);  // อ่านค่า analog จาก Pin A7  เก็บไว้ในตัวแปรที่ชื่อว่า val
  Serial.println(val);          // แสดงค่า val ผ่านทาง serial Monitor
}
#include<SKKnano.h>

int x;       // ตั้งค่าตัวแปรจำนวนเต็มเป็น x

void setup() {

  OLED_begin();
  
}

void loop(){

  OLED.clear();
  OLED.setCursor(40, 0);       // เซตตำแหน่ง 40,0
  OLED.set1X();        // เซตขนาดอักษรมีขนาดเป็น 2
  OLED.println("ROBOT");     // พิมพ์คำว่า Robot
  OLED.print("SKK");  // พิมพ์คำว่า SKK
  OLED.println(" 2021");    // พิมพ์บรรทัดใหม่หลังคำว่า 2021
  OLED.print("Kroothaimaker");      // พิมพ์คำว่า Kroothaimaker

  delay(100);

}
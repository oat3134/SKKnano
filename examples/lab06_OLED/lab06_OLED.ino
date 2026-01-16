#include<SKKnano.h>
SSD1306AsciiAvrI2c OLED;
#define I2C_ADDRESS 0x3C
#define RST_PIN -1

int x;       // ตั้งค่าตัวแปรจำนวนเต็มเป็น x

void setup() {

  #if RST_PIN >= 0
    OLED.begin(&Adafruit128x32, I2C_ADDRESS, RST_PIN);
  #else // RST_PIN >= 0
    OLED.begin(&Adafruit128x32, I2C_ADDRESS);
  #endif // RST_PIN >= 0
  OLED.setI2cClock(200000); // ลดความเร็วลงเพื่อความเสถียร
  OLED.setFont(Adafruit5x7);
  OLED.clear();

  OLED.setCursor(40, 0);       // เซตตำแหน่ง 40,0
  OLED.set1X();        // เซตขนาดอักษรมีขนาดเป็น 2
  OLED.println("ROBOT");     // พิมพ์คำว่า Robot
  OLED.print("SKK");  // พิมพ์คำว่า SKK
  OLED.println(" 2021");    // พิมพ์บรรทัดใหม่หลังคำว่า 2021
  OLED.print("Kroothaimaker");      // พิมพ์คำว่า Kroothaimaker
  
}

void loop(){

}
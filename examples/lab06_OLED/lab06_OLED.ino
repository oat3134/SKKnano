#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 OLED(-1);
int x;       // ตั้งค่าตัวแปรจำนวนเต็มเป็น x

void setup() {

  OLED.begin(SSD1306_SWITCHCAPVCC,0x3C); // กำหนดแอดเดรสของพอร์ตจอเป็น 0x3C (for the 128x64)

}

void loop(){

  OLED.clearDisplay();
  OLED.setTextColor(WHITE,BLACK);   //สีอักษรเป็นสีขาว ,พื้นหลังดำ
  OLED.setCursor(40, 0);       // เซตตำแหน่ง 40,0
  OLED.setTextSize(1);        // เซตขนาดอักษรมีขนาดเป็น 2
  OLED.println("ROBOT");     // พิมพ์คำว่า Robot
  OLED.print("SKK");  // พิมพ์คำว่า SKK
  OLED.println(" 2021");    // พิมพ์บรรทัดใหม่หลังคำว่า 2021
  OLED.print("Kroothaimaker");      // พิมพ์คำว่า Kroothaimaker
  OLED.display();

}
void setup() {

  Serial.begin(9600);			// เปิดการใช้งาน Port Serial Data Rate 9600 bps

}

void loop() {

	Serial.println(digitalRead(2));	// ให้ Port Serial แสดงผล ค่าที่อ่านได้จาก Pin Digital 2
	delay(100); 			//หน่วงเวลาที่ 100 ms

}
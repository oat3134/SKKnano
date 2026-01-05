#ifndef SKKnano
#define SKKnano

#include"SPI.h"
#include"Wire.h"
#include"Servo.h"
#include"Adafruit_GFX.h"
#include"Adafruit_SSD1306.h"
#include"Adafruit_MCP3008.h"
#include"MechaQMC5883.h"

/////////////////////////////////
MechaQMC5883 qmc;

void cpset() {
  Wire.begin();
  qmc.init();
}

int cp()
{     int x, y, z;
      int a;
      qmc.read(&x, &y, &z,&a);
	return (a);
}
int cpx()
{     int x, y, z;
      int a;
      qmc.read(&x, &y, &z,&a);
	return (x);
}
int cpy()
{     int x, y, z;
      int a;
      qmc.read(&x, &y, &z,&a);
	return (y);
}
int cpz()
{     int x, y, z;
      int a;
      qmc.read(&x, &y, &z,&a);
	return (z);
}
/////////////////////////////////


#endif
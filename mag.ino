
#include <Wire.h>
#include <math.h>
#define WHO_AM_I   0x0F

#define _CTRL_REG1  0x20
#define _CTRL_REG2  0x21
#define _CTRL_REG3  0x22
#define _CTRL_REG4  0x23
#define _CTRL_REG5  0x24

#define _STATUS_REG 0x27
#define _OUT_X_L    0x28
#define _OUT_X_H    0x29
#define _OUT_Y_L    0x2A
#define _OUT_Y_H    0x2B
#define _OUT_Z_L    0x2C
#define _OUT_Z_H    0x2D
#define _TEMP_OUT_L 0x2E
#define _TEMP_OUT_H 0x2F
#define _INT_CFG    0x30
#define _INT_SRC    0x31
#define _INT_THS_L  0x32
#define _INT_THS_H  0x33

void setupMAG();
int angle=0;
long magX, magY, magZ;
long a;
long minn=2617,maxx=-2417;
float Xgauss,Ygauss,Zgauss;
void setup() {
  Serial.begin(9600);
  Wire.begin();
  setupMAG();
}


void loop() {
  Wire.beginTransmission(0b0011100); //I2C address of the MPU
  Wire.write(_OUT_X_L | 0x80); //Starting register for Accel Readings
  Wire.endTransmission();
  Wire.requestFrom(0b0011100,6); //Request Accel Registers (3B - 40)
  while(Wire.available() < 6);
  magX = Wire.read()|Wire.read()<<8; //Store first two bytes into accelX
  magY = Wire.read()|Wire.read()<<8; //Store middle two bytes into accelY
  magZ = Wire.read()|Wire.read()<<8; //Store last two bytes into accelZ
  Xgauss=float(magX/27868.00f)*4.00f;
  Ygauss=float(magY/27868.00f)*4.00f;
  Zgauss=float(magZ/27868.00f)*4.00f;

  if(Xgauss==0.00)
  {
    if(Ygauss<0.00)
   {
    angle=0;
   }
    else
    angle=90;
    
  }
  else
  {
   angle = atan(Ygauss/Xgauss)*(180/PI);
  }
/*  if(magX<minn)
  minn=magX;
  if(magX>maxx)
  maxx=magX;
 */// a=map((float)(magX+magY)/magZ,-0.49, 0.49,0,180);
/*
  Serial.print(" X=");
  Serial.print(Xgauss);
  Serial.print(" Y=");
  Serial.print(Ygauss);
  *//*Serial.print(" Z=");
  Serial.println(Zgauss);*/

if(Xgauss<0.00 && Ygauss<0.00)
angle+=180;  
if(angle<0 && Xgauss<0.00)
angle+=180;
if(angle<0 && Xgauss>0.00)
angle+=360;
  Serial.print("Angle=");
  Serial.println(angle);
  delay(100);
}

void setupMAG(){
  Wire.beginTransmission(0b0011100); //This is the I2C address of the MPU (b1101000/b1101001 for AC0 low/high datasheet sec. 9.2)
  Wire.write(_CTRL_REG1); //Accessing the register 6B - Power Management (Sec. 4.28)
  Wire.write(0b01110000); //Setting SLEEP register to 0. (Required; see Note on p. 9)
  Wire.endTransmission();  
  Wire.beginTransmission(0b0011100); //This is the I2C address of the MPU (b1101000/b1101001 for AC0 low/high datasheet sec. 9.2)
  Wire.write(_CTRL_REG2); //Accessing the register 6B - Power Management (Sec. 4.28)
  Wire.write(0b00000000); //Setting SLEEP register to 0. (Required; see Note on p. 9)
  Wire.endTransmission();
  Wire.beginTransmission(0b0011100); //This is the I2C address of the MPU (b1101000/b1101001 for AC0 low/high datasheet sec. 9.2)
  Wire.write(_CTRL_REG3); //Accessing the register 6B - Power Management (Sec. 4.28)
  Wire.write(0b00000000); //Setting SLEEP register to 0. (Required; see Note on p. 9)
  Wire.endTransmission();
  Wire.beginTransmission(0b0011100); //This is the I2C address of the MPU (b1101000/b1101001 for AC0 low/high datasheet sec. 9.2)
  Wire.write(_CTRL_REG4); //Accessing the register 6B - Power Management (Sec. 4.28)
  Wire.write(0b00001100); //Setting SLEEP register to 0. (Required; see Note on p. 9)
  Wire.endTransmission();
  Wire.beginTransmission(0b0011100); //This is the I2C address of the MPU (b1101000/b1101001 for AC0 low/high datasheet sec. 9.2)
  Wire.write(_CTRL_REG5); //Accessing the register 6B - Power Management (Sec. 4.28)
  Wire.write(0b00000000); //Setting SLEEP register to 0. (Required; see Note on p. 9)
  Wire.endTransmission();
      
}

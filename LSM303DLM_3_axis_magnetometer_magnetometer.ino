#include<wire.h>


int mode = -1;
int magnetometerX,magnetometerY,magnetometerZ;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0)
  {
    mode=Serial.read();
    switch(mode)
    {
      case 'M';
      getMagnetometerValues();
      Serial.println(magnetometerX);
      Serial.println(magnetometerY);
      Serial.println(magnetometerZ);
      break;
    }
  }
}



void getMagnetometerValue()
{
  Wire.beginTransmission(Ox3C>>1);
  Wire.write(Ox03);
  Wire.endTransmission();
  Wire.requestFrom(Ox3C>>1,6);
}

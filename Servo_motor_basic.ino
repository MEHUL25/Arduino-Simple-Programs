#include<Servo.h>
int i=0,j=0;
Servo ser;
//Attach Signal terminal to ~9 and power to vcc
void setup()
{
  ser.attach(9);
}

void loop()
{
  for(int i=0;i<=179;i++)
  {
     ser.write(i);
    delay(20);
  }
  for(int i=179;i>=0;i--)
  {
     ser.write(i);
    delay(20);
  }
  delay(200);
}

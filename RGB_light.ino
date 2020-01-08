void setup()
{
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop()
{
  for(int i=0;i<=10;i=i+5)
  {
    analogWrite(9,255);
    analogWrite(10,201);
    delay(300);
    analogWrite(9,155);
    analogWrite(10,101);
    delay(800);
  }
}

void setup()
{
  pinMode(9, OUTPUT);
}

void loop()
{
  for(int i=0;i<=255;i=i+5)
  {
    analogWrite(9,i);
  }
  delay(3000);
  for(int i=255;i>=0;i=i-5)
  {
    analogWrite(9,i);
  }
  delay(3000);
}

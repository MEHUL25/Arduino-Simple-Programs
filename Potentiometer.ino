int value=0;
void setup()
{
  pinMode(13, OUTPUT);
  pinMode(A0, INPUT);
}

void loop()
{
  value=analogRead(A0);
  digitalWrite(13,HIGH);
  delay(value);
  digitalWrite(13,LOW);
  delay(value);
}

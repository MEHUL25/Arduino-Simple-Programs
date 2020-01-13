
int n;
void setup() {
  Serial.begin(9600);
}
void loop() {
  if(Serial.available()>0)
  {
  n=Serial.read();
  Serial.print(millis()/1000);
  Serial.print(" ");
  Serial.print(n);
  Serial.println();
  }                     
}


//Sender's code 


char str[5]="Hello";
int a=-23;
void setup() {
  Serial.begin(9600);
}

void loop() {
  uint8_t l=a;
  uint8_t m=a>>8;
  Serial.write(m);
  delay(300);
  Serial.write(l);
} 

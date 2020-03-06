//reciever's code


int a=0;
char c;
char buf[8];
void setup() {
  Serial.begin(9600);
  Serial2.begin(9600);
}

void loop() {
    while(Serial2.available()==0);
    for(int i=0;i<8;i++)
        {
          c=Serial2.read();
          Serial.print(c);
          buf[i]=c;
          if(c!=-1)
          {
            if(i>0)
            {
              a=a*10;
              a=(atoi(c))+a;
            }
          }
          
        }
        
        if(buf[0]=="-")
        {
          a=a*(-1);;
           
        }
Serial.println(a);
   delay(300);
}

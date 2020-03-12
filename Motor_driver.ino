const int pwm = 2 ;  //initializing pin 2 as pwm
const int dir = 3 ;
int angle=0;

void setup()
{
    pinMode(pwm,OUTPUT) ;   //we have to set PWM pin as output
    pinMode(dir,OUTPUT) ; 
}

void loop()
{
      analogWrite(pwm,200) ;
      delay(3000) ;    
       digitalWrite(dir,!digitalRead(dir)) ;
       analogWrite(pwm,150) ;
}

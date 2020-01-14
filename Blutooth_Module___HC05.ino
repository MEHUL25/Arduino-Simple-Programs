//This idea can be extended to Bluetooth home automated system.
//Just connect relay in place of led and the appliance to other end of relay
//Here on pressing a button on bluetooth app it sends a character to arduino
//Here on pressing 'Button 1' this app sends char 'A' Which can be used to turn on LED at pin no. 2
char val;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  val=Serial.read();
  if(val=='A')
    digitalWrite(2,HIGH);// Here the led connected to the pin no. 2 is to be glowed on recieving input from arduino.
   else if(val=='a');
    digitalWrite(2,LOW);
   delay(2000);
}

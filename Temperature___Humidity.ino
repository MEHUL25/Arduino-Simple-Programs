#include <dht.h>
dht object;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int check=object.read11(2);     // Here DHT11 Temperature sensor is connected to Digital pin no. 2 of the Arduino
  print("Temperature : ");
  println(object.temperature);
  print("Humidity : ");
  println(object.humidity);
  delay(2000);
}

#include <SoftwareSerial.h>
#define rxPin 11 //Broche 11 en tant que RX, à raccorder sur TX du HC-05
#define txPin 10 //Broche 10 en tant que RX, à raccorder sur TX du HC-05
#define baudrate 38400
SoftwareSerial mySerial(rxPin ,txPin); //D�finition du software serial

void setup() {
  // put your setup code here, to run once:
  pinMode(rxPin,INPUT);
  pinMode(txPin,OUTPUT);
    
  mySerial.begin(baudrate);
  Serial.begin(baudrate);
}

void loop() {
  // put your main code here, to run repeatedly:
  int i = 0; 
  char someChar[32] ={0};
  //when characters arrive over the serial port...

  while (Serial.available()) {
     do{
    someChar[i++] = Serial.read();
    delay(3);   
     }while (Serial.available() > 0);
     
     mySerial.println(someChar); 
     Serial.println(someChar); 
  }
  while (mySerial.available()) {
    Serial.print((char)mySerial.read());
  }
}

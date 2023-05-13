#include <Adafruit_SSD1306.h>
#include <SoftwareSerial.h>
#define nombreDePixelsEnLargeur 128         // Taille de l'écran OLED, en pixel, au niveau de sa largeur
#define nombreDePixelsEnHauteur 64          // Taille de l'écran OLED, en pixel, au niveau de sa hauteur
#define brocheResetOLED         -1          // Reset de l'OLED partagé avec l'Arduino (d'où la valeur à -1, et non un numéro de pin)
#define adresseI2CecranOLED     0x3C        // Adresse de "mon" écran OLED sur le bus i2c (généralement égal à 0x3C ou 0x3D)
#define rxPin 11 //Broche 11 en tant que RX, à raccorder sur TX du HC-05
#define txPin 10 //Broche 10 en tant que RX, à raccorder sur TX du HC-05
#define baudrate 38400
SoftwareSerial mySerial(rxPin ,txPin); //Definition du software serial

float voltage_output;
float Rc;

Adafruit_SSD1306 ecranOLED(nombreDePixelsEnLargeur, nombreDePixelsEnHauteur, &Wire, brocheResetOLED);

void setup() {
  Serial.begin(9600);
  if(!ecranOLED.begin(SSD1306_SWITCHCAPVCC, adresseI2CecranOLED))
    while(1);    
  
  ecranOLED.clearDisplay();
  ecranOLED.setTextSize(1);
  ecranOLED.setTextColor(SSD1306_WHITE, SSD1306_BLACK);
  
  pinMode(rxPin,INPUT);
  pinMode(txPin,OUTPUT);
    
  mySerial.begin(baudrate);
  Serial.begin(baudrate);
}

void loop() {

//Calcul Resistance jauge
voltage_output = analogRead(A0);
voltage_output = 5*voltage_output/1023;
Rc = 50/voltage_output;

// Bluetooth
while (Serial.available()) {
     do{
    //Serial.read();
    delay(3);   
     }while (Serial.available() > 0);
     
     //mySerial.println(i); 
     mySerial.write(voltage_output);
     Serial.println(Rc); 
  }

//Affichage et saisie de texte
String display_prompt = String(Rc,1);
int x = nombreDePixelsEnLargeur/2;
int y = nombreDePixelsEnHauteur/2;

ecranOLED.setCursor(15,0);
ecranOLED.print("Sensor resistance");
ecranOLED.setCursor(x-20,y);
ecranOLED.print(display_prompt + " MOhm");


ecranOLED.display();  
delay(1000);
ecranOLED.clearDisplay();

}

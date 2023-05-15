#include <Adafruit_SSD1306.h>
#include <SoftwareSerial.h>
#define nombreDePixelsEnLargeur 128         // Taille de l'écran OLED, en pixel, au niveau de sa largeur
#define nombreDePixelsEnHauteur 64          // Taille de l'écran OLED, en pixel, au niveau de sa hauteur

#define x 128         // Taille de l'écran OLED, en pixel, au niveau de sa largeur
#define y 64          // Taille de l'écran OLED, en pixel, au niveau de sa hauteur

#define brocheResetOLED         -1          // Reset de l'OLED partagé avec l'Arduino (d'où la valeur à -1, et non un numéro de pin)
#define adresseI2CecranOLED     0x3C        // Adresse de "mon" écran OLED sur le bus i2c (généralement égal à 0x3C ou 0x3D)
#define rxPin 10 //Broche 11 en tant que RX, à raccorder sur TX du HC-05
#define txPin 11 //Broche 10 en tant que RX, à raccorder sur TX du HC-05
#define baudrate 38400
SoftwareSerial mySerial(rxPin ,txPin); //Definition du software serial

float voltage_output;
float Rc;
float VBT;
int binary_voltage;

Adafruit_SSD1306 ecranOLED(x, y, &Wire, brocheResetOLED);

void setup() {
  
  if(!ecranOLED.begin(SSD1306_SWITCHCAPVCC, adresseI2CecranOLED))
    while(1);    
  
  ecranOLED.clearDisplay();
  ecranOLED.setTextSize(1);
  ecranOLED.setTextColor(SSD1306_WHITE, SSD1306_BLACK);

  pinMode(rxPin,INPUT);
  pinMode(txPin,OUTPUT);

  mySerial.begin(baudrate);
  Serial.begin(9600);
  ecranOLED.setCursor(10,y/2);
  ecranOLED.print("Initialization...");
  ecranOLED.display(); 
  delay(1000);
  ecranOLED.clearDisplay();


}

void loop() {

//Calcul Resistance jauge
voltage_output = analogRead(A0);
binary_voltage = voltage_output;
voltage_output = 5*voltage_output/1023;
Rc = 50/voltage_output;


// Bluetooth
//mySerial.println(i); 
mySerial.write(voltage_output/4);
VBT = analogRead(A3); //voltage de rxPin su
VBT = VBT*5/1023;
Serial.print(binary_voltage); 
Serial.println("V");
Serial.print(Rc); 
Serial.println("Ohm");
     
  
//Affichage et saisie de texte


String display_prompt1 = String(voltage_output,1);
String display_prompt2 = String(Rc,1);

ecranOLED.setCursor(25,0);
ecranOLED.print("Voltage output");
ecranOLED.setCursor(x/2 - 20, 10);
ecranOLED.print(display_prompt1 + " V");

ecranOLED.setCursor(15,y/2);
ecranOLED.print("Sensor resistance");
ecranOLED.setCursor(x/2 - 20,y-20);
ecranOLED.print(display_prompt2 + " MOhm");

ecranOLED.display();  
delay(1000);
ecranOLED.clearDisplay();

}

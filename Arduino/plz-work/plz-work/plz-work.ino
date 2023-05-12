#include <Adafruit_SSD1306.h>

#define x 128         // Taille de l'écran OLED, en pixel, au niveau de sa largeur
#define y 64          // Taille de l'écran OLED, en pixel, au niveau de sa hauteur
#define brocheResetOLED         -1          // Reset de l'OLED partagé avec l'Arduino (d'où la valeur à -1, et non un numéro de pin)
#define adresseI2CecranOLED     0x3C        // Adresse de "mon" écran OLED sur le bus i2c (généralement égal à 0x3C ou 0x3D)

float voltage_output;
float Rc;

Adafruit_SSD1306 ecranOLED(x, y, &Wire, brocheResetOLED);

void setup() {
  Serial.begin(9600);
  if(!ecranOLED.begin(SSD1306_SWITCHCAPVCC, adresseI2CecranOLED))
    while(1);    
  
  ecranOLED.clearDisplay();
  ecranOLED.setTextSize(1);
  ecranOLED.setTextColor(SSD1306_WHITE, SSD1306_BLACK);
  ecranOLED.setCursor(10,y/2);
  ecranOLED.print("Initialization...");
  ecranOLED.display(); 
  delay(1000);
  ecranOLED.clearDisplay();

}

void loop() {

//Calcul Resistance jauge
voltage_output = analogRead(A0);
voltage_output = 5*voltage_output/1023;
Rc = 50/voltage_output;

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

float voltage_output;
float Rc;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
//pinMode(A0,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
voltage_output = analogRead(A0);
voltage_output = 5*voltage_output/1023;
Rc = 50/voltage_output;
Serial.print("ADC vaut :");
Serial.print(voltage_output);
Serial.println("V");
Serial.print("Rc vaut :");
Serial.print(Rc);
Serial.println(" Mohms");
delay(1000);
}

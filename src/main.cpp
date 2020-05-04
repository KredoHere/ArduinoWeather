#include <Arduino.h>
/////////Zmienne / Variables////////
const int pResistor = 1;
int ThermistorPin = 0;
int Vo;
int value;
float R1 = 10000;
float logR2, R2, T, Tc;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;
////////////////////////////////////

////////Przygotowanie / Prepare////////
void setup() {
Serial.begin(9600);
pinMode(pResistor, INPUT);
}
///////////////////////////////////////

////////Odczyty / Readings////////
void loop() {
  value = analogRead(pResistor);
  Vo = analogRead(ThermistorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  Tc = T - 273.15;
  value = map(value, 0, 1023, 0, 100);
//////////////////////////////////

////////wysyłanie danych / Sending data////////
  Serial.print("Temperature: "); 
  Serial.print(Tc);
  Serial.println("*C");   
  Serial.print("Light:");
  Serial.print(value);
  Serial.println("%");
  delay(500);
}
////////////////////////////////////////////////
///           Made By Pastel 2020.           ///
////////////////////////////////////////////////

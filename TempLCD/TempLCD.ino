#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#include <LiquidCrystal.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

float sensorTemp = 0.0; // For storing raw data from LM-35
  float Temperature = 0.0; // For storing the converted temperature
  int analogInputPin = 0; // Data out of LM-35 is connected in Arduino's analog Pin A0
  
void setup() 
{

  Serial.begin(9600);
  pinMode( analogInputPin,INPUT );
  lcd.begin();
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
}

void loop() 
{
  sensorTemp = analogRead(analogInputPin); // Reads sensor data from pin A0
  Temperature = sensorTemp * 0.48875855; //(+Vcc * 1000 / 1023) / 10
//float temp = (-1*((analogRead(pinTemp) * (5.0/1024))-0.5 )/0.01)+10;
  lcd.setCursor(0, 1);
  //lcd.print("        ");
  //lcd.setCursor(0,1);
  lcd.print( Temperature );
  Serial.println( Temperature );
  delay( 1000);

}

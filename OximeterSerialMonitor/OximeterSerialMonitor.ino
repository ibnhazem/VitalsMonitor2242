#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "MAX30100_PulseOximeter.h"
 
#define REPORTING_PERIOD_MS     1000
 
PulseOximeter pox;
uint32_t tsLastReport = 0;
LiquidCrystal_I2C lcd(0x27, 16, 2);

float sensorTemp = 0.0; // For storing raw data from LM-35
float Temperature = 0.0; // For storing the converted temperature
int analogInputPin = 0; // Data out of LM-35 is connected in Arduino's analog Pin A0
int buttonPin = 7;
int buzPin = 8;
int buttonState = 0;

 
 
void setup()
{

    pinMode(buzPin , OUTPUT);
    pinMode (buttonPin , INPUT);
    Serial.begin(9500);
    Serial.print("Initializing pulse oximeter..");
    pinMode(analogInputPin, INPUT);

        lcd.begin();
        lcd.backlight();
 
    // Initialize the PulseOximeter instance
    // Failures are generally due to an improper I2C wiring, missing power supply
    // or wrong target chip
    if (!pox.begin()) {
        Serial.println("FAILED");
        for(;;);
    } else {
        Serial.println("SUCCESS");
    }
     pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);
      Serial.begin(9500);
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Life360");
  lcd.setCursor(0, 1);
  lcd.print("Loading...");
  
  delay(2000);

  if (!pox.begin()) {
    Serial.println("FAILED");
    for (;;);
  } else {
    Serial.println("SUCCESS");
  }
  pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);

}
 
void loop()
{
  sensorTemp = analogRead(analogInputPin); // Reads sensor data from pin A0
    Temperature = sensorTemp * 0.48875855; //(+Vcc * 1000 / 1023) / 10

    buttonState = digitalRead(buttonPin);
    if (buttonState == LOW) {
    
    // Make sure to call update as fast as possible
    pox.update();
    if (millis() - tsLastReport > REPORTING_PERIOD_MS) {
        Serial.print("Heart rate: ");
        Serial.print(pox.getHeartRate());
        Serial.print("bpm / SpO2: ");
        Serial.print(pox.getSpO2());
        Serial.println("%");
        Serial.print("Temperature: ");
        Serial.print(Temperature);
        Serial.println(" C");
 
        tsLastReport = millis();
    }
    
    
    
      pox.update();
  if (millis() - tsLastReport > REPORTING_PERIOD_MS) {

    lcd.setCursor(0 , 0);
    lcd.print("BPM:");
    lcd.print(pox.getHeartRate());
    lcd.setCursor(9, 0);
    lcd.print("|");
    lcd.print(" Temp: ");
    lcd.setCursor(0 , 1);
    lcd.print("Sp02:");
    lcd.print(pox.getSpO2());
    lcd.print("%");
    lcd.setCursor(9 , 1);
    lcd.print("|");
    lcd.print(Temperature);
//    lcd.setCursor(14,0);
//    lcd.print("");

    if (pox.getSpO2() >= 96) {
      lcd.setCursor(15 , 1);
      lcd.write(1);                 
    }
    else if (pox.getSpO2() <= 95 && pox.getSpO2() >= 91) {
      lcd.setCursor(15 , 1);
      lcd.write(2);                 
    }
    else if (pox.getSpO2() <= 90) {
      lcd.setCursor(15 , 1);
      lcd.write(3);
    }
  }
  //bracket below is the end bracket for the if buttonstate ==low
  digitalWrite(buzPin, LOW);
  delay(100);
  
    }
    else {
      digitalWrite(buzPin, HIGH);
      tone(buzPin, 1000, 1000);
      lcd.clear();
    }
}

float temp; 
int tempPin = A0;     // Sensor  connected to  analog  pin 0
void setup()
{
  Serial.begin(9600) ;   //start the serial monitor
}
void loop()
{
temp = analogRead(tempPin) ;  // assigning the analog input to temp
temp = temp / 2.048;      //converting readings to degree Celsius    
Serial.print("TEMPERATURE = ") ;  // display the information
Serial.print(temp) ;
Serial.print("*C") ;
Serial.println() ;
delay(1000) ;          // read the sensor every 1 sec.
}

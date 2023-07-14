   const int pinBuz = 8; //Buzzer Pin
   const int pinSwi = 2; // Push-button pin
     
   void setup() {
       Serial.begin(9600); // Opens Serial communication
       pinMode(pinBuz,OUTPUT); //Defines pinBuz as an Output
       pinMode(pinSwi,INPUT); // Defines pinSwi as an input
             }
   void loop () {
     int botao; // To save the last logic state of the button
     botao = digitalRead(pinSwi); //Put the reading value of the switch on botao
     Serial.println(botao); //Shows the logic state of the input on Serial Monitor
     if (botao == 1) // Pressed button, logic State HIGH (5V)
     {
     digitalWrite(pinBuz,1); //Switch pressed, buzzer on
     }else
     {
     digitalWrite(pinBuz,0); //If the switch isn’t pressed, buzzer off.
     }
     delay(1); //reading delay
               }

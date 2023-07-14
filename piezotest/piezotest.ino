    const int pinBuz = 3; //Buzzer Pin
    const int pinSwi = 2; // Push-button pin
       
    void setup() {
        Serial.begin(9500); // Opens Serial communication
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
      delay(10); //reading delay
                }
     

//const int BUTTON_PIN = 4; // Arduino pin connected to button's pin
//const int BUZZER_PIN = 3; // Arduino pin connected to Buzzer's pin
//
//void setup() {
//  Serial.begin(9600);                // initialize serial
//  pinMode(BUTTON_PIN, INPUT_PULLUP); // set arduino pin to input pull-up mode
//  pinMode(BUZZER_PIN, OUTPUT);       // set arduino pin to output mode
//}
//
//void loop() {
//  int buttonState = digitalRead(BUTTON_PIN); // read new state
//
//  if (buttonState == LOW) {
//    Serial.println("The button is being pressed");
//    digitalWrite(BUZZER_PIN, HIGH); // turn on
//  }
//  else
//  if (buttonState == HIGH) {
//    Serial.println("The button is unpressed");
//    digitalWrite(BUZZER_PIN, LOW);  // turn off
//  }
//}

const int buttonPin = 4;
int buttonState = 0;

void pushButton(){
  if (buttonState == 1) {
  Serial.println("Nice");
} else {
  Serial.println("why");
  delay(100);
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
}

void loop() {
  int buttonState = digitalRead(buttonPin);
  pushButton();
}

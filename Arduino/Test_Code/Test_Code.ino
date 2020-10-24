int scorePin = 3;
int score = 0;
int val = 0;
int counter;
int currentState;
int previousState;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(scorePin, INPUT_PULLUP);
}

void loop() {
  //put your main code here, to run repeatedly:
  int val = digitalRead(scorePin);
  if (val == HIGH) {
    //digitalWrite(scorePin, HIGH);
    currentState = 1;
  }
  else {
   // digitalWrite(scorePin, LOW);
    currentState = 0;
  }
  if (currentState != previousState) {
    if (currentState == 1) {
      counter = counter + 1;
      //Serial.println(counter);
    }
  }
  previousState = currentState;
  delay(20);
  Serial.print("point.val=");
    Serial.print(counter);
    Serial.write(0xff);
    Serial.write(0xff);
    Serial.write(0xff);
  
}

#include "Nextion.h"

NexButton b1 = NexButton(10, 2, "b1");
NexNumber timer = NexNumber(15, 7, "timer");
NexNumber bluescore = NexNumber(15, 1, "bluescore");
int scorePin = 3;
int score = 0;
int val = 0;
int counter;
int currentState;
int previousState;
//int bluescore = 0;
int redscore = 0;
//int timer;
int duration = 30000;
long startTime = millis();

// Register a button object to the touch event list.  
NexTouch *nex_listen_list[] = {
  &b1,
  &timer,
  &bluescore,
  NULL
};

void b1PopCallback(void *ptr) {
  digitalWrite(13, HIGH);
  delay(1000);
 digitalWrite(13, LOW);
  startTime = millis();

  while ((millis() - startTime) < duration) {
// update timer

  timer.setValue((uint32_t)((millis() - startTime)/1000));
  bluescore.setValue((uint32_t)((millis() - startTime)/1000));
 // Serial.print("timer.val=");
 // Serial.print((millis() - startTime)/1000);
 // Serial.write(0xff);
 // Serial.write(0xff);
 // Serial.write(0xff);

   
 int val = digitalRead(scorePin);
  if (val == HIGH) {
    digitalWrite(13, HIGH);
    currentState = 1;
  }
  else {
    digitalWrite(13, LOW);
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

  
//bluescore.setValue((uint32_t)2);
 /* Serial.print("bluescore.val=");
    Serial.print(counter);
    Serial.write(0xff);
    Serial.write(0xff);
    Serial.write(0xff);
     ;}*/

     

// tState.setText("State: on");
// digitalWrite(led1, HIGH);



}
}

void setup() {
  // put your setup code here, to run once:
 // Serial.begin(9600);

  // You might need to change NexConfig.h file in your ITEADLIB_Arduino_Nextion folder
  // Set the baudrate which is for debug and communicate with Nextion screen
  nexInit();
  
  b1.attachPop(b1PopCallback, &b1);
  
  pinMode(scorePin, INPUT_PULLUP);
}

void loop() {
    /*
   * When a pop or push event occured every time,
   * the corresponding component[right page id and component id] in touch event list will be asked.
   */
  nexLoop(nex_listen_list);

}

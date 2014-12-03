#include <Servo.h> 
 
Servo myservo;  
Servo myservo2;
Servo myservo3;
 
const int buttonPin = 2;
const int buttonPin2 = 3;

int switchValue = HIGH; 

int lastSwitch = HIGH;

//int bloomState = HIGH;
//int lastBloomState = HIGH;
//int buttonState;
//int lastButtonState = LOW;
//
//long lastDebounceTime = 0;
//long debounceDelay = 100;

void setup() 
{ 
  myservo.attach(9);  // attaches t   he servo on pin 9 to the servo object 
  myservo2.attach(10);
  myservo3.attach(11);
  
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin2, INPUT);
  digitalWrite(buttonPin, HIGH);
  
  myservo.write(20);
  myservo2.write(20);
  myservo3.write(5);
} 
 
    
void loop() 
{ 
//  int reading = digitalRead(buttonPin);
//
//  // check to see if you just pressed the button 
//  // (i.e. the input went from LOW to HIGH),  and you've waited 
//  // long enough since the last press to ignore any noise:  
//
//  // If the switch changed, due to noise or pressing:
//  if (reading != lastButtonState) {
//    // reset the debouncing timer
//    lastDebounceTime = millis();
//  } 
//  
//  if ((millis() - lastDebounceTime) > debounceDelay) {
//    // whatever the reading is at, it's been there for longer
//    // than the debounce delay, so take it as the actual current state:
//
//    // if the button state has changed:
//    if (reading != buttonState) {
//      buttonState = reading;
//      
//
//      // only toggle the LED if the new button state is HIGH
//      if (buttonState == HIGH) {
//        bloomState = !bloomState;
//      }
//    }
//  }
//  
//  // set the LED:
//      if (bloomState == HIGH && lastBloomState == LOW) {
//        lastBloomState = HIGH;
//        bloom();
//      }
//      
//      if (bloomState == LOW && lastBloomState == HIGH) {
//        lastBloomState = LOW;
//        unbloom();
//      }
//  
//
//  // save the reading.  Next time through the loop,
//  // it'll be the lastButtonState:
//  lastButtonState = reading;

  switchValue = digitalRead(buttonPin);
  
  if (switchValue == LOW && lastSwitch != 0) {
    lastSwitch = 0;
    bloom();
  }
  
  switchValue = digitalRead(buttonPin);
  
  if (switchValue == LOW && lastSwitch != 1) {
    lastSwitch = 1;
    unbloom();
  }
} 

void bloom() {
        for(int pos = 20; pos < 100; pos++)  // goes from 0 degrees to 180 degrees 
        {                                  // in steps of 1 degree 
          myservo.write(pos);              // tell servo to go to position in variable 'pos' 
          delay(20);                       // waits 15ms for the servo to reach the position 
        }  
//        delay(500);
        for(int pos = 20; pos < 100; pos++)  // goes from 0 degrees to 180 degrees 
        {                                  // in steps of 1 degree 
          myservo2.write(pos);              // tell servo to go to position in variable 'pos' 
          delay(20);                       // waits 15ms for the servo to reach the position 
        }  
//        delay(500);
        for(int pos = 5; pos < 80; pos++)  // goes from 0 degrees to 180 degrees 
        {                                  // in steps of 1 degree 
          myservo3.write(pos);              // tell servo to go to position in variable 'pos' 
          delay(20);                       // waits 15ms for the servo to reach the position 
        } 
//        delay(500);
}

void unbloom() {
        for(int pos = 100; pos > 20; pos--)  // goes from 0 degrees to 180 degrees 
        {                                  // in steps of 1 degree 
          myservo.write(pos);              // tell servo to go to position in variable 'pos' 
          delay(20);                       // waits 15ms for the servo to reach the position 
        }  
//        delay(500);
        for(int pos = 100; pos > 20; pos--)  // goes from 0 degrees to 180 degrees 
        {                                  // in steps of 1 degree 
          myservo2.write(pos);              // tell servo to go to position in variable 'pos' 
          delay(20);                       // waits 15ms for the servo to reach the position 
        }  
//        delay(500);
        for(int pos = 80; pos > 5; pos--)  // goes from 0 degrees to 180 degrees 
        {                                  // in steps of 1 degree 
          myservo3.write(pos);              // tell servo to go to position in variable 'pos' 
          delay(20);                       // waits 15ms for the servo to reach the position 
        } 
//        delay(500);
}

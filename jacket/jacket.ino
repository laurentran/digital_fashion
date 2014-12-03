

const int driverPin1 = 13;
const int driverPin2 = 12;
const int driverPin3 = 11;
const int switchPin = 10;
int switchValue;

const int rightPin1 = 6;
const int rightPin2 = 7;
const int rightPin3 = 8;
const int switchRight = 9;
int switchRightValue;

int rightLow = 4;

void setup()
{
    pinMode (driverPin1, OUTPUT);
    pinMode (driverPin2, OUTPUT);
    pinMode (driverPin3, OUTPUT);
    
    pinMode (rightPin1, OUTPUT);
    pinMode (rightPin2, OUTPUT);
    pinMode (rightPin3, OUTPUT);
    
    pinMode (rightLow, OUTPUT);
    
    pinMode (switchPin, INPUT);
    digitalWrite(switchPin, HIGH);
    
    pinMode (switchRight, INPUT);
    digitalWrite(switchRight, HIGH);
    
    digitalWrite(rightLow, LOW); 
}

void loop()
{
  switchValue = digitalRead(switchPin);
  switchRightValue = digitalRead(switchRight);
  
  // if left sleeve button is pressed
  if (switchValue == LOW) {
      for (int i = 0; i < 4; i++) {
      digitalWrite (driverPin1, HIGH);
      delay (200);
      digitalWrite (driverPin2, HIGH);
      delay (200);
      digitalWrite (driverPin3, HIGH);
      delay (800);
      digitalWrite (driverPin1, LOW);
      digitalWrite (driverPin2, LOW);
      digitalWrite (driverPin3, LOW);
      delay ( );
    }
  } else {
    digitalWrite (driverPin1, LOW);
    digitalWrite (driverPin2, LOW);
    digitalWrite (driverPin3, LOW); 
  }
  
  // if right sleeve button is pressed
  if (switchRightValue == LOW) {
    for (int j = 0; j < 4; j++) {
    digitalWrite (rightPin1, HIGH);
    delay (200);
    digitalWrite (rightPin2, HIGH);
    delay (200);
    digitalWrite (rightPin3, HIGH);
    delay (800);
    digitalWrite (rightPin1, LOW);
    digitalWrite (rightPin2, LOW);
    digitalWrite (rightPin3, LOW);
    delay (400);
    }
  } else {
    digitalWrite (rightPin1, LOW);
    digitalWrite (rightPin2, LOW);
    digitalWrite (rightPin3, LOW); 
  }
}

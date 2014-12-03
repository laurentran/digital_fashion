int boardLED = 13;
int leftSignal = 11;                
int rightSignal = 9;
int signalLow = 10;
int rightLow = 4;
int leftSwitch = 12;
int rightSwitch = 6;
int leftLED = 5;
int rightLED = 3;
int x, y;
int mode = 0;
int DAY = 0;
int NIGHT = 1;

void setup()                    // run once, when the sketch starts
{
  pinMode(boardLED, OUTPUT);
  
  pinMode(leftSignal, OUTPUT);
  pinMode(rightSignal, OUTPUT); 
  
  pinMode(signalLow, OUTPUT);  
  pinMode(rightLow, OUTPUT);  
  
  pinMode(leftSwitch, INPUT);  
  digitalWrite(leftSwitch, HIGH);
  pinMode(rightSwitch, INPUT);  
  digitalWrite(rightSwitch, HIGH);
  
  pinMode(leftLED, OUTPUT);   
  pinMode(rightLED, OUTPUT);   
  
  digitalWrite(boardLED, HIGH);
  digitalWrite(signalLow, LOW);
  digitalWrite(rightLow, LOW);
}

void loop()                     // run over and over again
{ 
  checkLeft();
  checkRight();
  if (mode == NIGHT)
    night();  
  else  
    day();
}

void checkLeft()
{
  if (digitalRead(leftSwitch) == LOW)
  {
    digitalWrite(boardLED, LOW);
    while (digitalRead(leftSwitch) == LOW)
    {
      if (digitalRead(rightSwitch) == LOW)
      {
        while (digitalRead(rightSwitch) == LOW | digitalRead(leftSwitch) == LOW);
        mode = 1-mode;
        digitalWrite(boardLED, HIGH);
        return;
      }
    }
    leftTurn();
  }
}

void checkRight()
{
  if (digitalRead(rightSwitch) == LOW)
  {
    digitalWrite(boardLED, LOW);
    while (digitalRead(rightSwitch) == LOW)
    {
      if (digitalRead(leftSwitch) == LOW)
      {
         while (digitalRead(leftSwitch) == LOW | digitalRead(rightSwitch) == LOW);
         mode = 1-mode;
         digitalWrite(boardLED, HIGH);
         return;
      }
    }
    rightTurn();
  }
}

void leftTurn()
{
  for (x=0;x<10;x++)
  {
    digitalWrite(leftSignal, HIGH); 
    digitalWrite(leftLED, LOW); 
    for(y=0;y<10;y++)
    {
      delay(30);
      if (digitalRead(leftSwitch) == LOW)
      {
        while (digitalRead(leftSwitch) == LOW);
        digitalWrite(leftSignal, LOW);  
        digitalWrite(leftLED, LOW); 
        return;
      }
    }
    digitalWrite(leftSignal, LOW);
    digitalWrite(leftLED, HIGH);
    for(y=0;y<10;y++)
    {
      delay(30);
      if (digitalRead(leftSwitch) == LOW)
      {
        while (digitalRead(leftSwitch) == LOW);
        digitalWrite(leftSignal, LOW);  
        digitalWrite(leftLED, LOW);
        return;
      }
    }
    digitalWrite(leftLED, LOW); 
  }
}

void rightTurn()
{
  for (x=0;x<10;x++)
  {
    digitalWrite(rightSignal, HIGH); 
    digitalWrite(rightLED, LOW); 
    for(y=0;y<10;y++)
    {
      delay(30);
      if (digitalRead(rightSwitch) == LOW)
      {
        while (digitalRead(rightSwitch) == LOW);
        digitalWrite(rightSignal, LOW);  
        digitalWrite(rightLED, LOW); 
        return;
      }
    }
    digitalWrite(rightSignal, LOW); 
    digitalWrite(rightLED, HIGH); 
    for(y=0;y<10;y++)
    {
      delay(30);
      if (digitalRead(rightSwitch) == LOW)
      {
        while (digitalRead(rightSwitch) == LOW);
        digitalWrite(rightSignal, LOW);  
        digitalWrite(rightLED, LOW); 
        return;
      }
    }
    digitalWrite(rightLED, LOW); 
  }
}

void night()
{
  digitalWrite(boardLED, LOW); 
  
  digitalWrite(rightSignal, HIGH); 
  digitalWrite(leftSignal, HIGH);  
  digitalWrite(leftLED, LOW); 
  digitalWrite(rightLED, LOW); 
  delay(100);
  digitalWrite(rightSignal, LOW);  
  digitalWrite(leftSignal, LOW);
  digitalWrite(leftLED, HIGH); 
  digitalWrite(rightLED, HIGH); 
  delay(100);
  digitalWrite(leftLED, LOW); 
  digitalWrite(rightLED, LOW); 
}

void day()
{
  
  digitalWrite(boardLED, HIGH); 
  delay(1);
  digitalWrite(boardLED, LOW); 
  digitalWrite(leftLED, HIGH);
  delay (1);
  digitalWrite(leftLED, LOW);
  digitalWrite(rightLED, HIGH);
  delay(1);
  digitalWrite(rightLED, LOW);
  delay (5);
}

const int ledPin = 9;
const int BUTTON = 2;
boolean run;
boolean lastButton;
boolean currentButton;
void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(BUTTON, INPUT);
}
boolean debounce(boolean last)
{
  boolean current = digitalRead(BUTTON);
  if(last != current)
  {
    delay(5);
    current = digitalRead(BUTTON);
  }
  return current;
}
void loop()
{
  currentButton = debounce(lastButton);
  if(digitalRead(BUTTON) == HIGH && lastButton == LOW && currentButton == HIGH)
  {
    run = !run;
  }
  else if(digitalRead(BUTTON) == LOW && lastButton == HIGH && currentButton == LOW)
  {
    run = run;
  }
  lastButton = currentButton;
  if(run)
    {
      for(int i = 0; i< 256; i++)
      {
        analogWrite(ledPin, i);
        delay(10);
      }
      for(int i= 255; i>=0; i--)
      {
        analogWrite(ledPin, i);
        delay(10); 
      }
   }
  else
  {
    digitalWrite(ledPin, HIGH);
  }

 
}

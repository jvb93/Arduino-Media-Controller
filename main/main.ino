
int encoderPin1 = 2;
int encoderPin2 = 3;
int encoderSwitchPin = 4;

volatile int lastEncoded = 0;
volatile long encoderValue = 0;
volatile int encoderDirection = 0;
long lastencoderValue = 0;

int lastMSB = 0;
int lastLSB = 0;

void setup() 
{
  Serial.begin (9600);

  pinMode(encoderPin1, INPUT);
  pinMode(encoderPin2, INPUT);
  pinMode(encoderSwitchPin, INPUT);

  digitalWrite(encoderPin1, HIGH);
  digitalWrite(encoderPin2, HIGH); 
  digitalWrite(encoderSwitchPin, HIGH); 

  attachInterrupt(0, updateEncoder, CHANGE);
  attachInterrupt(1, updateEncoder, CHANGE);
}

void loop() 
{
  if(!digitalRead(encoderSwitchPin)) 
  {
    Serial.println("pushed");
  }

  if(encoderDirection < 0) 
  {
    Serial.println("down");
  }

  else if(encoderDirection > 0)
  {
      Serial.println("up");
  }

  else 
  {
    Serial.println("no change");
  }

  Serial.println(encoderValue);

  encoderDirection = 0;
  delay(1000); 
}



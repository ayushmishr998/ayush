
int LED = 13;
int sensorPin = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED,OUTPUT);
  pinMode(sensorPin,INPUT);
  Serial.begin(9600);
}

void loop() 
{
  int value=digitalRead(sensorPin);
  Serial.println(value);
  if (value==1)
  {
    digitalWrite(LED,HIGH);
  }
  else
  {
    digitalWrite(LED,LOW);
  }

}

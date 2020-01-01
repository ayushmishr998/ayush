

int msensor=A2;
int msvalue=0;
int led=13;
boolean flag=false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(msensor,INPUT);
  pinMode(led,OUTPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  msvalue=analogRead(msensor);
  Serial.println(msvalue);
  if( (msvalue >=500  ) && ( flag==false ) )
  {
    digitalWrite(led,HIGH);
    flag=true;
    delay(1000);
  }
  
  if( (msvalue <= 300 ) && ( flag==true ))
  {
    digitalWrite(led,LOW);
    flag=false;
    delay(1000);
    
  }
  delay(1000);
}

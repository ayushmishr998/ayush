#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
int led=D5;

const char *ssid     = "Foxtel";
const char *password = "12344321";

const long utcOffsetInSeconds = 19620;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);

void setup(){
  pinMode(led,OUTPUT);
  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }

  timeClient.begin();
}

void loop() {
  timeClient.update();

  Serial.print(daysOfTheWeek[timeClient.getDay()]);
  Serial.print(", ");
  Serial.print(timeClient.getHours());
  Serial.print(":");
  Serial.print(timeClient.getMinutes());
  Serial.print(":");
  Serial.println(timeClient.getSeconds());
  //Serial.println(timeClient.getFormattedTime());
  
  if(timeClient.getDay()==1 ||  timeClient.getDay()==2 || timeClient.getDay()==3 || timeClient.getDay()==4 || timeClient.getDay()==5){
    if(timeClient.getHours()==18 && timeClient.getMinutes()>=0 && timeClient.getHours()<=5){
     digitalWrite(led,HIGH);
    }
    else{
      digitalWrite(led,LOW);}
  }

  

  delay(1000);
}

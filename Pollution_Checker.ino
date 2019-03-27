/*
 *                 --"MADE BY AYUSH AGGARWAL."
 */
#include <LiquidCrystal.h>
const int rs = D8, en = D7, d4 = D3, d5 = D2, d6 = D1, d7 = D0;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
#define MQ135  A0

#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include "ThingSpeak.h"

int air_quality=0;
unsigned long Channel= 741315;
unsigned int t=2;
int addr = 2;
int i=0;
const char *ssid = "AndroidAP";
const char *password = "12345678";
const char *host = "api.thingspeak.com";
String apiKey = "VDML9KT8ZO3QUFF7";

WiFiClient  client;

void LCD1()
{
  lcd.setCursor(0,0);
  lcd.print("                       ");
  lcd.setCursor(0,1);
  lcd.print("                       ");
  delay(1000);
  lcd.setCursor(0,0);
}

void sensor_read()
{
  for(int j=0;j<12;j++)
  {
    air_quality=analogRead(MQ135);
    LCD1();
    lcd.print("Air Quality = ");
    lcd.setCursor(0,1);
    lcd.print(air_quality);
    lcd.print(" PPM");  
    delay(5000);
  }
}

void wifi()
{
  LCD1();
  if(i==0)
  {
    lcd.print("Connecting");
    Serial.println("Connecting");///////////////////////////////////////
  }
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    if(i==0)
    {
      lcd.print(".");
    }
    t++;
    if(t>20)
    {
      LCD1();
      lcd.print("Wifi Not Found");
      Serial.println("Wifi Not Found");////////////////////////////////////////////////////////////////
      delay(1000);
    }
  }
  if(i==0)
  {
    LCD1();
    lcd.print("Connected to:");
    Serial.println("Connected to:");/////////////////////////////////////////////////////////////////////
    lcd.setCursor(0,1);
    lcd.println(ssid);
    i=0;
    delay(2000);
  }
  WiFiClient client;          
  const int httpPort = 80; //Port 80 is commonly used for www
  //Connect to host, host(web site) is define at top 
  if(i==0)
  {
    LCD1();
    lcd.print("Connecting");
    delay(1000);
  }
  if(!client.connect(host, httpPort))
  {
    i++;
    LCD1();
    lcd.print("No Internet");
    Serial.println("No Internet");///////////////////////////////////////////////////////////////////////
    delay(1000);
  }
  else                                                                                                                             // If wifi is connected
  {
      String ADCData;
      ADCData = String(air_quality);   //String to interger conversion 
      String Link="GET /update?api_key="+apiKey+"&field1=";  //Requeste webpage  
      Link = Link + ADCData;
      Link = Link + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n\r\n";                
      client.print(Link);
      delay(100);
      LCD1();
      lcd.print("Upload Complete");
      Serial.println("Upload Complete");///////////////////////////////////////////////////////////////
      delay(1000);
  }  
}

void setup() 
{
  lcd.begin(16, 2); 
  delay(1000);
  pinMode(MQ135,OUTPUT);
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);        //This line hides the viewing of ESP as wifi hotspot
  WiFi.begin(ssid, password);     //Connect to your WiFi router
  ThingSpeak.begin(client);
}

void loop() 
{
  sensor_read();
  if(millis()>900000)
  {
    wifi();
  }
  delay(5000);
}

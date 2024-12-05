//#define BLYNK_TEMPLATE_ID "TMPL4Cti3ha1"
//#define BLYNK_DEVICE_NAME "smarthome"
//#define BLYNK_AUTH_TOKEN "YLT0r5w_Ueh5jAPxBnaZ94mNZaBzRY9S"
#define BLYNK_TEMPLATE_ID "TMPL6Ivn6P1Ml"
#define BLYNK_TEMPLATE_NAME "tes"
#define BLYNK_AUTH_TOKEN "kc-sDaWegq5F1tgnYxEjXJOxexDAkhlY"
// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h> 
//#include <WiFi.h>
//#include <WiFiClient.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "AA";  // type your wifi name
char pass[] = "123321123";  // type your wifi password

BlynkTimer timer;



#define relay1_pin 5
#define relay2_pin 4
#define relay3_pin 0
#define relay4_pin 2
#define relay5_pin 14
#define relay6_pin 12
#define relay7_pin 13
#define relay8_pin 15

int relay1_state = 0;
int relay2_state = 0;
int relay3_state = 0;
int relay4_state = 0;
int relay5_state = 0;
int relay6_state = 0;
int relay7_state = 0;
int relay8_state = 0;


//Change the virtual pins according the your Wish
#define button1_vpin    V1
#define button2_vpin    V2
#define button3_vpin    V3 
#define button4_vpin    V4
#define button5_vpin    V5
#define button6_vpin    V6
#define button7_vpin    V7 
#define button8_vpin    V8


BLYNK_CONNECTED() {
  Blynk.syncVirtual(button1_vpin);
  Blynk.syncVirtual(button2_vpin);
  Blynk.syncVirtual(button3_vpin);
  Blynk.syncVirtual(button4_vpin);
  Blynk.syncVirtual(button5_vpin);
  Blynk.syncVirtual(button6_vpin);
  Blynk.syncVirtual(button7_vpin);
  Blynk.syncVirtual(button8_vpin);
}


BLYNK_WRITE(button1_vpin) {
  relay1_state = param.asInt();
  digitalWrite(relay1_pin, ! relay1_state);
   Serial.print("Relay 1 ");
   if(relay1_state==0)
   Serial.println("OFF");
   else
   Serial.println("ON");
}
//--------------------------------------------------------------------------
BLYNK_WRITE(button2_vpin) {
  relay2_state = param.asInt();
  digitalWrite(relay2_pin,  ! relay2_state);
   Serial.print("Relay 2 ");
   if(relay2_state==0)
   Serial.println("OFF");
   else
   Serial.println("ON");
}
//--------------------------------------------------------------------------
BLYNK_WRITE(button3_vpin) {
  relay3_state = param.asInt();
  digitalWrite(relay3_pin, ! relay3_state);
   Serial.print("Relay 3 ");
   if(relay3_state==0)
   Serial.println("OFF");
   else
   Serial.println("ON");
}
//--------------------------------------------------------------------------
BLYNK_WRITE(button4_vpin) {
  relay4_state = param.asInt();
  digitalWrite(relay4_pin, ! relay4_state);
   Serial.print("Relay 4 ");
   if(relay4_state==0)
   Serial.println("OFF");
   else
   Serial.println("ON");
}
//--------------------------------------------------------------------------
BLYNK_WRITE(button5_vpin) {
  relay5_state = param.asInt();
  digitalWrite(relay5_pin, ! relay4_state);
   Serial.print("Relay 5 ");
   if(relay5_state==0)
   Serial.println("OFF");
   else
   Serial.println("ON");
}
//--------------------------------------------------------------------------
BLYNK_WRITE(button6_vpin) {
  relay6_state = param.asInt();
  digitalWrite(relay6_pin, ! relay6_state);
   Serial.print("Relay 6 ");
   if(relay6_state==0)
   Serial.println("OFF");
   else
   Serial.println("ON");
}
//--------------------------------------------------------------------------
BLYNK_WRITE(button7_vpin) {
  relay7_state = param.asInt();
  digitalWrite(relay7_pin, ! relay7_state);
   Serial.print("Relay 7 ");
   if(relay7_state==0)
   Serial.println("OFF");
   else
   Serial.println("ON");
}
//--------------------------------------------------------------------------
BLYNK_WRITE(button8_vpin) {
  relay8_state = param.asInt();
  digitalWrite(relay8_pin, ! relay8_state);
   Serial.print("Relay 8 ");
   if(relay8_state==0)
   Serial.println("OFF");
   else
   Serial.println("ON");
}
//--------------------------------------------------------------------------


void setup()
{
  // Debug console
  Serial.begin(115200);
 
 
  //--------------------------------------------------------------------
  pinMode(relay1_pin, OUTPUT);
  pinMode(relay2_pin, OUTPUT);
  pinMode(relay3_pin, OUTPUT);
  pinMode(relay4_pin, OUTPUT);
   pinMode(relay5_pin, OUTPUT);
  pinMode(relay6_pin, OUTPUT);
  pinMode(relay7_pin, OUTPUT);
  pinMode(relay8_pin, OUTPUT);
  //--------------------------------------------------------------------
  //During Starting all Relays should TURN OFF
  digitalWrite(relay1_pin, HIGH);
  digitalWrite(relay2_pin, HIGH);
  digitalWrite(relay3_pin, HIGH);
  digitalWrite(relay4_pin, HIGH);
  digitalWrite(relay5_pin, HIGH);
  digitalWrite(relay6_pin, HIGH);
  digitalWrite(relay7_pin, HIGH);
  digitalWrite(relay8_pin, HIGH);
  //--------------------------------------------------------------------
  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
  //--------------------------------------------------------------------
  Blynk.virtualWrite(button1_vpin, relay1_state);
  Blynk.virtualWrite(button2_vpin, relay2_state);
  Blynk.virtualWrite(button3_vpin, relay3_state);
  Blynk.virtualWrite(button4_vpin, relay4_state);
  Blynk.virtualWrite(button5_vpin, relay5_state);
  Blynk.virtualWrite(button6_vpin, relay6_state);
  Blynk.virtualWrite(button7_vpin, relay7_state);
  Blynk.virtualWrite(button8_vpin, relay8_state);
  //--------------------------------------------------------------------
}

void loop()
{
  Blynk.run();
  timer.run();
 
}
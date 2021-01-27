#include <ESP8266WiFi.h>;
#include <WiFiClient.h>;
#include <ThingSpeak.h>;

const char* ssid = "DS Guests"; //Your Network SSID
const char* password = "12345678"; //Your Network Password

int val;
int LDRpin = A0; //LDR Pin Connected at A0 Pin

WiFiClient client;

unsigned long myChannelNumber = 1291196; //Your Channel Number (Without Brackets)
const char * myWriteAPIKey = "O2DK78IT3LZEUE20"; //Your Write API Key

void setup()
{
  Serial.begin(115200);
  delay(10);
  // Connect to WiFi network
  WiFi.begin(ssid, password);
  ThingSpeak.begin(client);
}

void loop()
{
  val = analogRead(LDRpin); //Read Analog values and Store in val variable
  Serial.println(val); //Print on Serial Monitor
  delay(1000);
  ThingSpeak.writeField(myChannelNumber, 1,val, myWriteAPIKey); //Update in ThingSpeak
  delay(100);
}

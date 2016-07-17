#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "xxxxxxxxxxxxxxxxxxxxxxxx";  
int analogPin = A0;  
String stringMail = "The mailbox has been opened! Battery voltage is: ";

void setup()  
{
  Serial.begin(115200);
   Serial.println("BEGIN");
   Blynk.begin(auth, "ssid", "password");
}
void loop() {  
  while (Blynk.connect() == false) {
    // Wait until connected
  }
  BLYNK_LOG("Switch Open");
  int battlevel = analogRead(analogPin);
  float voltage = battlevel * (4.2 / 1024.0); // 4.2 is the nominal voltage of the 18560 battery
  Blynk.email("xxxxxx@gmail.com", "From Blynk", stringMail + voltage);
  BLYNK_LOG("Going to Sleep");
  ESP.deepSleep(0);
}
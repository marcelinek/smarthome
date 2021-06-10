#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char token[] = "tokenı gir";
char agadi[] = "ağ adını gir";
char agsifre[] = "ağ şifresini gir";

#define gazsinyal A0
int gazdeger;
bool bildirim = true;

BlynkTimer timer;


void gazoku (){
  gazdeger = analogRead(gazsinyal);
  Blynk.virtualWrite(V1,gazdeger);
  
  if (gazdeger >= 10){
    Serial.println ("Gaz Sensörü Aktif");
    Blynk.notify ("Gaz Sensörü Aktif");
    bildirim = true;
  }
  else{
    bildirim = false;
  }
}

void setup() {
  Serial.begin(9600);
  Blynk.begin(token, agadi, agsifre);
  Blynk.notify ("Cihaz Açıldı");
  timer.setInterval(100L, gazoku);
}

void loop() {
  Blynk.run();
  timer.run();
}

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char token[] = "tokenı gir";
char agadi[] = "ağ adını gir";
char agsifre[] = "ağ şifresini gir";

#define pirPin D1
int pirDeger;
bool bildirim = true;

BlynkTimer timer;


void degeroku(){
  pirDeger = digitalRead (pirPin);
  Blynk.virtualWrite(V1, pirDeger);
  
  if (pirDeger) {
    Serial.println ("Hareket Algılandı");
    Blynk.notify ("Hareket Algılandı");
    bildirim = true;
  }
  else{
    bildirim = false;
  }
}

void setup () {
  Serial.begin (9600);
  Blynk.begin (token, agadi, agsifre);
  Blynk.notify ("Cihaz Açıldı");
  pinMode (pirPin, INPUT);
}

void loop(){
  Blynk.run();
  timer.run();
}

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char token[] = "tokenı gir";
char agadi[] = "ağ adını gir";
char agsifre[] = "ağ şifresini gir";

int pirPin = D1; // PIR pin
int ledPin = D7; // LED pin
int deger = false;
bool bildirim = true;

BlynkTimer timer;

void setup() {
Serial.begin(9600); //Serial Porttan veri göndermek için baundrate ayarlanıyor.
Blynk.begin (token, agadi, agsifre);
Blynk.notify ("Cihaz Açıldı");
pinMode(pirPin, INPUT); // PIR Pin'i giriş yapılıyor
pinMode(ledPin, OUTPUT); // LED Pin'i çıkış yapılıyor
}

void degeroku(){
  deger = digitalRead (pirPin); // dijital pin okunuyor.
  Blynk.virtualWrite(V1, deger);
  Serial.println(deger); // Okunan değer seri porttan okunuyor.
  
  if (deger == HIGH) {
    digitalWrite(ledPin, HIGH); // Eğer okunan değer 1 ise LED yakılıyor.
    }
  else{
    digitalWrite(ledPin,LOW); // Eğer okunan değer 0 ise LED söndürülüyor.
    } 
}
 
void loop(){
  Blynk.run();
  timer.run();
}

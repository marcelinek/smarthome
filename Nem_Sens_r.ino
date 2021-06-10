#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>  //Gerekli kütüphanelerimizi ekliyoruz.
#include <BlynkSimpleEsp8266.h>

char token[] = "oYSunvbqlsSTId0G_l5SBLyACXFUoFd_";
char agAdi[] = "Sampo_GargameL"; //Blynk uygulamasının bize vermiş olduğu token ve bağlanmak istediğimiz wifi ve şifresini char komutu ile belirliyoruz.
char agSifre[] = "SAMPO5064744118";
int deger ;      // okuma yapacağımız nem değerini deger değişkeni olarak belirliyoruz.
int donusum ;

#define sensor A0  // Sensor okuma yapacağımız pini burada belirliyoruz. 
void setup() {
  
  
  Serial.begin(9600);   //Blynk ve ESP iletişimi için serial monitörü başlatıyoruz.
  
  Blynk.begin(token, agAdi, agSifre);  // blynk uygulaması ve ESP bağlantısı sağlanması açısından Blynk.begin komutu içerisine token ve ag adı,şifremizi yazıyoruz.
  
}

void loop() {
    deger = analogRead(A0);     //toprak nem sensöründen analog okuma yapıyoruz.
  donusum = map(deger ,0,1023,0,100);      // okunan bu değer 0-1023 değeri arasında olacağı için burada map komutu ile istediğimiz 0-100 aralığına çeviriyoruz.
  Blynk.virtualWrite (V1, donusum);
  Blynk.run();            //Blynk uygulamasını başlatıyoruz.
 

}

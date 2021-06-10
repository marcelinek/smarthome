// NOTALARI TANIMLIYORUZ
#define dok  1000 // kalin do
#define re   1122
#define mi   1260
#define fa   1335
#define sol  1498
#define la   1681
#define si   1887
#define doi  2000 // ince do

#define echoPin 13
#define trigPin 12
#define buzzerPin 11

int melodi[] =     {dok,re,doi ,si,dok,si,dok,re,doi ,si,dok,si,dok,re,doi ,si,dok,si,  la,si,la,sol,fa,la };
int notasuresi[] = {6, 6, 2, 6, 6, 2, 6, 6, 2, 6, 6, 2, 6, 6, 2, 6, 6, 2, 6, 9, 8, 5, 5, 2 };
int tempo = 1200;
int olcum;
int sure;

void setup()
{
  
    
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trigPin,HIGH);
  delay(1);
  digitalWrite(trigPin,LOW);
  
  sure = pulseIn(echoPin,HIGH);
  olcum=(sure/2)/28.9;

Serial.println("UZAKLIK =");
Serial.print(olcum);
Serial.println("cm"); 
Serial.println("-------------------------------"); 

    if (olcum < 50){
      for (int Nota = 0; Nota <24; Nota++) 
    {
      int sure = tempo/notasuresi[Nota];
     tone(11, melodi[Nota],sure);
     delay(sure*1.2);
    }
      digitalWrite(buzzerPin, HIGH);
        }

      else{
        digitalWrite(buzzerPin, LOW );
        }
}

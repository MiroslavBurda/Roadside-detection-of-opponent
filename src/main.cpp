// HC-SR04 catches double-reflector between 70-45 cm of distance, if is underlayed with cca 3mm thin material

#include <Arduino.h>

#define FIRMWARE 0.1
//variables
int pTrig[8] = {13, 10, 11, 12, A0, A1, A2, A3};
int pEcho[8] = {2, 3, 4, 5, 6, 7, 8, 9};
long response[8]; 
float distance[8];
int min_first = 32500; 
u_int8 min_last = 254;

void setup()  {
  Serial.begin(115200);
  Serial.print("Started");
  for (int i; i < 8; i++) {
    pinMode(pEcho[i], INPUT);
    pinMode(pTrig[i], OUTPUT);
  }
}

void loop()
{
  int min = min_frst;
  for (int i = 0; i < 8; i++)
  {
    digitalWrite(pTrig[i], LOW);
    delayMicroseconds(5);
    digitalWrite(pTrig[i], HIGH);
    delayMicroseconds(10);
    digitalWrite(pTrig[i], LOW);
    response[i] = pulseIn(pEcho[i], HIGH);
    distance[i] = response[i] / 58.31;
    if (distance[i] < min) 
        min = distance[i];
    // TOHLE V OSTRE VERZI PRYC ************************************
    Serial.print(i);   // debug
    Serial.print(": ");
    Serial.print(distance[i]);
    Serial.print("; ");
    delay(50); // without this, it will measure max. distance cca 130 cm
  }
  if (min > 255) 
      min = 255;
  min_last = min;
  Serial.println(min_last);
  delay(500);  // TOHLE V OSTRE VERZI PRYC ************************************
  Serial.print(millis()); // TOHLE TAKY 
}

https://uart.cz/271/arduino-a-preruseni/
pin rising - nastavit v hlavním programu - nezapomenout ho zase sesadit 
posílat chci pouze 1 bajt -> jak to udělat z typu int
počkám na něj ve smyčce + ošetrit konec čekání a chybovou hlášku, když bude problém 




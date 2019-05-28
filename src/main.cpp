// bere dvojity odrazec mezi 70-45 cm vzdalenosti, kdyz je podlozen 3mm preklizky 

#include <Arduino.h>

#define FIRMWARE 0.1
//variables
int pTrig[8] = {13, 10, 11, 12, A0, A1, A2, A3};
int pEcho[8] = {2, 3, 4, 5, 6, 7, 8, 9};
long response[8]; 
float distance[8];

void setup()  {
  Serial.begin(115200);
  Serial.print("Ahoj");
  for (int i; i < 8; i++) {
    pinMode(pEcho[i], INPUT);
    pinMode(pTrig[i], OUTPUT);
  }
 }

void loop()
{
  
  for (int i = 0; i < 8; i++)
  {
    digitalWrite(pTrig[i], LOW);
    delayMicroseconds(5);
    digitalWrite(pTrig[i], HIGH);
    delayMicroseconds(10);
    digitalWrite(pTrig[i], LOW);
    response[i] = pulseIn(pEcho[i], HIGH);
    distance[i] = response[i] / 58.31;
    Serial.print(i);
    Serial.print(": ");
    Serial.print(distance[i]);
    Serial.print("; ");
    delay(50); // if nebude, bude merit max. vzdalenost tak 130 cm, to by nemuselo tak vadit 
  }
  Serial.println();
  delay(500);
  Serial.print(millis());
}


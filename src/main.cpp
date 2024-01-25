#include <Arduino.h>
#include "inindThread.h"

#define LEDPIN 3           // the number of the LED pin
#define LED_INTERVAL 500.0 // interval at which to blink (milliseconds)
#define GridFreq 1.0       // Nominal Grid Frequency in Hz
#define Fs 1000.0          // Sampling frequency = 1Khz
#define Tfinal 0.1         // Time the simulation
#define AMPLITUDE 10       // Amplitude da Onda

// Variaveis calculadas
const double T = (1.0 / GridFreq); // Periodo do Sinal
const double Ts = (1.0 / Fs);      // Sampling Time = 1/Fs

double onda = 0;
double timeStamp = 0;
double aux = 0;

void OndaFunc()
{
  aux = (aux <= T + Ts ? aux + Ts : 0);
  timeStamp += (Ts * 1000);
  onda = (AMPLITUDE / T) * aux; // y = m*x onde m = A/T e x = n % T
  Serial.print(">onda:");
  Serial.print(timeStamp);
  Serial.print(":");
  Serial.print(onda);
  Serial.println("§Volts|g");
}

void ledFunc()
{
  digitalWrite(LEDPIN, !digitalRead(LEDPIN));
}

void setup()
{
  pinMode(LEDPIN, OUTPUT);
  Serial.begin(115200);
  threadSetup(ledFunc, LED_INTERVAL, OndaFunc, (int)(Ts * 1000), NULL);
}

void loop()
{
  // put your main code here, to run repeatedly:
}
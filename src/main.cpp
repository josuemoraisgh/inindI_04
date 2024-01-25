#include <Arduino.h>
#include "inindThread.h"

#define LEDPIN 3         // the number of the LED pin
#define LED_INTERVAL 500 // interval at which to blink (milliseconds)
#define GridFreq 100     // Nominal Grid Frequency in Hz
#define Fs 10000         // Sampling frequency = 10Khz
#define Tfinal 0.1       // Time the simulation
#define AMPLITUDE 10     // Amplitude da Onda

// Variaveis calculadas
#define T 1 / GridFreq     // Periodo do Sinal
#define Ts 1 / Fs          // Sampling Time = 1/Fs
#define w 2 * pi *GridFreq // Frequencia Angular

double onda = 0;
unsigned long count = 0;

void ledFunc()
{
  count += Ts;
  onda = (AMPLITUDE / T) * (count % T); // y = m*x onde m = A/T e x = n % T
  Serial.print(">onda:");
  Serial.print(count);
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
  threadSetup(ledFunc, LED_INTERVAL, NULL);
}

void loop()
{
  // put your main code here, to run repeatedly:
}
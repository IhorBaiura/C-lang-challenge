/*
 *
 * This program prints table of convertion Fahrenheit defrees for Celsius.
 *
 * Range: 0-300
 * Step: 20
 *
 */

#include <stdio.h>

float transformFahrToCelsius(float fahr) { return 5.0 * (fahr - 32.0) / 9.0; }

int main(int argc, char *argv[]) {
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  while (fahr <= upper) {
    celsius = transformFahrToCelsius(fahr);
    printf("%3.0f :F -|- C: %6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
}

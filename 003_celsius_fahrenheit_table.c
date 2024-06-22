/*
 *
 * This program prints table of convertion defrees Celsius for Fahrenheit.
 *
 * Range: -50 - 150
 * Step: 10
 *
 */

#include <stdio.h>

float transformCelsiusToFahr(float celsius) {
  return (celsius * (9.0 / 5.0)) + 32.0;
}

int main(int argc, char *argv[]) {
  float fahr, celsius;
  int lower, upper, step;

  lower = -50;
  upper = 150;
  step = 10;

  printf("Celsius | Fahrenheit\n");
  printf("____________________\n");

  celsius = lower;
  while (celsius <= upper) {
    fahr = transformCelsiusToFahr(celsius);
    printf("%7.0f | %9.1f\n", celsius, fahr);
    celsius = celsius + step;
  }
}

/*
 *
 * This program prints table of convertion Fahrenheit defrees for Celsius.
 *
 * with FOR loop
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

  printf("Fahrenheit | Celsius\n");
  printf("____________________\n");

  for (fahr = 300; fahr >= 0; fahr = fahr - 20) {
    printf("%10.0f | %7.1f\n", fahr, transformFahrToCelsius(fahr));
  }
}

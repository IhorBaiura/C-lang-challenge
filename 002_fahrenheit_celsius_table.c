/*
 *
 * This program prints table of convertion Fahrenheit defrees for Celsius.
 *
 * Range: 0-300
 * Step: 20
 *
 */

#include <stdio.h>

int transformFahrToCelsius(int fahr) { return 5 * (fahr - 32) / 9; }

int main(int argc, char *argv[]) {
  int fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  while (fahr <= upper) {
    celsius = transformFahrToCelsius(fahr);
    printf("%d\t%d\n", fahr, celsius);
    fahr = fahr + step;
  }
}

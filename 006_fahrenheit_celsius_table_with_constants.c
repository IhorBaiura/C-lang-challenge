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

#define LOWER 0
#define UPPER 300
#define STEP 20

float transformFahrToCelsius(float fahr) { return 5.0 * (fahr - 32.0) / 9.0; }

int main(int argc, char *argv[]) {
  float fahr;

  printf("Fahrenheit | Celsius\n");
  printf("____________________\n");

  for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP) {
    printf("%10.0f | %7.1f\n", fahr, transformFahrToCelsius(fahr));
  }
}

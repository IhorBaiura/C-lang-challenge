/*
 *
 * 1. bit masking
 *
 */

#include <stdio.h>

void printb(int num);

int main(int argc, char *argv[]) {
  int num = 125;

  printb(num);
  printb(573);

  return 0;
}

void printb(int num) {
  char binary[sizeof(unsigned int) * 8];
  int i, j;

  for (i = 0; num > 0; i++) {
    binary[i] = num % 2;
    num /= 2;
  }

  while (i % 4 != 0)
    binary[i++] = 0;

  for (j = i - 1; j >= 0; j--) {
    if ((j + 1) % 4 == 0 && j != i - 1)
      printf(" ");
    printf("%d", binary[j]);
  }
  printf("\n");
}

/*
 *
 * & (AND):
 * 1. bit masking
 * 2. parity
 *
 */

#include <stdio.h>
// #include <time.h>

#define BITE_SIZE 8

void printb(int num);
void printb_bitwice(int num);
unsigned int bit_masking(unsigned int num, unsigned int mask);
char parity(int num);

int main(int argc, char *argv[]) {
  // int num = 125;
  //
  // printb(num);
  // printb(573);
  // printb(0);

  /*clock_t begin_loop = clock();
  for (int i = 0; i < 1000000000; i++)
    printb(15758);
  clock_t end_loop = clock();

  clock_t begin_smart = clock();
  for (int i = 0; i < 1000000000; i++)
    printb_bitwice(15758);
  clock_t end_smart = clock();

  printf("printb\t\t: time: %f\n",
         (double)(end_loop - begin_loop) / CLOCKS_PER_SEC);
  printf("printb_bitwice\t: tiem: %f\n",
         (double)(end_smart - begin_smart) / CLOCKS_PER_SEC);*/

  /*
   *
   * iterations count: 1 000 000
   * printb          : time: 0.076132
   * printb_bitwice  : tiem: 0.047023    ~ 40% faster
   *
   * iterations count: 100 000 000
   * printb          : time: 4.794608
   * printb_bitwice  : tiem: 4.521706    ~ 8% faster
   *
   * iterations count: 1 000 000 000
   * printb          : time: 47.546372
   * printb_bitwice  : tiem: 45.208066   ~ 5% faster
   *
   */

  bit_masking(125, 15);
  bit_masking(1275, 255);

  parity(125);
  parity(124);

  return 0;
}

void printb(int num) {
  char binary[sizeof(unsigned int) * BITE_SIZE];
  int i, j;

  i = 0;
  if (num == 0)
    binary[i++] = 0;
  else
    while (num > 0) {
      binary[i++] = num % 2;
      num /= 2;
    }

  while (/* i % 4 != 0 &&  */ i % (2 * BITE_SIZE) != 0)
    binary[i++] = 0;

  for (j = i - 1; j >= 0; j--) {
    if ((j + 1) % 4 == 0 && j != i - 1)
      printf(" ");
    printf("%d", binary[j]);
  }
  printf("\n");
}

void printb_bitwice(int num) {
  char binary[sizeof(unsigned int) * 8];
  int i, j;

  i = 0;
  if (num == 0)
    binary[i++] = 0;
  else
    while (num > 0) {
      binary[i++] = num & 1;
      num >>= 1;
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

unsigned int bit_masking(unsigned int num, unsigned int mask) {
  unsigned int res = num & mask;

  printf("number\t: ");
  printb(num);
  printf("mask\t: ");
  printb(mask);
  printf("result\t: ");
  printb(res);
  printf("\n");

  return res;
}

char parity(int num) {
  if (num & 1) {
    printf("%d is odd\n", num);
    return 1;
  } else {
    printf("%d is even\n", num);
    return 0;
  }

  // return num & 1;
}

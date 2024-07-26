#include <stdio.h>

long pow_loop(const int num, const unsigned int pow);

int main(int argc, char *argv[]) {
  int num = 5;
  int pow = 3;

  printf("pow_loop: %d ^ %d = %ld\n", num, pow, pow_loop(num, pow));

  int num1 = 5;
  int pow1 = 0;

  printf("pow_loop: %d ^ %d = %ld\n", num1, pow1, pow_loop(num1, pow1));

  int num2 = 5;
  int pow2 = 1;

  printf("pow_loop: %d ^ %d = %ld\n", num2, pow2, pow_loop(num2, pow2));

  return 0;
}

long pow_loop(const int num, const unsigned int pow) {
  int i;
  long res;

  res = 1;
  for (i = 1; i <= pow; i++)
    res *= num;

  return res;
}

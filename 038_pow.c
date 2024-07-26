#include <stdio.h>
#include <time.h>

long long pow_loop(const int num, const unsigned int pow);
long long _pow(const int num, const unsigned int pow);

int main(int argc, char *argv[]) {
  int num = 5;
  int pow = 3;

  printf("pow_loop: %d ^ %d = %lld\n", num, pow, pow_loop(num, pow));
  printf("_pow: %d ^ %d = %lld\n", num, pow, _pow(num, pow));

  int num1 = 5;
  int pow1 = 0;

  printf("pow_loop: %d ^ %d = %lld\n", num1, pow1, pow_loop(num1, pow1));
  printf("_pow: %d ^ %d = %lld\n", num1, pow1, _pow(num1, pow1));

  int num2 = 5;
  int pow2 = 1;

  printf("pow_loop: %d ^ %d = %lld\n", num2, pow2, pow_loop(num2, pow2));
  printf("_pow: %d ^ %d = %lld\n", num2, pow2, _pow(num2, pow2));

  int num3 = 5;
  int pow3 = 4;

  printf("pow_loop: %d ^ %d = %lld\n", num3, pow3, pow_loop(num3, pow3));
  printf("_pow: %d ^ %d = %lld\n", num3, pow3, _pow(num3, pow3));

  int num4 = 5;
  int pow4 = 977;

  clock_t begin_loop = clock();
  long long res4_loop = 0;
  for (int i = 0; i < 1000000; i++)
    res4_loop = pow_loop(num4, pow4);
  clock_t end_loop = clock();

  clock_t begin_smart = clock();
  long long res4_smart = 0;
  for (int i = 0; i < 1000000; i++)
    res4_smart = _pow(num4, pow4);
  clock_t end_smart = clock();

  printf("pow_loop: %d ^ %d = %lld\t\t time: %f\n", num4, pow4,
         pow_loop(num4, pow4),
         (double)(end_loop - begin_loop) / CLOCKS_PER_SEC);
  printf("_pow\t: %d ^ %d = %lld\t\t tiem: %f\n", num4, pow4, _pow(num4, pow4),
         (double)(end_smart - begin_smart) / CLOCKS_PER_SEC);

  // pow_loop: 5 ^ 777 = 7816586455663677797       time: 0.673203
  // _pow    : 5 ^ 777 = 7816586455663677797       tiem: 0.034117  ~20x faster

  return 0;
}

long long pow_loop(const int num, const unsigned int pow) {
  int i;
  long res;

  res = 1;
  for (i = 1; i <= pow; i++)
    res *= num;

  return res;
}

long long _pow(const int num, const unsigned int pow) {
  int i;
  long long res;

  res = 1;

  if (pow == 0)
    return res;
  if (pow == 1)
    return num;
  if (pow % 2 != 0)
    return num * _pow(num, pow - 1);

  res = _pow(num, pow / 2);
  return res * res;
}

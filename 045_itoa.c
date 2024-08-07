/*
 *
 * Exercise 3-4. In a two’s complement number representation, our version of
 * itoa does not handle the largest negative number, that is, the value of n
 * equal to -(2wordsize−1). Explain why not. Modify it to print that value
 * correctly, regardless of the machine on which it runs.
 *
 * Exercise 3-6. Write a version of itoa that accepts three arguments instead
 * of two. The third argument is a minimum field width; the converted number
 * must be padded with blanks on the left if necessary to make it wide enough.
 *
 */

#include <limits.h>
#include <stdio.h>
#include <string.h>

#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define PURPLE "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

#define abs(x) ((x) < 0 ? -(x) : (x))

void itoa(int n, char s[]);
void itoa_imp(int n, char s[]);
void itoa_ext(int n, char s[], int min_width);

void run_test(int n, const char *expected) {
  char s[20], res;
  itoa_imp(n, s);
  res = strcmp(s, expected) == 0;
  printf("%sitoa(%d) -> \"%s\" (Expected: \"%s\") - %s%s\n", res ? GREEN : RED,
         n, s, expected, res ? "PASS" : "FAIL", WHITE);
}

void run_test_ext(int n, int min_width, const char *expected) {
  char s[100], res;
  itoa_ext(n, s, min_width);
  res = strcmp(s, expected) == 0;
  printf("%sitoa_ext(%d, min_width %d) -> \"%s\" (Expected: \"%s\") - %s%s\n",
         res ? GREEN : RED, n, min_width, s, expected, res ? "PASS" : "FAIL",
         WHITE);
}

int main() {
  run_test(0, "0");
  run_test(7, "7");
  run_test(-7, "-7");
  run_test(1234, "1234");
  run_test(-1234, "-1234");
  run_test(-2147483648, "-2147483648"); // Assuming 32-bit integer
  run_test(2147483647, "2147483647");   // Assuming 32-bit integer
  run_test(987654321, "987654321");
  run_test(1, "1");
  run_test(-1, "-1");

  printf("int: %ld\n", sizeof(int) * 8);

  run_test_ext(123, 3, "123");
  run_test_ext(123, 5, "  123");
  run_test_ext(-456, 4, "-456");
  run_test_ext(-78, 6, "   -78");
  run_test_ext(0, 4, "   0");
  run_test_ext(INT_MIN, 12, " -2147483648"); // Assuming 32-bit int
  run_test_ext(INT_MAX, 10, "2147483647");   // Assuming 32-bit int
  run_test_ext(987654321, 5, "987654321");
  run_test_ext(-12, 3, "-12");
  run_test_ext(7, 4, "   7");

  return 0;
}

void reverse(char s[]) {
  int i, j, c;

  for (i = 0; s[i] != '\0' && s[i] != '\n'; i++)
    ;
  for (j = 0, --i; j <= (i / 2); j++) {
    c = s[j];
    s[j] = s[i - j];
    s[i - j] = c;
  }
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[]) {
  int i, sign;

  i = 0;
  if (n == INT_MIN) {
    sign = -1;
    n = -(n + 1);
    s[i++] = n % 10 + 1 + '0';
    n /= 10;
  } else if ((sign = n) < 0) {
    n = -n;
  }

  do
    s[i++] = n % 10 + '0';
  while ((n /= 10) > 0);

  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';

  reverse(s);
}

void itoa_imp(int n, char s[]) {
  int i, sign;

  sign = n;
  i = 0;
  do {
    s[i++] = abs(n % 10) + '0';
  } while ((n /= 10) != 0);

  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';

  reverse(s);
}

void itoa_ext(int n, char s[], int min_width) {
  int i, sign;

  sign = n;
  i = 0;
  do {
    s[i++] = abs(n % 10) + '0';
  } while ((n /= 10) != 0);

  if (sign < 0)
    s[i++] = '-';

  while ((i + 1) <= min_width)
    s[i++] = ' ';

  s[i] = '\0';

  reverse(s);
}

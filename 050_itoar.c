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

void itoa_r(int n, char s[]);

void run_test(int n, const char *expected) {
  char s[20], res;
  itoa_r(n, s);
  res = strcmp(s, expected) == 0;
  printf("%sitoa(%d) -> \"%s\" (Expected: \"%s\") - %s%s\n", res ? GREEN : RED,
         n, s, expected, res ? "PASS" : "FAIL", WHITE);
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

  return 0;
}

void itoa_r(int n, char s[]) {
  static int i = 0;

  if (n / 10) {
    itoa_r(n / 10, s);
  } else {
    i = 0;
    if (n < 0)
      s[i++] = '-';
  }

  s[i++] = abs(n % 10) + '0';
  s[i] = '\0';
}

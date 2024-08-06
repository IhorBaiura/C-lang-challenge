/*
 *
 * Exercise 3-5. Write the function itob(n,s,b) that converts the integer n
 * into a base b character representation in the string s. In particular,
 * itob(n,s,16) formats n as a hexadecimal integer in s.
 *
 */

#include <limits.h>
#include <stdio.h>
#include <string.h>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define WHITE "\033[37m"

#define NUMBERS "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"

void itob(int n, char s[], int b);
void run_test(int n, int b, const char *expected);

int main() {
  // run_test(0, 2, "0");
  // run_test(5, 2, "101");
  // run_test(-5, 2, "-101");
  // run_test(123, 8, "173");
  // run_test(-123, 8, "-173");
  // run_test(123, 10, "123");
  // run_test(-123, 10, "-123");
  // run_test(255, 16, "FF");
  // run_test(-255, 16, "-FF");
  // run_test(735, 16, "2DF");
  // run_test(1024, 2, "10000000000");
  // run_test(4095, 16, "FFF");
  // run_test(-2147483648, 16, "-80000000");
  // run_test(2147483647, 16, "7FFFFFFF");
  // run_test(-2147483648, 10, "-2147483648");
  // run_test(2147483647, 10, "2147483647");
  run_test(-2147483648, 2, "-10000000000000000000000000000000");
  // run_test(-2147483648, 4, "-2000000000000000");
  // run_test(-2147483648, 8, "-20000000000");
  // run_test(-2147483648, 32, "-2000000");
  // run_test(75, 5, "300");
  // run_test(-75, 7, "-135");
  // run_test(74765, 27, "3LF2");
  // run_test(74765, 36, "1LOT");

  // run_test(5, 1, "101");

  return 0;
}

void run_test(int n, int b, const char *expected) {
  char s[100], res;
  itob(n, s, b);

  res = strcmp(s, expected) == 0;

  printf("%sitob(%d, base %d) -> \"%s\" (Expected: \"%s\") - %s\n%s",
         res ? GREEN : RED, n, b, s, expected, res ? "PASS" : "FAIL", WHITE);
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

void itob(int n, char s[], int b) {
  int i, sign, cary;
  char num[] = NUMBERS;

  if (b > 36 || b < 2) {
    printf("%s The base is out of the range [2; 36].\n%s", RED, WHITE);
  }

  i = 0;
  cary = 0;
  sign = n;

  if (n == INT_MIN) {
    n = -(n + 1);
    s[i++] = num[(n % b + 1) % b];
    cary = (n % b + 1) / b;
    n /= b;
  } else if (sign < 0) {
    n = -n;
  }

  do {
    if (cary != 0) {
      s[i++] = num[(n % b + cary) % b];
      cary = (n % b + cary) / b;
    } else
      s[i++] = num[n % b];
  } while ((n /= b) > 0);

  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';

  reverse(s);
}

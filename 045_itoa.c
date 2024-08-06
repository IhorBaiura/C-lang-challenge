

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

void itoa(int n, char s[]);

void run_test(int n, const char *expected) {
  char s[20], res;
  itoa(n, s);
  res = strcmp(s, expected) == 0;
  printf(res ? GREEN : RED);
  printf("itoa(%d) -> \"%s\" (Expected: \"%s\") - %s\n", n, s, expected,
         res ? "PASS" : "FAIL");
  printf(WHITE);
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

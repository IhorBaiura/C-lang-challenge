/*
 *
 * Exercise 2-3. Write the function htoi(s), which converts a string of
 * hexadecimal digits (including an optional 0x or 0X) into its equivalent
 * integer value. The allowable digits are 0 through 9, a through f, and A
 * through F.
 *
 */

#include <stdio.h>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define WHITE "\033[37m"

long int htoi(char *);

void test_htoi(char *s, int expected) {
  int result = htoi(s);

  if (result == expected) {
    printf(GREEN);
    printf("PASS: htoi(\"%s\") -> %d\n", s, result);
  } else {
    printf(RED);
    printf("FAIL: htoi(\"%s\") -> %d (Expected: %d)\n", s, result, expected);
  }
  printf(WHITE);
}

int main(int argc, char *argv[]) {
  test_htoi("1A", 26);
  test_htoi("0x1A", 26);
  test_htoi("0X1A", 26);
  test_htoi("a9", 169);
  test_htoi("AbC", 2748);
  test_htoi("00001A", 26);
  test_htoi("7", 7);
  test_htoi("0x7", 7);
  test_htoi("", 0);
  test_htoi("0x1G", -1);
  test_htoi("0x", 0);

  return 0;
}

long _strlen(char *str);
char _ishexdigit(char c);
int _charhextodecimal(char c);
long _pow(int x, int pow);

long htoi(char *s) {
  char *s0 = s;
  char *sl;
  long res = 0;

  if (*s == '0' && (*(s + 1) == 'x' || *(s + 1) == 'X')) {
    s += 2;
    s0 = s;
  }

  while (*s)
    s++;
  sl = --s;

  for (; s - s0 >= 0; s--) {
    if (!_ishexdigit(*s))
      return -1;

    res += _pow(16, sl - s) * _charhextodecimal(*s);
  }

  return res;
}

char _ishexdigit(char c) {
  return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') ||
                 (c >= 'A' && c <= 'F')
             ? 1
             : 0;
}

long _strlen(char *s) {
  long i = 0;

  while (*s != '\0' && *s++ != EOF)
    i++;

  return i;
}

int _charhextodecimal(char c) {
  if (c >= '0' && c <= '9')
    return c - '0';

  if (c >= 'a' && c <= 'f')
    return c - 'a' + 10;

  if (c >= 'A' && c <= 'F')
    return c - 'A' + 10;

  return -1;
}

long _pow(int x, int pow) {
  long res = 1;

  for (int i = 0; i < pow; i++)
    res *= x;

  return res;
}

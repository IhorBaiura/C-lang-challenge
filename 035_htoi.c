/*
 *
 * Exercise 2-3. Write the function htoi(s), which converts a string of
 * hexadecimal digits (including an optional 0x or 0X) into its equivalent
 * integer value. The allowable digits are 0 through 9, a through f, and A
 * through F.
 *
 */

#include <stdio.h>

#define IS_HEX 1

long int htoi(char[]);

int main(int argc, char *argv[]) {
  char str[] = "0x1A3F";
  char str1[] = "0X4B2E";
  char str2[] = "7C9D";

  printf("hex: %s -> %ld\n", str, htoi(str));
  printf("hex: %s -> %ld\n", str1, htoi(str1));
  printf("hex: %s -> %ld\n", str2, htoi(str2));

  return 0;
}

long _strlen(char str[]);
char _ishexdigit(char c);
int _charhextodecimal(char c);
long _pow(int x, int pow);

long htoi(char str[]) {
  int i, pos, beginnig;
  long res, len;

  beginnig = 0;
  res = 0L;
  len = _strlen(str) - 1;

  if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
    beginnig = 2;

  for (i = len; i >= beginnig; i--) {
    if (!_ishexdigit(str[i]))
      return -1;

    res += _pow(16, len - i) * _charhextodecimal(str[i]);
  }

  return res;
}

char _ishexdigit(char c) {
  if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') ||
      (c >= 'A' && c <= 'F'))
    return 1;

  return 0;
}

long _strlen(char str[]) {
  long i;

  for (i = 0; str[i] != '\0' && str[i] != EOF; i++)
    ;

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

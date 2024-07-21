/*
 *
 * Exercise 2-3. Write the function htoi(s), which converts a string of
 * hexadecimal digits (including an optional 0x or 0X) into its equivalent
 * integer value. The allowable digits are 0 through 9, a through f, and A
 * through F.
 *
 */

#include <stdio.h>
#include <string.h>

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

long htoi(char str[]) {
  int i;
  long res;

  for (i = 0; i < strlen(str); i++) {
  }

  return 1;
}

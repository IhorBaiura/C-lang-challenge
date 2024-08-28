/*
 *
 * Exercise 4-13. Write a recursive version of the function reverse(s), which
 * reverses the string s in place.
 *
 */

#include <limits.h>
#include <stdio.h>
#include <string.h>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define WHITE "\033[37m"

void reverse(char s[]);
void reverse_p(char *s);

void test_reverse(char original[], const char expected[]) {
  char input[100], res; // Buffer to store the original input for display
  strncpy(input, original, 100);
  reverse_p(input);
  res = strcmp(input, expected) == 0;
  printf("%sInput: \"%s\" | Reversed: \"%s\" | Expected: \"%s\" | %s%s\n",
         res ? GREEN : RED, original, input, expected, res ? "PASS" : "FAIL",
         WHITE);
}

int main() {
  test_reverse("", "");
  test_reverse("a", "a");
  test_reverse("ab", "ba");
  test_reverse("racecar", "racecar");
  test_reverse("hello", "olleh");
  test_reverse("hello world", "dlrow olleh");
  test_reverse("123!@#abc", "cba#@!321");
  test_reverse("abcdefghijklmnopqrstuvwxyz", "zyxwvutsrqponmlkjihgfedcba");
  test_reverse("1234567890", "0987654321");
  test_reverse("AbCdEfGh", "hGfEdCbA");

  return 0;
}

void reverse_p(char *s) {
  char c;
  char *s0 = s;

  while (*s)
    s++;

  --s;
  while (s > s0) {
    c = *s;
    *s-- = *s0;
    *s0++ = c;
  }
}

void reverse(char s[]) {
  void _reverse(char s[], int i, int len);
  _reverse(s, 0, strlen(s) - 1);
}

void _reverse(char s[], int i, int j) {
  char tmp;

  if (i < j) {
    tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
    _reverse(s, i + 1, j - 1);
  }
}

/*
 *
 * Exercise 3-3. Write a function expand(s1,s2) that expands shorthand
 * notations like a-z in the string s1 into the equivalent complete list
 * abc...xyz in s2. Allow for letters of either case and digits, and be prepared
 * to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or
 * trailing - is taken literally.
 *
 */

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

enum SYMBOL_TYPE {
  LOWER_LETTER,
  UPPER_LETTER,
  NUMBER,
  DASH_SYMBOL,
  OTHER_SYMBOL,
};

typedef enum SYMBOL_TYPE symbol_type;

void expand(const char s1[], char s2[]);

void run_test(const char *s1, const char *expected) {
  char s2[100] = {0};
  expand(s1, s2);
  printf("Input: \"%s\" -> Output: \"%s\" (Expected: \"%s\") - %s\n", s1, s2,
         expected, strcmp(s2, expected) == 0 ? "PASS" : "FAIL");
}

int main() {
  run_test("a-z", "abcdefghijklmnopqrstuvwxyz");
  run_test("0-9", "0123456789");
  run_test("A-Z", "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
  run_test("a-fA-F", "abcdefABCDEF");
  run_test("a-dx-z", "abcdxyz");
  run_test("-a-z", "-abcdefghijklmnopqrstuvwxyz");
  run_test("a-z-", "abcdefghijklmnopqrstuvwxyz-");
  run_test("a-c0-3", "abc0123");
  run_test("a-b-c", "abc");
  run_test("abc", "abc");
  run_test("z-a", "z-a");
  run_test("1-31-5", "12345");
  run_test("a", "a");
  run_test("", "");
  run_test("-a-z-", "-abcdefghijklmnopqrstuvwxyz-");

  return 0;
}

symbol_type get_symbol_type(char c) {
  if ('a' <= c || c <= 'z')
    return LOWER_LETTER;

  if ('A' <= c || c <= 'Z')
    return UPPER_LETTER;

  if ('0' <= c || c <= '9')
    return NUMBER;

  if (c == '-')
    return DASH_SYMBOL;

  return OTHER_SYMBOL;
}

void expand(const char s1[], char s2[]) {
  char range_start, range_end, in_range;
  int i, j, is_error;

  j = range_start = range_end = in_range = 0;
  is_error = 0;
  for (i = 0; s1[i] != '\0' && !is_error; i++)
    switch (get_symbol_type(s1[i])) {
    case DASH_SYMBOL:
      if (!in_range) {
        s2[j++] = s1[i];
        break;
      }

    case LOWER_LETTER:
    case UPPER_LETTER:
    case NUMBER:
      range_start = s1[i];
      break;
    case OTHER_SYMBOL:
    default:
      is_error = -1;
      break;
    }
}

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
void expand_imp(const char s1[], char s2[]);

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
  if (c == '-')
    return DASH_SYMBOL;

  if ('a' <= c && c <= 'z')
    return LOWER_LETTER;

  if ('A' <= c && c <= 'Z')
    return UPPER_LETTER;

  if ('0' <= c && c <= '9')
    return NUMBER;

  return OTHER_SYMBOL;
}

// TODO need to add error handler (is_error)
void expand(const char s1[], char s2[]) {
  char range_start, range_end;
  int i, j, is_error, dash, k;

  j = range_start = range_end = 0;
  is_error = dash = 0;
  for (i = 0; s1[i] != '\0' && !is_error; i++)
    switch (get_symbol_type(s1[i])) {
    case DASH_SYMBOL:
      if (!range_start) {
        s2[j++] = s1[i];
        break;
      }

      if (range_end && s1[i + 1] == '\0') {
        for (k = range_start; k <= range_end; k++)
          s2[j++] = k;

        s2[j++] = s1[i];
        range_start = range_end = 0;
        break;
      }

      dash = 1;
      break;
    case LOWER_LETTER:
    case UPPER_LETTER:
    case NUMBER:
      if (!range_start) {
        range_start = s1[i];
        break;
      }

      if (range_start && dash) {
        if (range_start > s1[i]) {
          s2[j++] = range_start;
          s2[j++] = '-';
          s2[j++] = s1[i];

          range_start = 0;
          break;
        }

        range_end = s1[i];
        dash = 0;
        break;
      }

      if (range_start && !dash && !range_end) {
        s2[j++] = range_start;
        s2[j++] = s1[i];
        range_start = 0;
        break;
      }

      if (range_start && range_end && !dash) {
        if (range_start != s1[i]) {
          for (k = range_start; k <= range_end; k++)
            s2[j++] = k;
          range_start = s1[i];
        }

        break;
      }

      break;
    case OTHER_SYMBOL:
    default:
      is_error = -1;
      break;
    }

  if (range_start && !range_end)
    s2[j++] = range_start;
  if (range_start && range_end)
    for (k = range_start; k <= range_end; k++)
      s2[j++] = k;

  s2[j] = '\0';
}

void expand_imp(const char s1[], char s2[]) {
  int i = 0, j = 0;
  char start, end;

  while (s1[i] != '\0') {
    if (s1[i] == '-' && i > 0 && s1[i + 1] != '\0' && s1[i - 1] < s1[i + 1]) {
      start = s1[i - 1] + 1;
      end = s1[i + 1];

      while (start <= end) {
        if (start != s1[i - 1]) {
          s2[j++] = start;
        }
        start++;
      }
      i++;
    } else {
      if (!(s1[i] == '-' && (i == 0 || s1[i + 1] == '\0'))) {
        s2[j++] = s1[i];
      } else {
        s2[j++] = '-';
      }
    }
    i++;
  }
  s2[j] = '\0';
}

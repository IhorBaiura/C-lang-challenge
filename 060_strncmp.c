#include <stdio.h>

// Function prototype for strncmp
int my_strncmp(const char *s1, const char *s2, size_t n);

void test_strncmp(const char *s1, const char *s2, size_t n, int expected) {
  int result = my_strncmp(s1, s2, n);

  if ((result == 0 && expected == 0) || (result < 0 && expected < 0) ||
      (result > 0 && expected > 0)) {
    printf("PASS: strncmp(\"%s\", \"%s\", %zu) -> %d\n", s1, s2, n, result);
  } else {
    printf("FAIL: strncmp(\"%s\", \"%s\", %zu) -> %d (Expected: %d)\n", s1, s2,
           n, result, expected);
  }
}

int main() {
  // Test cases
  test_strncmp("apple", "apricot", 2, 0);
  test_strncmp("apple", "banana", 5, -1);
  test_strncmp("orange", "oranges", 6, 0);
  test_strncmp("apple", "applesauce", 10, -1);
  test_strncmp("zebra", "zeb", 5, 1);
  test_strncmp("", "hello", 5, -1);
  test_strncmp("hello", "", 5, 1);
  test_strncmp("", "", 5, 0);
  test_strncmp("hello", "world", 0, 0);
  test_strncmp("goodbye", "goodbye", 10, 0);

  return 0;
}

int my_strncmp(const char *s, const char *t, size_t n) {
  if (n == 0)
    return 0;

  for (; *s == *t; s++, t++)
    if (*s == '\0' || --n == 0)
      return 0;

  return *s - *t;
}

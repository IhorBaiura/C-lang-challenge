#include <stdio.h>

int strend(const char *s, const char *t);

void test_strend(const char *s, const char *t, int expected) {
  int result = strend(s, t);

  if (result == expected) {
    printf("PASS: strend(\"%s\", \"%s\") -> %d\n", s, t, result);
  } else {
    printf("FAIL: strend(\"%s\", \"%s\") -> %d (Expected: %d)\n", s, t, result,
           expected);
  }
}

int main() {
  // Test cases
  test_strend("hello", "lo", 1);
  test_strend("hello", "he", 0);
  test_strend("world", "world", 1);
  test_strend("hi", "hello", 0);
  test_strend("hello", "", 1);
  test_strend("", "hello", 0);
  test_strend("", "", 1);
  test_strend("hello world", "hello", 0);
  test_strend("this is a test", "is", 0);
  test_strend("teststring", "string", 1);

  return 0;
}

int strend(const char *s, const char *t) {
  const char *s0 = s;
  const char *t0 = t;

  while (*s)
    s++;
  while (*t)
    t++;

  if (t - t0 == 0)
    return 1;

  for (; s != s0 && t != t0 && *s == *t; s--, t--)
    ;

  if (*s == *t && t == t0 && *s != '\0')
    return 1;

  return 0;
}

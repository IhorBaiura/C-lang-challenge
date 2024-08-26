#include <stdio.h>
#include <string.h>

// Function prototype for strncpy
void my_strncpy(char *s, const char *t, size_t n);

void test_strncpy(char *s, const char *t, size_t n, const char *expected) {
  char buffer[100];              // Buffer to hold the result of strncpy
  memset(buffer, 'X', n);        // Fill buffer with 'X'
  strncpy(buffer, s, strlen(s)); // Copy the initial value of s to buffer
  my_strncpy(buffer, t, n);      // Perform the copy operation

  // Compare the result with the expected output
  if (memcmp(buffer, expected, n) == 0 && buffer[n] == expected[n]) {
    printf("PASS: strncpy(\"%s\", \"%s\", %zu) -> \"%s\"\n", s, t, n, buffer);
  } else {
    printf("FAIL: strncpy(\"%s\", \"%s\", %zu) -> \"%s\" (Expected: \"%s\")\n",
           s, t, n, buffer, expected);
  }
}

int main() {
  // Test cases
  test_strncpy("XXXXXXXXXX", "hello", 3, "helXXXXXXX");
  test_strncpy("XXXXXXXXXX", "hello", 5, "helloXXXXX");
  test_strncpy("XXXXXXXXXX", "hello", 8, "hello\0\0\0XX");
  test_strncpy("XXXXXXXXXX", "hello", 0, "XXXXXXXXXX");
  test_strncpy("XXXXXXXXXX", "", 5, "\0\0\0\0\0XXXXX");
  test_strncpy("helloXXXXX", "new", 3, "newloXXXXX");
  test_strncpy("XXXXXXXXXX", "hi", 10, "hi\0\0\0\0\0\0\0\0");

  return 0;
}

void my_strncpy(char *s, const char *t, size_t n) {
  for (; *t && n > 0; n--)
    *s++ = *t++;

  while (n-- > 0) {
    *s++ = '\0';
  }
}

#include <stdio.h>
#include <string.h>

// Function prototype for strncat
void my_strncat(char *s, const char *t, size_t n);

void test_strncat(char *s, const char *t, size_t n, const char *expected) {
  char buffer[100];                  // Buffer to hold the result of strncat
  memset(buffer, 0, sizeof(buffer)); // Initialize buffer with null characters
  strncpy(buffer, s, strlen(s));     // Copy the initial value of s to buffer
  my_strncat(buffer, t, n);          // Perform the concatenation

  // Compare the result with the expected output
  if (strcmp(buffer, expected) == 0) {
    printf("PASS: strncat(\"%s\", \"%s\", %zu) -> \"%s\"\n", s, t, n, buffer);
  } else {
    printf("FAIL: strncat(\"%s\", \"%s\", %zu) -> \"%s\" (Expected: \"%s\")\n",
           s, t, n, buffer, expected);
  }
}

int main() {
  // Test cases
  test_strncat("Hello, ", "world!", 3, "Hello, wor");
  test_strncat("Hello, ", "world!", 6, "Hello, world!");
  test_strncat("Hello, ", "world!", 10, "Hello, world!");
  test_strncat("Hello, ", "world!", 0, "Hello, ");
  test_strncat("Hello, ", "", 5, "Hello, ");
  test_strncat("", "world!", 6, "world!");
  test_strncat("", "", 5, "");
  test_strncat("Test", "ing123", 3, "Testing");

  return 0;
}

void my_strncat(char *s, const char *t, size_t n) {
  while (*s)
    s++;

  for (; *t && n > 0; n--)
    *s++ = *t++;

  while (n-- > 0) {
    *s++ = '\0';
  }
}

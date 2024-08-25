#include <stdio.h>
#include <string.h>

// Function prototype for pointer version of strcat
void strcat_p(char *s, const char *t);

void test_strcat(char *s, const char *t, const char *expected) {
  char buffer[100];  // Buffer to hold the result of strcat
  strcpy(buffer, s); // Copy s into buffer to avoid modifying the original
  strcat(buffer, t); // Perform the concatenation

  if (strcmp(buffer, expected) == 0) {
    printf("PASS: \"%s\" + \"%s\" -> \"%s\"\n", s, t, buffer);
  } else {
    printf("FAIL: \"%s\" + \"%s\" -> \"%s\" (Expected: \"%s\")\n", s, t, buffer,
           expected);
  }
}

int main() {
  // Test cases
  test_strcat("Hello, ", "world!", "Hello, world!");
  test_strcat("Hello", "", "Hello");
  test_strcat("", "world!", "world!");
  test_strcat("", "", "");
  test_strcat("Hello, ", "world!\n", "Hello, world!\n");
  test_strcat("This is a long string. ", "This is another long string.",
              "This is a long string. This is another long string.");
  // For overlapping strings, the behavior is undefined, so typically these are
  // not tested.

  return 0;
}

/* strcat: concatenate t to end of s; s must be big enough */
void strcat_a(char s[], char t[]) {
  int i, j;
  i = j = 0;
  while (s[i] != '\0')
    i++;
  while ((s[i++] = t[j++]) != '\0')
    ;
}

void strcat_p(char *s, const char *t) {
  while (*s++)
    ;

  while ((*s++ = *t++))
    ;
}

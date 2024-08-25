#include "bufch.h"
#include <stdio.h>
#include <string.h>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define WHITE "\033[37m"

int getfloat(float *pn);

void test_getfloat(const char *input, float expected_value,
                   int expected_return) {
  float result;
  int return_value;

  printf("%s", WHITE);

  clear();
  ungetch(EOF);
  for (int i = strlen(input) - 1; i >= 0; i--) {
    ungetch(input[i]);
  }

  // Call getfloat
  return_value = getfloat(&result);

  // Output the result
  printf("Input: \"%s\"\n", input);
  if (return_value == expected_return && result == expected_value) {
    printf("%sPASS: Result = %.6f, Return = %d%s\n", GREEN, result,
           return_value, WHITE);
  } else {
    printf("%sFAIL: Expected Result = %.6f, Expected Return = %d\n", GREEN,
           expected_value, expected_return);
    printf("      Got Result = %.6f, Got Return = %d%s\n", result, return_value,
           WHITE);
  }
  printf("-----------------------------\n");
}

int main() {
  // Test cases
  test_getfloat("123.456", 123.456, EOF);
  test_getfloat("-456.789", -456.789, EOF);
  test_getfloat("+", 0.0, 0);
  test_getfloat("-", 0.0, 0);
  test_getfloat("123.", 123.0, EOF);
  test_getfloat(".789", 0.789, EOF);
  test_getfloat("abc", 0.0, 0);
  test_getfloat("123.456abc", 123.456, 'a');
  test_getfloat("   789.012   ", 789.012, ' ');
  test_getfloat("-0.123", -0.123, EOF);

  return 0;
}

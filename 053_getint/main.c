#include <stdio.h>

int getint(int *pn);

void test_getint(char input[], int expected_value, int expected_return) {
  int result;
  int return_value;

  return_value = getint(&result);

  printf("Input: \"%s\"\n", input);
  if (return_value == expected_return && result == expected_value) {
    printf("PASS: Result = %d, Return = %d\n", result, return_value);
  } else {
    printf("FAIL: Expected Result = %d, Expected Return = %d\n", expected_value,
           expected_return);
    printf("      Got Result = %d, Got Return = %d\n", result, return_value);
  }
  printf("-----------------------------\n");
}

int main() {
  test_getint("123", 123, ' ');
  test_getint("-456", -456, ' ');
  test_getint("+", 0, 0);
  test_getint("-", 0, 0);
  test_getint("+789", 789, ' ');
  test_getint("-321", -321, ' ');
  test_getint("-a123", 0, 0);
  test_getint("123abc456", 123, 'a');
  test_getint("   789   ", 789, ' ');
  test_getint("", 0, EOF);

  return 0;
}

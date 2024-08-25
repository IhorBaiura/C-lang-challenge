#include "bufch.h"
#include <stdio.h>
#include <string.h>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define WHITE "\033[37m"

int getint(int *pn);

void test_getint(char input[], int expected_value, int expected_return) {
  int result;
  int return_value;

  printf("%sinput: %s; expected_value: %d; expected_return: (%d; '%c')\n",
         WHITE, input, expected_value, expected_return, expected_return);

  clear();
  ungetch(EOF);
  for (int i = strlen(input) - 1; i >= 0; i--) {
    /* printf("%c; %d\n", input[i], input[i]); */
    ungetch(input[i]);
  }

  return_value = getint(&result);

  printf("Input: \"%s\"\nReturn value: (%d; '%c')\n", input, return_value,
         return_value);
  if (return_value == expected_return && result == expected_value) {
    printf("%sPASS: Result = %d, Return = %d%s\n", GREEN, result, return_value,
           WHITE);
  } else {
    printf("%sFAIL: Expected Result = %d, Expected Return = %d\n", RED,
           expected_value, expected_return);
    printf("      Got Result = %d, Got Return = %d%s\n", result, return_value,
           WHITE);
  }
  printf("-----------------------------\n");
}

int main() {
  test_getint("123", 123, EOF);
  test_getint("-456", -456, EOF);
  test_getint("+", 0, 0);
  test_getint("-", 0, 0);
  test_getint("+789", 789, EOF);
  test_getint("-321", -321, EOF);
  test_getint("-a123", 0, 0);
  test_getint("123abc456", 123, 'a');
  test_getint("   789   ", 789, ' ');
  test_getint("", 0, EOF);

  return 0;
}

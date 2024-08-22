/*
 *
 * Exercise 4-14. Define a macro swap(t,x,y) that interchanges two arguments
 * of type t. (Block structure will help.)
 *
 */

#include <stdio.h>
#include <string.h>

#define swap(t, x, y)                                                          \
  do {                                                                         \
    t tmp = x;                                                                 \
    x = y;                                                                     \
    y = tmp;                                                                   \
  } while (0)

// Test function for integers
void test_swap_int(int x, int y, int expected_x, int expected_y) {
  printf("Before swap: x = %d, y = %d\n", x, y);
  swap(int, x, y);
  printf("After swap: x = %d, y = %d\n", x, y);
  if (x == expected_x && y == expected_y) {
    printf("PASS\n");
  } else {
    printf("FAIL\n");
  }
  printf("---------------------\n");
}

// Test function for floats
void test_swap_float(float x, float y, float expected_x, float expected_y) {
  printf("Before swap: x = %.2f, y = %.2f\n", x, y);
  swap(float, x, y);
  printf("After swap: x = %.2f, y = %.2f\n", x, y);
  if (x == expected_x && y == expected_y) {
    printf("PASS\n");
  } else {
    printf("FAIL\n");
  }
  printf("---------------------\n");
}

// Test function for characters
void test_swap_char(char x, char y, char expected_x, char expected_y) {
  printf("Before swap: x = %c, y = %c\n", x, y);
  swap(char, x, y);
  printf("After swap: x = %c, y = %c\n", x, y);
  if (x == expected_x && y == expected_y) {
    printf("PASS\n");
  } else {
    printf("FAIL\n");
  }
  printf("---------------------\n");
}

// Test function for strings (pointers)
void test_swap_string(char *x, char *y, char *expected_x, char *expected_y) {
  printf("Before swap: x = %s, y = %s\n", x, y);
  swap(char *, x, y);
  printf("After swap: x = %s, y = %s\n", x, y);
  if (strcmp(x, expected_x) == 0 && strcmp(y, expected_y) == 0) {
    printf("PASS\n");
  } else {
    printf("FAIL\n");
  }
  printf("---------------------\n");
}

int main() {
  // Test 1: Swap integers
  test_swap_int(5, 10, 10, 5);

  // Test 2: Swap floats
  test_swap_float(1.23f, 4.56f, 4.56f, 1.23f);

  // Test 3: Swap characters
  test_swap_char('A', 'B', 'B', 'A');

  // Test 4: Swap strings
  char *str1 = "Hello";
  char *str2 = "World";
  test_swap_string(str1, str2, "World", "Hello");

  return 0;
}

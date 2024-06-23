/*
 * Exercise 1-6. Verify that the expression getchar() != EOF is 0 or 1.
 * Exercise 1-7. Write a program to print the value of EOF.
 */

#include <stdio.h>

int main(int argc, char *argv[]) {
  printf("int value of EOF constant is %d\n", EOF);
  printf("char value of EOF constant is %c\n", EOF);

  printf("Char isn't equal to EOF: %d\n", getchar() != EOF);
}

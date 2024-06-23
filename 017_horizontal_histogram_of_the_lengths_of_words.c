/*
 * Exercise 1-13. Write a program to print a horizontal histogram of the lengths
 * of words in its input.
 */

#include <stdio.h>

#define INSIDE 1
#define OUTSIDE 0

int main(int argc, char *argv[]) {
  int c, status;

  status = OUTSIDE;
  while ((c = getchar()) != EOF)
    if (c == ' ' || c == '\t' || c == '\n') {
      if (status == INSIDE)
        putchar('\n');
      status = OUTSIDE;
    } else {
      status = INSIDE;
      putchar('-');
    }
}

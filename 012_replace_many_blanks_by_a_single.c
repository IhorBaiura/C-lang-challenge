#include <stdio.h>

/*
 * Exercise 1-9. Write a program to copy its input to its output, replacing each
 * string of one or more blanks by a single blank.
 */

int main(int argc, char *argv[]) {
  int c, bl;

  bl = 0;
  while ((c = getchar()) != EOF) {
    if (c != ' ') {
      if (bl)
        putchar(' ');
      putchar(c);
      bl = 0;
    }

    if (c == ' ')
      ++bl;
  }
}

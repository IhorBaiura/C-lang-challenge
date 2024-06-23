/*
 * Exercise 1-10. Write a program to copy its input to its output, replacing
 * each tab by \t, each backspace by \b, and each backslash by \\. This makes
 * tab and backspaces visible in an unambiguous way.
 */

#include <stdio.h>

int main(int argc, char *argv[]) {
  int c, esc;

  while ((c = getchar()) != EOF) {
    esc = 0;

    if (c == '\t') {
      putchar('\\');
      putchar('t');
      esc = 1;
    }

    if (c == '\b') {
      putchar('\\');
      putchar('b');
      esc = 1;
    }

    if (c == '\\') {
      putchar('\\');
      putchar('\\');
      esc = 1;
    }

    if (esc == 0)
      putchar(c);
  }
}

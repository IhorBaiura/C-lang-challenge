#include <stdio.h>

/*
 * Exercise 1-8. Write a program to count blanks, tabs, and newlines.
 */

int main(int argc, char *argv[]) {
  int b, t, nl, c;

  b = t = nl = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\n')
      ++nl;

    if (c == '\t')
      ++t;

    if (c == ' ')
      ++b;
  }

  printf("Base text statistic:\nBlankes: %d\nTabs: %d\nNewlines: %d\n", b, t,
         nl);
}

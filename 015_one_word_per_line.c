/*
 * Exercise 1-12. Write a program that prints its input one word per line.
 */

#include <stdio.h>

#define INSIDE 1
#define OUTSIDE 0

int main(int argc, char *argv[]) {
  int c, word;

  word = OUTSIDE;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      if (word == INSIDE)
        putchar('\n');
      word = OUTSIDE;
    } else {
      word = INSIDE;
      putchar(c);
    }
  }
}

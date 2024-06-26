/*
 * Exercise 1-19. Write a function reverse(s) that reverses the character
 * string(s). Use it to write a program that reverses its input a line at a
 * time.
 */

#include <stdio.h>

#define MAXLINE 1000

int get_line(char s[], int lim);
void reverse(char line[]);

int main(int argc, char *argv[]) {
  char line[MAXLINE];

  while (get_line(line, MAXLINE) > 0) {
    reverse(line);
    printf("%s", line);
  }

  return 0;
}

/* get_line: read a line into s, return length */
int get_line(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    s[i] = c;

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';

  return i;
}

void reverse(char line[]) {
  int i, j, c;

  for (i = 0; line[i] != '\0' && line[i] != '\n'; i++)
    ;
  for (j = 0, --i; j <= (i / 2); j++) {
    c = line[j];
    line[j] = line[i - j];
    line[i - j] = c;
  }
}

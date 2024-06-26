/*
 * Exercise 1-18. Write a program to remove trailing blanks and tabs from each
 * line of input, and to delete entirely blank lines.
 */

#include <stdio.h>

#define MAXLINE 1000

int get_line(char s[], int lim);
int trim_line(char line[], int lim);

int main(int argc, char *argv[]) {
  char line[MAXLINE];

  while (get_line(line, MAXLINE) > 0)
    if (trim_line(line, MAXLINE) > 0)
      printf("%s", line);

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

int trim_line(char line[], int lim) {
  int i, j;

  for (j = 0; line[j] != '\0' && line[j] != '\n' && j < lim - 1 &&
              (line[j] == ' ' || line[j] == '\t');
       j++)
    ;

  for (i = 0; line[j] != '\0' && line[j] != '\n' && j < lim - 1;
       line[i] = line[j], i++, j++)
    ;

  for (--i; i >= 0 && (line[i] == ' ' || line[i] == '\t'); i--)
    ;

  if (i >= 0) {
    ++i;
    line[i] = '\n';
    ++i;
    line[i] = '\0';
  }

  return i;
}

/*
 * Exercise 1-20. Write a program detab that replaces tabs in the input with
 * the proper number of blanks to space to the next tab stop. Assume a fixed set
 * of tab stops, say every n columns. Should n be a variable or a symbolic
 * parameter?
 */

#include <stdio.h>

#define MAXLINE 1000
#define TAB 8
#define TAB_MAARK '*'

int get_line(char s[], int lim);
void detab(char s[], int lim);

int main(int argc, char *argv[]) {
  char line[MAXLINE];

  while (get_line(line, MAXLINE) > 0) {
    detab(line, MAXLINE);
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

void detab(char s[], int lim) {
  int i, j, count, space;
  char tmp[lim];

  for (count = i = 0; (s[i] != '\0' || s[i] != '\n') && count < lim - 1; i++)
    if (s[i] == '\t')
      for (space = TAB - (count % TAB); space > 0; space--)
        tmp[count++] = TAB_MAARK;
    else
      tmp[count++] = s[i];

  tmp[count] = '\0';

  for (i = 0; (s[i] = tmp[i]) != '\0'; i++)
    ;
}

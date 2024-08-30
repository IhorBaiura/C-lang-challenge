/*
 *
 * Exercise 5-7. Rewrite readlines to store lines in an array supplied by main,
 * rather than calling alloc to maintain storage. How much faster is the
 * program?
 *
 */

#include <stdio.h>
#include <string.h>

#define MAXLEN 1000     /* max length of any input line */
#define BUFFERSIZE 7000 /* max space for keeping lines */

int getline_m(char *, int);
char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], char *linebuffer, int maxlines) {
  int len, nlines;
  char *p = linebuffer;
  char *linestop = linebuffer + BUFFERSIZE;
  char line[MAXLEN];

  nlines = 0;
  while ((len = getline_m(line, MAXLEN)) > 0)
    if (nlines >= maxlines || p + len > linestop)
      return -1;
    else {
      line[len - 1] = '\0'; /* delete newline */
      strcpy(p, line);
      lineptr[nlines++] = p;
      p += len;
    }
  return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines) {
  while (nlines-- > 0)
    printf("%s\n", *lineptr++);
}

/* getline: read a line into s, return length */
int getline_m(char s[], int lim) {
  int c, i;
  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

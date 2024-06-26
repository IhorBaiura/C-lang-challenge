#include <stdio.h>

#define MAXLINE 1000

int max;
char line[MAXLINE];
char longest[MAXLINE];

int get_line(void);
void copy(void);

/* print longest input line */
int main(int argc, char *argv[]) {
  int len;
  extern int max;
  extern char longest[];

  max = 0;
  while ((len = get_line()) > 0)
    if (len > max) {
      max = len;
      copy();
    }
  if (max > 0)
    printf("%s", longest);
  return 0;
}

/* get_line: read a line into s, return length */
int get_line(void) {
  int c, i;
  extern char line[];

  for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    line[i] = c;
  if (c == '\n') {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';
  return i;
}

/* copy: copy 'from' into 'to'; assune to is big enough */
void copy(void) {
  int i;
  extern char line[], longest[];

  i = 0;
  while ((longest[i] = line[i]) != '\0')
    ++i;
}

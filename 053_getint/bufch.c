#include <stdio.h>

char buf = 0;

int getch(void) /* get a (possibly pushed back) character */
{
  if (buf) {
    buf = 0;
    return buf;
  }

  int c = getch();

  if (c == EOF) {
    buf = c;
  }

  return c;
}

void ungetch(int c) /* push character back on input */
{
  if (c != EOF) {
    return;
  }

  if (buf)
    printf("ungetch: too many characters\n");
  else {
    buf = c;
  }
}

/*
 *
 * Exercise 5-1. As written, getint treats a + or - not followed by a digit as
 * a valid representation of zero. Fix it to push such a character back on the
 * input.
 *
 */

#include <ctype.h>
#include <stdio.h>

#include "bufch.h"

/* getint: get next integer from input into *pn */
int getint(int *pn) {
  int c, sign, next;
  while (isspace(c = getch())) /* skip white space */
    ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c); /* it’s not a number */
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-') {
    next = getch();

    if (!isdigit(next)) {
      ungetch(next);
      ungetch(c);
      *pn = 0;
      return 0;
    }

    c = next;
  }
  for (*pn = 0; isdigit(c); c = getch())
    *pn = 10 * *pn + (c - '0');
  *pn *= sign;
  if (c != EOF)
    ungetch(c);
  return c;
}

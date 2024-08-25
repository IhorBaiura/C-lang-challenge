/*
 *
 * Exercise 5-2. Write getfloat, the floating-point analog of getint. What type
 * does getfloat return as its function value?
 *
 */

#include "bufch.h"
#include <ctype.h>
#include <stdio.h>

int getfloat(float *pf) {
  int c, sign, next;
  float res = 0.0;

  while (isspace(c = getch()))
    ;

  if (!isdigit(c) && c != EOF && c != '.' && c != '-' && c != '+') {
    ungetch(c);
    return 0;
  }

  sign = (c == '-') ? -1 : 1;

  if (c == '+' || c == '-') {
    next = getch();

    if (!isdigit(next)) {
      ungetch(next);
      ungetch(c);
      *pf = 0;
      return 0;
    }

    c = next;
  }

  for (*pf = 0; isdigit(c); c = getch())
    *pf = 10 * *pf + (c - '0');
  if (c == '.') {
    for (int i = 0; isdigit(c); c = getch(), i++)
      *pf = (10 * *pf + (c - '0')) / 100.0;
  }
  *pf *= sign;
  if (c != EOF)
    ungetch(c);
  return c;
}

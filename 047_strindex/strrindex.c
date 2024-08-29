#include <stdio.h>

/*
 *
 * Exercise 4-1. Write the function strrindex(s,t), which returns the position
 * of the rightmost occurrence of t in s, or -1 if there is none.
 *
 */

int strrindex(char *s, char *t) {
  char *s0 = s;
  char *t0 = t;

  while (*s)
    s++;
  --s;
  char *sl = s;

  while (*t)
    t++;
  --t;
  char *tl = t;

  while (sl > s0) {
    s = sl;
    t = tl;

    while (t >= t0 && *s == *t) {
      if (t == t0 && *s == *t) {
        return s - s0;
      }

      t--;
      s--;
    }

    sl--;
  }

  return -1;
}

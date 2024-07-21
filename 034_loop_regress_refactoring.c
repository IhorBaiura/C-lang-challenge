/*
 *
 * Exercise 2-2. Write a loop equivalent to the for loop above without using &&
 * or ||.
 *
 * Loop:
 * for (i=0; i<lim-1 && (c=getchar()) != ’\n’ && c != EOF; ++i) s[i] = c;
 *
 */
#include <stdio.h>

#define LIMIT 15

enum loop_statuses {
  CONTINUE,
  STOP,
};

int main(int argc, char *argv[]) {
  char c, s[LIMIT];
  int i;
  enum loop_statuses status;

  i = 0;
  status = CONTINUE;

  while (status != STOP) {
    if (i++ >= LIMIT - 1)
      status = STOP;
    if ((c = getchar()) == '\n')
      status = STOP;
    else if (c == EOF)
      status = STOP;
    else
      s[i] = c;
  }

  return 0;
}

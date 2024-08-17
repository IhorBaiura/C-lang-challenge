/*
 *
 * Exercise 4-7. Write a routine ungets(s) that will push back an entire string
 * onto the input. Should ungets know about buf and bufp, or should it just use
 * ungetch?
 *
 * Exercise 4-8. Suppose that there will never be more than one character of
 * pushback. Modify getch and ungetch accordingly.
 *
 * Exercise 4-9. Our getch and ungetch do not handle a pushed-back EOF
 * correctly. Decide what their properties ought to be if an EOF is pushed back,
 * then implement your design.
 *
 */

#include <stdio.h>
// #include <string.h>

char buf;     /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int getch(void) /* get a (possibly pushed back) character */
{
  if (bufp) {
    bufp = 0;
    return buf;
  }

  int c = getch();

  if (c == EOF) {
    bufp = 1;
    buf = c;
  }

  return c;
}

void ungetch(int c) /* push character back on input */
{
  if (c != EOF) {
    return;
  }

  if (bufp)
    printf("ungetch: too many characters\n");
  else {
    buf = c;
    bufp = 1;
  }
}

// This function is no longer relevant due to exercise 4-8
/* void ungets(char s[]) // push entire string back on input
{
  int len = strlen(s);
  while (len > 0)
    ungetch(s[--len]);
} */

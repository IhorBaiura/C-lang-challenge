/*
 *
 * Exercise 4-3. Given the basic framework, it’s straightforward to extend the
 * calculator. Add the modulus (%) operator and provisions for negative numbers.
 *
 */

#include <ctype.h>
#include <stdio.h>

#define NUMBER '0' /* signal that a number was found */
#define MATHOP 'M'

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[]) {
  int i, c;
  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';

  // Check if it's a function name
  if (isalpha(c)) {
    i = 0;
    while (isalpha(s[i++] = c)) // collect function name
      c = getch();
    s[i - 1] = '\0';
    // push back the last character that's not part of the function name
    ungetch(c);
    return MATHOP;
  }

  // Check if it's a number or negative sign
  if (!isdigit(c) && c != '.' && c != '-') {
    return c; // not a number or function, return it
  }

  i = 0;
  if (c == '-') { // collect negative sign
    if (isdigit(c = getch()) || c == '.') {
      s[++i] = c; // it's a negative number
    } else {
      if (c != EOF)
        ungetch(c); // it's not a number, push back the character
      return '-';   // return the minus operator
    }
  }

  if (isdigit(c)) /* collect integer part */
    while (isdigit(s[++i] = c = getch()))
      ;

  if (c == '.') /* collect fraction part */
    while (isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  if (c != EOF)
    ungetch(c);
  return NUMBER;
}

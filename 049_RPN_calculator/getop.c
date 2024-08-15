/*
 *
 * Exercise 4-3. Given the basic framework, it’s straightforward to extend the
 * calculator. Add the modulus (%) operator and provisions for negative numbers.
 *
 */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define NUMBER '0' /* signal that a number was found */
#define MATHOP 'M'
#define VAR 'V'
#define ASSIGN 'A'
#define RESULT 'R'
#define CLEAR 'C'

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[]) {
  int i, c, t;
  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';

  // Check if it's a command to print the most recent value (e.g., "R")
  if (c == 'R') {
    return RESULT; // Return 'R' as the command to print the last value
  }

  // Check if it's a command to clear stack
  if (c == 'C') {
    return CLEAR; // Return 'C' as the command to clear stack
  }

  // Check if it's a function name
  if (isalpha(c)) {
    i = 0;
    while (isalpha(s[i++] = c)) // collect function name
      c = getch();
    s[i - 1] = '\0';
    // push back the last character that's not part of the function name
    ungetch(c);

    // Check if it's a single-letter variable
    if (strlen(s) == 1 && s[0] >= 'a' && s[0] <= 'z') {
      c = getch();
      t = getch();
      if (c == ' ' && t == '=') { // Handle assignment (e.g., a =)
        s[1] = c;
        s[2] = '\0';
        return ASSIGN;
      } else {
        ungetch(c); // Not an assignment, push the character back
        ungetch(t); // Not an assignment, push the character back
        return VAR;
      }
    }

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

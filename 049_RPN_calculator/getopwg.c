/*
 *
 * Exercise 4-11. Modify getop so that it doesn’t need to use ungetch. Hint:
 * use an internal static variable.
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
#define NEWLINE 'N'

/* getop: get next operator or numeric operand */
int getop(char s[]) {
  int i, tmp;
  static char c = ' ';

  // Handle EOF
  if (c == EOF) {
    return EOF;
  }

  // Skip whitespace or tabs
  while (c == ' ' || c == '\t') {
    c = getchar();
    if (c == EOF) {
      return EOF;
    }
  }

  s[0] = c;
  s[1] = '\0';

  if (!isdigit(c) && c != '.' && c != '-') {
    if (isalpha(c)) {
      i = 0;
      while (isalpha(s[i++] = c)) {
        c = getchar();
      } // collect function name
      s[i - 1] = '\0';

      // Check if it's a single-letter variable
      if (strlen(s) == 1) {
        if (s[0] >= 'a' && s[0] <= 'z') {

          if (c == ' ') {
            c = getchar();

            if (c == '=') { // Handle assignment (e.g., a =)
              s[1] = c;
              s[2] = '\0';
              c = getchar();
              return ASSIGN;
            }

            return VAR;
          }

          return VAR;
        }

        if (s[0] >= 'A' && s[0] <= 'Z') {
          return s[0];
        }
      }

      return MATHOP;
    }

    tmp = c;
    c = ' ';
    return tmp;
  }

  i = 0;
  if (c == '-') {
    c = getchar();

    if (c == EOF) {
      return '-';
    }

    if (!isdigit(c) && c != '.') {
      return '-'; // It is a minus sign, not a negative number
    }

    s[++i] = c; // It is a negative number
  }

  if (isdigit(s[i])) {
    while (isdigit(c = getchar())) {
      s[++i] = c;
    }
  }
  if (c == '.') {
    s[++i] = c;
    while (isdigit(c = getchar())) {
      s[++i] = c; // Collect the digits after the decimal point
    }
  }
  s[++i] = '\0';
  return NUMBER;
}

/*
 *
 * Exercise 4-10. An alternate organization uses getline to read an entire input
 * line; this makes getch and ungetch unnecessary. Revise the calculator to use
 * this approach.
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

#define LIMIT 100

int _getline(char s[], int limit);

int li = 0; // line index
char line[LIMIT];

/* getop: get next operator or numeric operand */
int getop(char s[]) {
  int i, c, t;

  if (line[li] == '\0') {
    if (_getline(line, LIMIT) == 0)
      return EOF;
    else
      li = 0;
  }

  while ((s[0] = c = line[li++]) == ' ' || c == '\t')
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
      c = line[li++];
    s[i - 1] = '\0';
    // push back the last character that's not part of the function name
    --li;

    // Check if it's a single-letter variable
    if (strlen(s) == 1 && s[0] >= 'a' && s[0] <= 'z') {
      c = line[li++];

      if (c == ' ') {
        c = line[li++];
        if (c == '=') { // Handle assignment (e.g., a =)
          s[1] = c;
          s[2] = '\0';
          return ASSIGN;
        }
        --li;
        return VAR;
      }

      --li;
      return VAR;
    }

    return MATHOP;
  }

  // Check if it's a number or negative sign
  if (!isdigit(c) && c != '.' && c != '-') {
    return c; // not a number or function, return it
  }

  i = 0;
  if (c == '-') { // collect negative sign
    if (isdigit(c = line[li++]) || c == '.') {
      s[++i] = c; // it's a negative number
    } else {
      if (c != EOF)
        --li;     // it's not a number, push back the character
      return '-'; // return the minus operator
    }
  }

  if (isdigit(c)) /* collect integer part */
    while (isdigit(s[++i] = c = line[li++]))
      ;

  if (c == '.') /* collect fraction part */
    while (isdigit(s[++i] = c = line[li++]))
      ;
  s[i] = '\0';
  if (c != EOF)
    --li;
  return NUMBER;
}

int _getline(char s[], int lim) {
  int i;
  char c;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
    s[i] = c;
  }

  if (c == '\n') {
    s[i++] = c;
  }
  s[i] = '\0';

  return i;
}

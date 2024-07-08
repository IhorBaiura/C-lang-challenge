/*
 *
 * Exercise 1-24. Write a program to check a C program for rudimentary
 * syntax errors like unbalanced parentheses, brackets and braces. Don’t forget
 * about quotes, both single and double, escape sequences, and comments. (This
 * program is hard if you do it in full generality.)
 *
 */

#include <stdio.h>

#define LEFT_PARENTHESE '('
#define RIGHT_PARENTHESE ')'
#define LEFT_BRACKET '['
#define RIGHT_BRACKET ']'
#define LEFT_BRACE '{'
#define RIGHT_BRACE '}'
#define SINGLE_QUOTE '\''
#define DOUBLE_QUOTE '"'
#define FORWARD_SLASH '/'

void check_syntax_error(char s[]);

int main(int argc, char *argv[]) { return 0; }

void check_syntax_error(char s[]) {
  int i, j, pos, line;

  for (i = 0; s[i] != '\0'; i++)
    ;

  char stack[i];

  j = pos = line = 0;
  for (i = 0; s[i] != '\0'; i++, pos++) {
    if (s[i] == '\n') {
      pos = 0;
      line++;
    }

    if (s[i] == LEFT_PARENTHESE || s[i] == LEFT_BRACE || s[i] == LEFT_BRACKET)
      stack[j++] = s[i];

    if (s[i] == RIGHT_PARENTHESE || s[i] == RIGHT_BRACE ||
        s[i] == RIGHT_BRACKET)
      if (j - 1 < 0)
        printf("Unbalanced parentheses, brackets or braces. Missing opening "
               "part for position %d:%d",
               line, pos);
      else if (stack[j - 1] != s[i])
        printf("Unbalanced parentheses, brackets or braces. Missing opening "
               "part for position %d:%d",
               line, pos);
  }
}

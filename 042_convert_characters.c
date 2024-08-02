/*
 *
 * Exercise 3-2. Write a function escape(s,t) that converts characters like
 * newline and tab into visible escape sequences like \n and \t as it copies the
 * string t to s. Use a switch. Write a function for the other direction as
 * well, converting escape sequences into the real characters.
 *
 */

#include <stdio.h>

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main(int argc, char *argv[]) {
  char t[] = "This is a test string.\nWith a new line.\tAnd a tab.";
  char s[100];
  char u[100];

  escape(s, t);
  printf("Escaped: %s\n", s);

  unescape(u, s);
  printf("Unescaped: %s\n", u);

  return 0;
}

void escape(char s[], char t[]) {
  int i, j;

  j = 0;
  for (i = 0; t[i] != '\0'; i++)
    switch (t[i]) {
    case '\t':
      s[j++] = '\\';
      s[j++] = 't';
      break;
    case '\n':
      s[j++] = '\\';
      s[j++] = 'n';
      break;
    default:
      s[j++] = t[i];
      break;
    }

  s[j] = '\0';
}

void unescape(char s[], char t[]) {
  int i, j;

  j = 0;
  for (i = 0; t[i] != '\0'; i++) {
    if (t[i] == '\\') {
      switch (t[++i]) {
      case 't':
        s[j++] = '\t';
        break;
      case 'n':
        s[j++] = '\n';
        break;
      default:
        s[j++] = '\\';
        s[j++] = t[i];
        break;
      }
    } else {
      s[j++] = t[i];
    }
  }

  s[j] = '\0';
}

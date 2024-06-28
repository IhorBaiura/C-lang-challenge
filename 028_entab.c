/*
 * Exercise 1-21. Write a program entab that replaces strings of blanks by the
 * minimum number of tabs and blanks to achieve the same spacing. Use the same
 * tab stops as for detab. When either a tab or a single blank would suffic to
 * reach a tab stop, which should be given preference?
 *
 * Example:
 * Input string:  "apple banana pear"
 * Output string: "\tapple\tbanana\t\t\tpear"
 */

#include <stdio.h>

#define MAXLINE 1000
#define TAB 8

int get_line(char s[], int lim);
void entab(char s[], int lim);

int main(int argc, char *argv[]) {
  char line[MAXLINE];

  while (get_line(line, MAXLINE) > 0) {
    entab(line, MAXLINE);
    printf("%s", line);
  }

  return 0;
}

/* get_line: read a line into s, return length */
int get_line(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    s[i] = c;

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';

  return i;
}

void entab(char s[], int lim) {
  char tmp[lim];
  int i, j, spaces;

  for (i = 0, j = 0; (s[i] != '\n' || s[i] != '\0') && i < lim - 1; i++) {
    if (s[i] == ' ') {
      spaces++;
      if ((i + 1) % TAB == 0) {
        tmp[j++] = '\t';
        spaces = 0;
      }
    } else {
      for (; spaces > 0; spaces--)
        tmp[j++] = ' ';
      tmp[j++] = s[i];
    }
  }

  printf("i = %d; j = %d\n", i, j);

  tmp[j] = '\0';
  for (i = 0; i < j; s[i] = tmp[i], i++)
    ;
}

void print_esc(char c) {
  if (c == '\t') {
    putchar('\\');
    putchar('t');
  } else if (c == '\b') {
    putchar('\\');
    putchar('b');
  } else if (c == '\\') {
    putchar('\\');
    putchar('\\');
  }
}

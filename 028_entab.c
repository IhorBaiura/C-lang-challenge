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
void print_esc(char c);

int main(int argc, char *argv[]) {
  char line[MAXLINE];

  while (get_line(line, MAXLINE) > 0) {
    entab(line, MAXLINE);
    // printf("%s", line);
  }

  return 0;
}

/* get_line: read a line into s, return length */
int get_line(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    s[i] = c;

  if (c == '\n')
    s[i++] = c;

  s[i] = '\0';

  return i;
}

void entab(char s[], int lim) {
  char tmp[lim];
  int i, j, spaces;

  //
  // a__________________a
  // |a_______|________|___a
  // a\t\t___a
  //

  for (i = j = spaces = 0; s[i] != '\0' && s[i] != '\n' && i < lim - 1; i++) {
    if (s[i] == ' ') {
      spaces++;
      if ((i + 1) % TAB == 0) {
        tmp[j++] = '\t';
        spaces = 0;
      }
    } else {
      while (spaces > 0) {
        tmp[j++] = ' ';
        spaces--;
      }
      tmp[j++] = s[i];
    }
  }

  if (s[i] == '\n')
    tmp[j++] = s[i];

  tmp[j] = '\0';

  //
  // for (i = 0; i <= j; s[i] = tmp[i], i++)
  //   print_esc(s[i]);
  //
  //

  for (i = 0; tmp[i] != '\0'; i++)
    print_esc(tmp[i]);
}

void print_esc(char c) {
  if (c == '\t') {
    putchar('\\');
    putchar('t');
  } else if (c == '\b') {
    putchar('\\');
    putchar('b');
  } else if (c == '\n') {
    putchar('\\');
    putchar('n');
  } else if (c == '\\') {
    putchar('\\');
    putchar('\\');
  } else if (c == ' ') {
    putchar('_');
  } else {
    putchar(c);
  }
}

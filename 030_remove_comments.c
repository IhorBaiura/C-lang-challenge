/*
 * Exercise 1-23. Write a program to remove all comments from a C program. Don’t
 * forget to handle quoted strings and character constants properly. C comments
 * do not nest.
 *
 */

#include <stdio.h>

#define LINE_LENGTH 1000
#define LINECOMMENT 1
#define MULTILINECOMMENT 2
#define MULTILINECOMMENTEND 3
#define START 0
#define OUTSIDE -1

int get_line(char s[], int lim);
void remove_comments(char s[]);

int main(int argc, char *argv[]) {
  int length;
  char line[LINE_LENGTH];

  while ((length = get_line(line, LINE_LENGTH)) > 0) {
    remove_comments(line);
    printf("%s", line);
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

void remove_comments(char s[]) {
  int i, j, comment, comment_start;
  char prev_char;

  comment = OUTSIDE;
  prev_char = 'a';
  j = 0;
  comment_start = OUTSIDE;
  for (i = 0; s[i] != '\0'; i++) {
    s[j++] = s[i];

    if (s[i] == '/') {
      if (comment == OUTSIDE)
        comment = START;

      else if (comment == START) {
        comment = LINECOMMENT;
        comment_start = j - 2;
      }

      else if (comment == MULTILINECOMMENTEND) {
        j = comment_start;
        comment = OUTSIDE;
      }
    } else if (s[i] == '*') {
      if (comment == START) {
        comment = MULTILINECOMMENT;
        comment_start = j - 2;
      }

      else if (comment == MULTILINECOMMENT)
        comment = MULTILINECOMMENTEND;
    } else {
      if (comment == MULTILINECOMMENTEND)
        comment = MULTILINECOMMENT;

      else if (comment == START)
        comment = OUTSIDE;
    }

    if (s[i] == '\n' || s[i] == '\0') {
      if (comment == LINECOMMENT) {
        j = comment_start;
        comment = OUTSIDE;
      }
    }
  }

  s[j] = '\0';
}

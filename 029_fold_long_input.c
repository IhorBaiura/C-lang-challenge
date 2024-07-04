/*
 * Exercise 1-22. Write a program to “fold” long input lines into two or more
 * shorter lines after the last non-blank character that occurs before the n-th
 * column of input. Make sure your program does something intelligent with very
 * long lines, and if there are no blanks or tabs before the specified column.
 *
 * Input line:
 * Make sure your program does something intelligent with very long lines
 *
 * Output line "ROW_LENGTH 20":
 * Make sure your
 * program does
 * something
 * intelligent with
 * very long lines
 */

#include <stdio.h>

#define LINE_LENGTH 1000
#define ROW 10
#define TAB 8

int get_line(char s[], int lim);
void fold(char s[], int lim);

int main(int argc, char *argv[]) {
  int length;
  char line[LINE_LENGTH];

  while ((length = get_line(line, LINE_LENGTH)) > 0) {
    fold(line, LINE_LENGTH);
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

void fold(char s[], int lim) {
  int i, j, pos, blank_pos, has_word, inside_word, line_start;
  char acc[lim];

  /*
   *    ROW 10
   *
   *  1   aasd_sdf_afd___\t__adslkfj___ajlfa_fa_\t___kalfj
   *      aasd sdf afd      adslkfj   ajlfa fa     kalfj
   *
   *  1   aasd_sdf\n
   *  2   afd\n
   *  3   adslkfj\n
   *  4   ajlfa_fa\n
   *  5   kalfj\0
   */

  j = has_word = inside_word = line_start = 0;
  pos = 1;
  blank_pos = -1;
  for (i = 0; s[i] != '\0' && s[i] != '\n' && i < lim - 1; i++) {
    acc[j++] = s[i];

    if (s[i] == ' ' || s[i] == '\t') {
      if (blank_pos < 0 || (blank_pos >= 0 && inside_word == 1)) {
        blank_pos = j - 1;
        inside_word = 0;
      }
    }

    if (s[i] == '\t')
      pos += TAB - (pos % TAB);
    else if (s[i] == ' ')
      pos++;
    else {
      if (blank_pos >= 0 && has_word == 0) {
        j = blank_pos;
        blank_pos = -1;
        pos = 0;
      }

      pos++;
      inside_word = 1;
      has_word = 1;
    }

    if (pos >= ROW) {
      if (blank_pos >= 0)
        j = blank_pos;

      if (inside_word == 1) {
        // TODO need to shift i backward
        // i = word_start;
      }

      if (has_word == 0)
        j = line_start;
      else
        acc[j++] = '\n';

      blank_pos = -1;
      pos = 1;
      has_word = 0;
      inside_word = 0;
      line_start = j;
    }
  }

  acc[j] = '\0';

  printf("\noutput:\n%s\n-------\n", acc);

  for (i = 0; i < lim - 1 && acc[i] != '\0'; i++)
    s[i] = acc[i];
}

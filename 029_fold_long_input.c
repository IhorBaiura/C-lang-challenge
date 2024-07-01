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
#define ROW 80
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
  int i, j, pos, word_size, blank_pos;
  char acc[lim];

  /*
   *    ROW 10
   *
   *  1   aasd_sdf_afd___\t__adslkfj___ajlfa_fa_\t___kalfj
   *
   *  1   aasd_sdf\n
   *  2   afd\n
   *  3   adslkfj\n
   *  4   ajlfa_fa\n
   *  5   kalfj\0
   */

  word_size = j = 0;
  pos = 1;
  blank_pos = -1;
  for (i = 0; s[i] != '\0' && s[i] != '\n' && i < lim - 1; i++) {
    acc[j] = s[i];

    if ((s[i] == ' ' || s[i] == '\t') && blank_pos < 0)
      blank_pos = j;

    if (s[i] == '\t')
      pos += TAB - (pos % TAB);

    if (s[i] == ' ')
      pos++;

    if (pos >= ROW)
      ;

    // if (s[i] == '\t') {
    //   int shift = 0;
    //   shift = TAB - (pos % TAB);
    //   spaces += shift;
    //   pos += shift;
    // } else if (s[i] == ' ') {
    //   spaces++;
    // } else {
    //   if (pos >= ROW_LENGTH) {
    //     acc[j++] = '\n';
    //     pos = 0;
    //     spaces = 0;
    //   }
    //
    //   for (; spaces > 0; spaces--)
    //     acc[j++] = ' ';
    //
    //   acc[j++] = s[i];
    //   pos++;
    // }

    // pos++;
    // if(pos >= ROW_LENGTH) {
    //   tmp[j++] = '\n';
    //   pos = 1;
    // }
    // tmp[j++] = s[i];
  }

  // tmp[j] = '\0';
  //
  // for (i = 0; i < lim - 1 && tmp[i] != '\0'; i++)
  //   s[i] = tmp[i];
}

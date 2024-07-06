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
  int i, j, pos, blank_pos, has_word, word_start_pos, line_start;
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
   *
   *
   *
   *    ROW 10
   *
   *  1   asdf as dfsa             asd fas                 dsfas fd         a sd
   * fsdfa                 asfadf adf a
   *
   *  1   asdf as
   *  2   dfsa
   *  3   asd fas
   *  4   dsfas fd
   *  5   a     sd
   *  6   fsdfa
   *  7   asfadf
   *  8   adf a
   */

  j = has_word = line_start = 0;
  pos = 1;
  blank_pos = word_start_pos = -1;
  for (i = 0; s[i] != '\0' && s[i] != '\n' && i < lim - 1; i++) {
    acc[j++] = s[i];
    // printf("s[i]: %c, i: %d, j: %d, line_start: %d\n", s[i], i, j - 1,
    //        line_start);

    if (s[i] == ' ' || s[i] == '\t') {
      if (blank_pos < 0 || (blank_pos >= 0 && word_start_pos > 0)) {
        blank_pos = j - 1;
        word_start_pos = -1;
        // printf("\t__%d__\n", j - 1);
      }
    }

    if (s[i] == '\t')
      pos += TAB - (pos % TAB);
    else if (s[i] == ' ')
      pos++;
    else {
      // printf("\t\t\tdetected character: blank_pos: %d, has_word: %d, i:
      // %d\n",
      //        blank_pos, has_word, i);
      if (blank_pos >= 0 && has_word == 0) {
        j = blank_pos;
        blank_pos = -1;
        pos = 0;
        acc[j++] = s[i];
      }

      if (word_start_pos < 0) {
        word_start_pos = i;
      }

      pos++;
      has_word = 1;
    }

    if (pos >= ROW) {
      if (blank_pos >= 0)
        j = blank_pos;

      if (word_start_pos > 0) {
        i = word_start_pos - 1;
        // printf("\n\t\t\tword_start_pos: %d\n", word_start_pos);
      }

      if (has_word == 0)
        j = line_start;
      else
        acc[j++] = '\n';

      blank_pos = -1;
      pos = 1;
      has_word = 0;
      word_start_pos = -1;
      line_start = j;

      // printf("\n\t\t\tprint:  s[i]: %c   j: %d   i: %d   line_start: %d\n\n",
      //        s[i], j, i, line_start);
    }
  }

  acc[j] = '\0';

  // printf("\noutput:\n%s\n-------\n", acc);

  for (i = 0; i <= j; i++)
    s[i] = acc[i];
}

/*
 * Exercise 1-13. Write a program to print a vertical histogram of the lengths
 * of words in its input.
 *
 * Input:
 *    aaaa aaaaa aaaaaaa aaaaa aaaaaaaa aaaaa aaaa aa a
 *
 * Result:
 *
 *                -
 *          -     -
 *          -     -
 *       -  -  -  -  -
 *    -  -  -  -  -  -  -
 *    -  -  -  -  -  -  -
 *    -  -  -  -  -  -  -  -
 *    -  -  -  -  -  -  -  -  -
 *    1  2  3  4  5  6  7  8  9
 *
 */

#include <stdio.h>

#define INSIDE 1
#define OUTSIDE 0
#define LINE_LENGTH 50

void renderVerticalHistogram(int line_item_sizes[], int wNumber);
int getMaxValueOfArrayInRange(int array[], int range);

int main(int argc, char *argv[]) {
  int c, status, word_count, word_size;
  int line_item_sizes[LINE_LENGTH];

  status = OUTSIDE;
  word_size = word_count = 0;
  while ((c = getchar()) != EOF)
    if (c == ' ' || c == '\t' || c == '\n') {
      if (status == INSIDE) {
        if (word_count > LINE_LENGTH) {
          renderVerticalHistogram(line_item_sizes, word_count);
          word_count = 0;
        }
        line_item_sizes[word_count] = word_size;
        word_size = 0;
        status = OUTSIDE;
        ++word_count;
      }
    } else {
      status = INSIDE;
      ++word_size;
    }

  renderVerticalHistogram(line_item_sizes, word_count);
}

void renderVerticalHistogram(int line_item_sizes[], int range) {
  putchar('\n');

  int max = getMaxValueOfArrayInRange(line_item_sizes, range);
  for (; max > 0; max--) {
    for (int i = 0; i < range; i++) {
      if (max == line_item_sizes[i]) {
        line_item_sizes[i] = line_item_sizes[i] - 1;
        putchar(' ');
        putchar('-');
        putchar(' ');
      } else {
        putchar(' ');
        putchar(' ');
        putchar(' ');
      }
    }

    putchar('\n');
  }

  for (int i = 1; i <= range; i++) {
    printf(" %d ", i);
  }

  putchar('\n');
}

int getMaxValueOfArrayInRange(int array[], int range) {
  int max, i;

  max = 0;
  for (i = 0; i < range; i++) {
    if (max < array[i])
      max = array[i];
  }

  return max;
}

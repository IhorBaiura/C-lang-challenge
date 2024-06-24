/*
 * Exercise 1-14. Write a program to print a histogram of the frequencies of
 * differen characters in its input.
 *
 * expectation:
 *
 *  > if (i == '\n' || i == '\t' || i == ' ')
 *
 *          -
 *          -
 *          -
 *          -
 *          -
 *          -
 *          -  -        -
 *          -  -        -
 *          -  -        -        -        -
 *          -  -        -        -        -
 *          -  -        -  -     -        -
 *      -   -  -  -  -  -  -  -  -  -  -  -
 *     \n  \_  '  (  )  =  \  f  i  n  t  |
 *
 */

#include <stdio.h>

#define CHARACTERS_COUNT 128
#define SHIFT 10

int getMaxValueOfArrayInRange(int array[], int range);

int main(int argc, char *argv[]) {
  int c, max;
  int charactersFrequencies[CHARACTERS_COUNT] = {0};

  while ((c = getchar()) != EOF) {
    if (charactersFrequencies[c] == 0)
      charactersFrequencies[c] = SHIFT;
    charactersFrequencies[c] = charactersFrequencies[c] + 1;
  }

  max = getMaxValueOfArrayInRange(charactersFrequencies, CHARACTERS_COUNT) -
        SHIFT;

  for (; max >= 0; max--) {
    if (max > 0)
      for (int i = 0; i < CHARACTERS_COUNT; i++) {
        if (charactersFrequencies[i] == 0)
          continue;

        if (max == (charactersFrequencies[i] - SHIFT)) {
          charactersFrequencies[i] = charactersFrequencies[i] - 1;
          if (i == '\n' || i == '\t' || i == ' ')
            printf("  - ");
          else
            printf(" - ");
        } else {
          if (i == '\n' || i == '\t' || i == ' ')
            printf("    ");
          else
            printf("   ");
        }
      }

    if (max == 0) {
      for (int i = 0; i < CHARACTERS_COUNT; i++) {
        if (charactersFrequencies[i] == SHIFT) {
          if (i == '\n') {
            printf(" \\n ");
            continue;
          }
          if (i == '\t')
            printf(" \\t ");
          if (i == ' ')
            printf(" \\_ ");
          else
            printf(" %c ", i);
        }
      }
    }

    putchar('\n');
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

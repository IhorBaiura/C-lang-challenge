/*
 *
 *   Exercise 5-10. Write the program expr, which evaluates a reverse Polish
 * expression from the command line, where each operator or operand is a
 * separate argument. For example,
 *
 *      expr 2 3 4 + *
 *
 * evaluates 2 × (3+4).
 *
 */
#include "commands.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  Stack *st = create();

  while (--argc) {
    if (isdigit(**++argv))
      push(st, atoi(*argv));
    else
      apply_command(st, *argv);
  }

  result(st);

  return 0;
}

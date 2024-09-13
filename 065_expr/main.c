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
#include "stack.h"

int main(int argc, char *argv[]) {
  Stack *stack = create();

  while (--argc)
    switch ((*++argv)[]) {
      case isNum()
    }

  return 0;
}

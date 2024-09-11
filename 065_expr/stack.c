#include "stack.h"
#include <stdlib.h>

Stack *create() {
  Stack *stack = malloc(sizeof(Stack));
  stack->stack = malloc(STEP * sizeof(Data));
  stack->n = 0;
  stack->size = STEP;

  return stack;
}

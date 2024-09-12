#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack *create() {
  Stack *stack = malloc(sizeof(Stack));
  stack->a = NULL;
  stack->n = 0;
  stack->size = 0;

  return stack;
}

Data pop(Stack *st) {
  if (is_empty(st)) {
    printf("Stack is empty");
    return 0;
  }

  return st->a[st->n-- - 1];
}

void push(Stack *st, Data d) {
  if (is_full(st)) {
    st->size += STEP;
    st->a = realloc(st->a, st->size * sizeof(Data));
  }

  st->a[st->n++] = d;
}

bool is_empty(Stack *st) { return st->n; }

bool is_full(Stack *st) { return st->n >= st->size; }

void destroy(Stack *st) {
  free(st->a);
  free(st);
}

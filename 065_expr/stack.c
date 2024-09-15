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

void print(Stack *st) {
  printf("Stack: ");
  for (unsigned int i = 0; i < st->n; i++)
    printf("%d ", st->a[i]);
  printf("\n");
}

Data pop(Stack *st) {
  if (is_empty(st)) {
    printf("Stack is empty\n");
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
  print(st);
}

bool is_empty(Stack *st) { return st->n == 0; }

bool is_full(Stack *st) { return st->n >= st->size; }

void destroy(Stack *st) {
  free(st->a);
  free(st);
}

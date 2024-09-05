#include "stack_dynamic.h"
#include <stdio.h>
#include <stdlib.h>

Stack *create() {
  Stack *st = malloc(sizeof(Stack));
  init(st);
  return st;
}

void print(Stack *st) {
  printf("Stack: ");
  for (unsigned int i = 0; i < st->n; i++)
    printf("%d ", st->a[i]);
  printf("\n");
}

void init(Stack *st) {
  st->n = 0;
  st->a = NULL;
  st->size = 0;
}

void push(Stack *st, Data d) {
  if (is_full(st)) {
    st->size += STEP;
    st->a = realloc(st->a, st->size * sizeof(st->a[0]));
  }

  st->a[st->n++] = d;
}

Data pop(Stack *st) {
  if (is_empty(st)) {
    printf("Stack is empty");
    return 0;
  }

  return st->a[st->n-- - 1];
}

int is_empty(Stack *st) { return st->n == 0; }

int is_full(Stack *st) { return st->n >= st->size; }

void destroy(Stack *st) {
  free(st->a);
  init(st);
}

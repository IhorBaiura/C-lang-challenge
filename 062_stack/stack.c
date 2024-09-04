#include "stack.h"
#include <stdio.h>

void print(Stack *st) {
  printf("Stack: ");
  for (unsigned int i = 0; i < st->n; i++)
    printf("%d ", st->a[i]);
  printf("\n");
}

void init(Stack *st) { st->n = 0; }

void push(Stack *st, Data d) {
  if (is_full(st)) {
    printf("Stack owerflow");
    return;
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

int is_full(Stack *st) { return st->n >= sizeof(st->a) / sizeof(st->a[0]); }

#include "stack.h"
#include <stdio.h>

void print(Stack *st) {
  for (unsigned int i = 0; i < st->n; i++)
    printf("%d ", st->a[i]);
  printf("\n");
}

void init(Stack *st) { st->n = 0; }

void push(Stack *st, Data d) { st->a[st->n++] = d; }

Data pop(Stack *st) { return st->a[st->n-- - 1]; }

int is_empty(Stack *st) { return st->n == 0; }

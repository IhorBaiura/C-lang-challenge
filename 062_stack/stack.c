#include "stack.h"
#include <stdio.h>

void print(Stack *st) {
  for (unsigned int i = 0; i < st->n; i++)
    printf("%d ", st->a[i]);
  printf("\n");
}

void init(Stack *st) { st->n = 0; }

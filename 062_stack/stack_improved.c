#include "stack_improved.h"
#include <stdio.h>
#include <stdlib.h>

Stack *create() {
  Stack *st = malloc(sizeof(Stack) + sizeof(Data) * STEP);
  st->size = STEP;
  st->n = 0;
  return st;
}

void print(Stack *st) {
  printf("Stack: ");
  for (unsigned int i = 0; i < st->n; i++)
    printf("%d ", st->a[i]);
  printf("\n");
}

void push(Stack **pst, Data d) {

  if (is_full(*pst)) {
    ((Stack *)*pst)->size += STEP;
    *pst = realloc(*pst, sizeof(Stack) + ((Stack *)*pst)->size * sizeof(Data));
  }

  Stack *st = *pst;
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

void destroy(Stack *st) { free(st); }

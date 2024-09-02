#include "stack.h"
#include <stdio.h>

void print(Stack *sp) {
  for (unsigned int i = 0; i < sp->n; i++)
    printf("%d ", sp->a[i]);
  printf("\n");
}

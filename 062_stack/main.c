#include "stack.h"
#include <stdio.h>

int main() {
  Stack s;
  Stack *st = &s;

  init(st);
  print(st);

  push(st, -5);
  print(st);

  push(st, 1);
  print(st);

  push(st, 15);
  print(st);

  push(st, 22);
  print(st);

  push(st, 110);
  print(st);

  Data d;
  d = pop(st);
  printf("pop data: %d\n", d); // 110
  print(st);                   // -5 1 15 22

  d = pop(st);
  printf("pop data: %d\n", d); // 22
  print(st);                   // -5 1 15

  d = pop(st);
  printf("pop data: %d\n", d); // 15
  print(st);                   // -5 1

  d = pop(st);
  printf("pop data: %d\n", d); // 1
  print(st);                   // -5

  d = pop(st);
  printf("pop data: %d\n", d); // -5
  print(st);                   //

  return 0;
}

#include "stack.h"
#include <stdio.h>

int main() {
  Stack s;
  Stack *st = &s;

  init(st);
  print(st);
  printf("Stack is empty: %s\n", is_empty(st) ? "Yes" : "No"); // Yes

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

  printf("Stack is empty: %s\n", is_empty(st) ? "Yes" : "No"); // No

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

  printf("Stack is empty: %s\n", is_empty(st) ? "Yes" : "No"); // Yes

  printf("Stack is full: %s\n", is_full(st) ? "Yes" : "No"); // No
  push(st, 110);
  push(st, 110);
  push(st, 110);
  push(st, 110);
  push(st, 110);
  push(st, 110);
  push(st, 110);
  push(st, 110);
  print(st);
  printf("Stack is empty: %s\n", is_empty(st) ? "Yes" : "No"); // No
  printf("Stack is full: %s\n", is_full(st) ? "Yes" : "No");   // Yes

  return 0;
}

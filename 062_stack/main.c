#include "stack.h"
#include <stdio.h>

int main() {
  Data td[DEPTH] = {-5, 1, 15, 22, 110};
  Stack s;
  Stack *st = &s;

  init(st);
  print(st);
  printf("Stack is empty: %s\n", is_empty(st) ? "Yes" : "No"); // Yes
  printf("Stack is full: %s\n", is_full(st) ? "Yes" : "No");   // No

  for (int i = 0; i < DEPTH; i++) {
    printf("Push to stack: %d\n", td[i]);
    push(st, td[i]);
    print(st);
  }

  printf("Stack is empty: %s\n", is_empty(st) ? "Yes" : "No"); // No
  printf("Stack is full: %s\n", is_full(st) ? "Yes" : "No");   // Yes

  Data d;
  for (int i = 0; i < DEPTH; i++) {
    d = pop(st);
    printf("Pop from stack: %d\n", d);
    print(st);
  }

  printf("Stack is empty: %s\n", is_empty(st) ? "Yes" : "No"); // Yes
  printf("Stack is full: %s\n", is_full(st) ? "Yes" : "No");   // No

  return 0;
}

#include "stack.h"

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

  return 0;
}

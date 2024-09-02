#include "stack.h"

int main() {
  Stack s;
  Stack *st = &s;

  init(st);
  print(st);

  return 0;
}

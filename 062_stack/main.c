#include "stack.h"

int main() {
  Stack s = {{7, 4, 1}, 3};
  Stack *sp = &s;

  print(sp);

  return 0;
}

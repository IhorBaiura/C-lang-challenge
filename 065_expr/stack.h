#include <string.h>
#define STEP 10

typedef int Data;
typedef struct Stack {
  Data *stack;
  unsigned int n;
  size_t size;
} Stack;

Stack *create();

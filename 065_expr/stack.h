#include <stdbool.h>
#include <string.h>
#define STEP 10

typedef int Data;
typedef struct Stack {
  Data *a;
  unsigned int n;
  size_t size;
} Stack;

Stack *create();
Data pop(Stack *st);
void push(Stack *st, Data d);
bool is_empty(Stack *st);
bool is_full(Stack *st);
void destroy(Stack *st);

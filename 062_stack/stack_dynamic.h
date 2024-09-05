#include <string.h>
#define STEP 10

typedef int Data;
typedef struct {
  Data *a;
  unsigned int n;
  size_t size;
} Stack;

Stack *create();
void print(Stack *st);
void init(Stack *st);
void push(Stack *st, Data d);
Data pop(Stack *st);
int is_empty(Stack *st);
int is_full(Stack *st);
void destroy(Stack *st);

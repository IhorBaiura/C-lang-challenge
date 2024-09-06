#include <string.h>
#define STEP 10

typedef int Data;
typedef struct {
  unsigned int n;
  size_t size;
  Data a[1]; // put in last position
} Stack;

Stack *create();
void print(Stack *st);
void push(Stack **pst, Data d);
Data pop(Stack *st);
int is_empty(Stack *st);
int is_full(Stack *st);
void destroy(Stack *st);

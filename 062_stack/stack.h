#define DEPTH 8

typedef int Data;
typedef struct {
  Data a[DEPTH];
  unsigned int n;
} Stack;

void print(Stack *st);
void init(Stack *st);
void push(Stack *st, Data d);
Data pop(Stack *st);
int is_empty(Stack *st);

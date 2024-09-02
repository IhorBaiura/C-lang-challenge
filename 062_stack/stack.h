#define DEPTH 8

typedef int Date;
typedef struct {
  Date a[DEPTH];
  unsigned int n;
} Stack;

void print(Stack *st);

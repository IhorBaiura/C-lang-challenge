#include <math.h>
#include <stdio.h>
#include <string.h>

#define RED "\033[31m"
#define WHITE "\033[37m"

void push(double);
double pop(void);

void mathfn(char s[]) {
  double tmp;

  if (strcmp(s, "sin")) {
    push(sin(pop()));
  } else if (strcmp(s, "cos")) {
    push(cos(pop()));
  } else if (strcmp(s, "exp")) {
    push(exp(pop()));
  } else if (strcmp(s, "pow")) {
    tmp = pop();
    push(pow(pop(), tmp));
  } else {
    printf("%sThere is an indefined operator %s%s", RED, s, WHITE);
  }
}

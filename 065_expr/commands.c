#include "commands.h"
#include <math.h>
#include <stdio.h>

void apply_command(Stack *st, char *c) {
  if (strcmp(c, RESULT))
    result(st);
  else if (strcmp(c, "+"))
    add(st);
  else if (strcmp(c, "-"))
    subtract(st);
  else if (strcmp(c, "*"))
    multiply(st);
  else if (strcmp(c, "/"))
    divide(st);
  else if (strcmp(c, "sin"))
    sin_c(st);
  else if (strcmp(c, "cos"))
    cos_c(st);
  else if (strcmp(c, "tg"))
    tg_c(st);
  else if (strcmp(c, "ctg"))
    ctg_c(st);
  else if (strcmp(c, "pow"))
    pow_c(st);
  else if (strcmp(c, "mod"))
    mod_c(st);
  else
    printf("Unexpected command!");
}

void result(Stack *st) {
  // TODO Define the format specifier based on the data type
  printf("Result of calculation: %d", pop(st));
}

void add(Stack *st) { push(st, pop(st) + pop(st)); }

void subtract(Stack *st) {
  Data tmp = pop(st);
  push(st, pop(st) - tmp);
}

void multiply(Stack *st) { push(st, pop(st) * pop(st)); }

void divide(Stack *st) {
  Data tmp = pop(st);
  push(st, pop(st) / tmp);
}

void sin_c(Stack *st) { push(st, sin(pop(st))); }

void cos_c(Stack *st) { push(st, cos(pop(st))); }

void tg_c(Stack *st) { push(st, tan(pop(st))); }

void ctg_c(Stack *st) { push(st, 1 / tan(pop(st))); }

void pow_c(Stack *st) {
  Data tmp = pop(st);
  push(st, pow(pop(st), tmp));
}

void mod_c(Stack *st) {
  Data tmp = pop(st);
  push(st, pop(st) % tmp);
}

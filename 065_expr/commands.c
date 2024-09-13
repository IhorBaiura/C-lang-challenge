#include "commands.h"
#include <math.h>

void add(Stack *st) { push(st, pop(st) + pop(st)); }

void subtract(Stack *st) { push(st, pop(st) + pop(st)); }

void multiply(Stack *st) { push(st, pop(st) * pop(st)); }

void divide(Stack *st) { push(st, pop(st) / pop(st)); }

void sin_c(Stack *st) { push(st, sin(pop(st))); }

void cos_c(Stack *st) { push(st, cos(pop(st))); }

void tg_c(Stack *st) { push(st, tan(pop(st))); }

void ctg_c(Stack *st) { push(st, 1 / tan(pop(st))); }

void pow_c(Stack *st) {
  Data tmp = pop(st);
  push(st, pow(tmp, pop(st)));
}

void mod_c(Stack *st) {
  Data tmp = pop(st);
  push(st, tmp % pop(st));
}

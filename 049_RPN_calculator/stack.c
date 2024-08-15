/*
 *
 * Exercise 4-4. Add commands to print the top element of the stack without
 * popping, to duplicate it, and to swap the top two elements. Add a command to
 * clear the stack.
 *
 */

#include <stdio.h>

#define MAXVAL 100 /* maximum depth of val stack */

int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f) {
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, can’t push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void) {
  if (sp > 0)
    return val[--sp];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

void printl(void) { printf("Last element of stack is %.8g\n", val[sp]); }

void duplicatel(void) {
  if (sp < MAXVAL) {
    ++sp;
    val[sp] = val[sp - 1];
  } else {
    printf("error: stack full, can’t duplicate.\n");
  }
}

void swap(void) {
  double tmp = val[sp - 1];
  val[sp - 1] = val[sp];
  val[sp] = tmp;
}

void clear(void) { sp = 0; }

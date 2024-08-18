/*
 *
 * Exercise 4-3. Given the basic framework, it’s straightforward to extend the
 * calculator. Add the modulus (%) operator and provisions for negative numbers.
 *
 * Exercise 4-5. Add access to library functions like sin, exp, and pow. See
 * <math.h> in Appendix B, Section 4.
 *
 * Exercise 4-6. Add commands for handling variables. (It’s easy to provide
 * twenty-six variables with single-letter names.) Add a variable for the most
 * recently printed value.
 *
 */

#include <stdio.h>
#include <stdlib.h> /* for atof() */

#define MAXOP 100  /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define MATHOP 'M' /* signal that a number was found */
#define VAR 'V'
#define ASSIGN 'A'
#define RESULT 'R'
#define CLEAR 'C'

int getop(char[]);
void push(double);
double pop(void);
void mathfn(char s[]);
void putv(char name, double value);
double getv(char name);
void addlv(double val);
void printlv();
void clears(void);

/* reverse Polish calculator */
int main(int argc, char *argv[]) {
  int type;
  double op2;
  char s[MAXOP];
  while ((type = getop(s)) != EOF) {
    switch (type) {
    case NUMBER:
      printf("numb: %f\n", atof(s));
      push(atof(s));
      break;
    case MATHOP:
      mathfn(s);
      break;
    case VAR:
      push(getv(s[0]));
      break;
    case ASSIGN:
      printf("assign: %c\n", s[0]);
      putv(s[0], pop());
      break;
    case '+':
      push(pop() + pop());
      break;
    case RESULT:
      printf("RESULT\n");
      addlv(pop());
      break;
    case CLEAR:
      printf("CLEAR\n");
      clears();
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0)
        push(pop() / op2);
      else
        printf("error: zero divisor\n");
      break;
    case '%':
      op2 = pop();
      if (op2 != 0.0)
        push((int)pop() % (int)op2);
      else
        printf("error: zero divisor\n");
      break;
    case '\n':
      printlv();
      break;
    default:
      printf("error: unknown command %s\n", s);
      break;
    }
  }
  return 0;
}

#include <stdio.h>

#define VARIABLE_COUNT 26

double vars[VARIABLE_COUNT] = {0.0};
double lastval = 0.0;

void putv(char name, double value) {
  if (name >= 'a' && name <= 'z') {
    vars['a' - name] = value;
  }
}

double getv(char name) {
  if (name >= 'a' && name <= 'z') {
    return vars['a' - name];
  }

  return 0.0;
}

void addlv(double val) { lastval = val; }
void printlv() { printf("\t%.8g\n", lastval); }

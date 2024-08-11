#include <stdio.h>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define WHITE "\033[37m"

double _atof(char s[]);

void run_test(char *s, double expected) {
  double result = _atof(s);
  int r = result == expected;
  printf("%satof(\"%s\") -> %.10g (Expected: %.10g) - %s%s\n", r ? GREEN : RED,
         s, result, expected, r ? "PASS" : "FAIL", WHITE);
}

int main() {
  run_test("123.45", 123.45);
  run_test("123.45e2", 12345.0);
  run_test("123.45e-2", 1.2345);
  run_test("1.2345e6", 1234500.0);
  run_test("1.2345e-6", 0.0000012345);
  run_test("2e3", 2000.0);
  run_test("2e-3", 0.002);
  run_test(".45e2", 45.0);
  run_test("123.e2", 12300.0);
  run_test("5e0", 5.0);
  run_test("-123.45e3", -123450.0);
  run_test("-123.45e-3", -0.12345);
  run_test("1.23E4", 12300.0);
  run_test("4.56e8", 456000000.0);
  run_test("0e5", 0.0);

  return 0;
}

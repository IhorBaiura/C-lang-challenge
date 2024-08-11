/*
 *
 * Exercise 4-2. Extend atof to handle scientific notation of the form
 *    123.45e-6
 * where a floating-point number may be followed by e or E and an
 * optionally signed exponent.
 *
 */

#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>

/* atof: convert string s to double */
double _atof(const char s[]) {
  double val, power, exp;
  int i, sign, k;
  int exp_sign = 1;
  char exp_val[SCHAR_MAX] = "1";

  for (i = 0; isspace(s[i]); i++) /* skip white space */
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  for (val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');
  if (s[i] == '.')
    i++;
  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10.0;
  }
  if (s[i] == 'e' || s[i] == 'E') {
    i++;

    if (s[i] == '-') {
      exp_sign = -1;
      i++;
    }

    for (k = 0; isdigit(s[i]); i++) {
      exp_val[k++] = s[i];
    }
    exp_val[k] = '\0';

    exp = pow(10, atoi(exp_val));
    power = exp_sign > 0 ? power / exp : power * exp;
  }
  return sign * val / power;
}

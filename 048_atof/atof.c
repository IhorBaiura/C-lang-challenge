/*
 *
 * Exercise 4-2. Extend atof to handle scientific notation of the form
 *    123.45e-6
 * where a floating-point number may be followed by e or E and an
 * optionally signed exponent.
 *
 */

#include <ctype.h>
#include <math.h>
#include <stdlib.h>

/* atof: convert string s to double */
double _atof(char s[]) {
  double val, power;
  int i, sign, k, exp;
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
    ++i;
    if (s[i] == '-') {
      while (isdigit(s[i])) {
        s[k++] = s[i];
      }
      if (k > 0)
        s[k] = '\0';
      exp = pow(10, atoi(s));
      power /= exp;
    } else if (s[i] == '+') {
      while (isdigit(s[i])) {
        s[k++] = s[i];
      }
      if (k > 0)
        s[k] = '\0';
      exp = pow(10, atoi(s));
      power *= exp;
    }
  }
  return sign * val / power;
}

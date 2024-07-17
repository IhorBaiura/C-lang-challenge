/*
 * Exercise 2-1. Write a program to determine the ranges of char, short, int,
 * and long variables, both signed and unsigned, by printing appropriate values
 * from standard headers and by direct computation. Harder if you compute them:
 * determine the ranges of the various floating-point types.
 */

#include <float.h>
#include <limits.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  char c;
  signed char sc;
  unsigned char uc;
  short s;
  short int si;
  signed short ss;
  unsigned short us;
  int i;
  signed int sgi;
  unsigned int ui;
  long l;
  long int li;
  signed long sl;
  unsigned long ul;
  long long ll;
  long long int lli;
  float f;
  double df;
  long double ld;

  printf("\n| type\t\t\t|\tbytes\t\t|\tbits\t\t|\tmin\t\t|\tmax\t\t|\n\n");
  printf("| char\t\t\t|\t%lu\t\t|\t%d\t\t|\t%d\t\t|\t%d\t\t|\n", sizeof(c),
         CHAR_BIT, CHAR_MIN, CHAR_MAX);
  printf("| signed char\t\t|\t%lu\t\t|\t%d\t\t|\t%d\t\t|\t%d\t\t|\n",
         sizeof(sc), CHAR_BIT, SCHAR_MIN, SCHAR_MAX);
  printf("| unsigned char\t\t|\t%lu\t\t|\t%d\t\t|\t%d\t\t|\t%d\t\t|\n",
         sizeof(uc), CHAR_BIT, 0, UCHAR_MAX);

  printf("\n| short\t\t\t|\t%lu\t\t|\t%lu\t\t|\t%d\t\t|\t%d\t\t|\n", sizeof(s),
         sizeof(s) * CHAR_BIT, SHRT_MIN, SHRT_MAX);
  printf("| short = short int\t|\t%lu\t\t|\t%lu\t\t|\t%d\t\t|\t%d\t\t|\n",
         sizeof(si), sizeof(si) * CHAR_BIT, SHRT_MIN, SHRT_MAX);
  printf("| short = signed short\t|\t%lu\t\t|\t%lu\t\t|\t%d\t\t|\t%d\t\t|\n",
         sizeof(ss), sizeof(ss) * CHAR_BIT, SHRT_MIN, SHRT_MAX);
  printf("| unsigned short\t|\t%lu\t\t|\t%lu\t\t|\t%d\t\t|\t%d\t\t|\n",
         sizeof(us), sizeof(us) * CHAR_BIT, 0, (unsigned short)USHRT_MAX);

  printf("\n| int\t\t\t|\t%lu\t\t|\t%lu\t\t|\t%d\t|\t%d\t|\n", sizeof(i),
         sizeof(i) * CHAR_BIT, INT_MIN, INT_MAX);
  printf("| signed int = int\t|\t%lu\t\t|\t%lu\t\t|\t%d\t|\t%d\t|\n",
         sizeof(sgi), sizeof(sgi) * CHAR_BIT, INT_MIN, INT_MAX);
  printf("| unsigned int\t\t|\t%lu\t\t|\t%lu\t\t|\t%d\t\t|\t%u\t|\n",
         sizeof(ui), sizeof(ui) * CHAR_BIT, 0, (unsigned int)UINT_MAX);

  printf("\n| long\t\t\t|\t%lu\t\t|\t%lu\t\t| %ld\t| %ld\t|\n", sizeof(l),
         sizeof(l) * CHAR_BIT, (long)LONG_MIN, (long)LONG_MAX);
  printf("| long int = long\t|\t%lu\t\t|\t%lu\t\t| %ld\t| %ld\t|\n", sizeof(li),
         sizeof(li) * CHAR_BIT, (long)LONG_MIN, (long)LONG_MAX);
  printf("| signrf long = long\t|\t%lu\t\t|\t%lu\t\t| %ld\t| %ld\t|\n",
         sizeof(sl), sizeof(sl) * CHAR_BIT, (long)LONG_MIN, (long)LONG_MAX);
  printf("| unsigned long\t\t|\t%lu\t\t|\t%lu\t\t|\t%d\t\t| %lu\t|\n",
         sizeof(ul), sizeof(ul) * CHAR_BIT, 0, (unsigned long)ULONG_MAX);

  printf("\n\n float types");
  printf("\n| float\t\t\t|\t%lu\t\t|\t%lu\t\t|\t%g\t|\t%g\t|\n", sizeof(float),
         sizeof(float) * CHAR_BIT, (float)FLT_MAX, (float)FLT_MIN);
  printf("| -float\t\t|\t%lu\t\t|\t%lu\t\t|\t%g\t|\t%g\t|\n", sizeof(float),
         sizeof(float) * CHAR_BIT, (float)-FLT_MAX, (float)-FLT_MIN);
  printf("| double\t\t|\t%lu\t\t|\t%lu\t\t|\t%g\t|\t%g\t|\n", sizeof(double),
         sizeof(double) * CHAR_BIT, (double)DBL_MAX, (double)DBL_MIN);

  return 0;
}

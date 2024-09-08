/*
 *
 * Exercise 5-8. There is no error checking in day_of_year or month_day. Remedy
 * this defect.
 *
 * Exercise 5-9. Rewrite the routines day_of_year and month_day with
 * pointers instead of indexing.
 *
 */

#include "converter.h"
#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int day_of_year(int year, int month, int day) {
  int leap;
  char *p;

  if (month < 1 || month > 12) {
    printf("Wrong month was recieved!\n");
    return -1;
  }

  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
  p = daytab[leap];

  if (day < 1 || day > daytab[leap][month]) {
    printf("Wrong day was recieved!\n");
    return -1;
  }

  while (--month)
    day += *++p;

  return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday) {
  int leap;
  char *p;

  if (year < 1) {
    *pmonth = -1;
    *pday = -1;
    return;
  }

  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
  p = daytab[leap];

  while (yearday > *++p)
    yearday -= *p;

  *pday = yearday;
  *pmonth = p - *(daytab + leap);
}

char *month_name(int n) {
  static char *name[] = {"Illegal month", "January",   "February", "March",
                         "April",         "May",       "June",     "July",
                         "August",        "September", "October",  "November",
                         "December"};

  return (n < 1 || n > 12) ? name[0] : name[n];
}

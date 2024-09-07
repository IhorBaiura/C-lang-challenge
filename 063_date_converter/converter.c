/*
 *
 * Exercise 5-8. There is no error checking in day_of_year or month_day. Remedy
 * this defect.
 *
 */

#include "converter.h"
#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int day_of_year(int year, int month, int day) {
  int i, leap;

  if (month < 1 || month > 12) {
    printf("Wrong month was recieved!\n");
    return -1;
  }

  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

  if (day < 1 || day > daytab[leap][month]) {
    printf("Wrong day was recieved!\n");
    return -1;
  }

  for (i = 1; i < month; i++)
    day += daytab[leap][i];

  return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday) {
  int i, leap;

  if (year < 1) {
    *pmonth = -1;
    *pday = -1;
    return;
  }

  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

  for (i = 1; yearday > daytab[leap][i]; i++)
    yearday -= daytab[leap][i];

  if (i > 12 && yearday > daytab[leap][i]) {
    *pday = -1;
    *pmonth = -1;
  } else {
    *pday = yearday;
    *pmonth = i;
  }
}

char *month_name(int n) {
  static char *name[] = {"Illegal month", "January",   "February", "March",
                         "April",         "May",       "June",     "July",
                         "August",        "September", "October",  "November",
                         "December"};

  return (n < 1 || n > 12) ? name[0] : name[n];
}

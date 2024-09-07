#include "converter.h"
#include <stdio.h>

int main() {

  printf("06.03.2024 is %dth day of 2024 year\n", day_of_year(2024, 06, 03));

  int month, day;
  month_day(2024, 155, &month, &day);
  printf("155th day in 2024th year is %.2d.%.2d.2024\n", month, day);
  printf("12th month is %s\n", (char *)month_name(12));

  return 0;
}

/*
 *
 * Exercise 2-4. Write an alternate version of squeeze(s1,s2) that deletes each
 * character in s1 that matches any character in the string s2.
 *
 */

#include <stdio.h>

void squeeze_str(char str[], const char filret[]);
void squeeze(char str[], const char c);

int main(int argc, char *argv[]) {
  char str[] = "new string key value array";
  char filter[] = "array";

  printf("str: %s, filter: %s, ", str, filter);
  squeeze_str(str, filter);
  printf("filtered string: %s\n", str);

  return 0;
}

void squeeze(char str[], const char c) {
  int i, j;

  for (i = j = 0; str[i] != '\0'; i++)
    if (str[i] != c)
      str[j++] = str[i];

  str[j] = '\0';
}

void squeeze_str(char str[], const char filter[]) {
  int i;

  for (i = 0; filter[i] != '\0'; i++)
    squeeze(str, filter[i]);
}

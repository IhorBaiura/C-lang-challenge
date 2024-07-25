/*
 *
 *  Exercise 2-5. Write the function any(s1,s2), which returns the first
 * location in the string s1 where any character from the string s2 occurs, or
 * -1 if s1 contains no characters from s2. (The standard library function
 * strpbrk does the same job but returns a pointer to the location.)
 *
 */

#include <stdio.h>

int any(const char str1[], const char str2[]);

int main(int argc, char *argv[]) {
  char str1[] = "this is the first string";
  char str2[] = "abr";

  printf("%d\n", any(str1, str2));

  return 0;
}

int any(const char str1[], const char str2[]) {
  int i, j;

  for (i = 0; str1[i] != '\0'; i++)
    for (j = 0; str2[j] != '\0'; j++)
      if (str1[i] == str2[j])
        return i;

  return -1;
}

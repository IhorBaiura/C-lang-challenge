/*
 *
 * Exercise 4-1. Write the function strrindex(s,t), which returns the position
 * of the rightmost occurrence of t in s, or -1 if there is none.
 *
 */

int strrindex(char s[], char t[]) {
  int i, j, k;
  int last = -1;

  for (i = 0; s[i] != '\0'; i++) {
    for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
      ;
    if (k > 0 && t[k] == '\0')
      last = i;
  }
  return last;
}

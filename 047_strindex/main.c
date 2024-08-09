#include <stdio.h>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define WHITE "\033[37m"

int strindex(char s[], char t[]);
int strrindex(char s[], char t[]);

void run_test_strindex(char s[], char t[], int expected) {
  int result = strindex(s, t);
  int r = result == expected;
  printf("%sstrindex(\"%s\", \"%s\") -> %d (Expected: %d) - %s%s\n",
         r ? GREEN : RED, s, t, result, expected, r ? "PASS" : "FAIL", WHITE);
}

void run_test_strrindex(char s[], char t[], int expected) {
  int result = strrindex(s, t);
  int r = result == expected;
  printf("%sstrrindex(\"%s\", \"%s\") -> %d (Expected: %d) - %s%s\n",
         r ? GREEN : RED, s, t, result, expected, r ? "PASS" : "FAIL", WHITE);
}

int main() {
  printf("-----\t\t\t strindex \t\t\t-----\n");
  run_test_strindex("hello world", "hello", 0);
  run_test_strindex("hello world", "world", 6);
  run_test_strindex("hello world", "d", 10);
  run_test_strindex("hello world", "goodbye", -1);
  run_test_strindex("hello world", "", -1);
  run_test_strindex("", "hello", -1);
  run_test_strindex("", "", -1);
  run_test_strindex("abcabcabc", "abc", 0);
  run_test_strindex("hello world", "o", 4);
  run_test_strindex("hi", "hello", -1);

  printf("\n\n-----\t\t\t strrindex \t\t\t-----\n");
  run_test_strrindex("hello world", "world", 6);
  run_test_strrindex("hello world", "hello", 0);
  run_test_strrindex("abcabcabc", "abc", 6);
  run_test_strrindex("hello world", "o", 7);
  run_test_strrindex("hello world", "goodbye", -1);
  run_test_strrindex("hello world", "", -1);
  run_test_strrindex("", "hello", -1);
  run_test_strrindex("", "", -1);
  run_test_strrindex("this is a test", "test", 10);
  run_test_strrindex("hi", "hello", -1);

  return 0;
}

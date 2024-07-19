#include <stdio.h>

int main(int argc, char *argv[]) {
  // printf("\a");
  printf("aaaa aaaa aaaa\rbbbb cccc dd\n");
  printf("first\vstring\vagain\n");
  printf("first\tsecond\tthird\n");

  printf("first\b\b\b second\n");

  printf("first\fstring\fagain\n");

  printf("%d\n", '\0');

  return 0;
}

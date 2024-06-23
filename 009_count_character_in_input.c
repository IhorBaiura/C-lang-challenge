#include <stdio.h>

int main(int argc, char *argv[]) {
  long nc;

  /*
  nc = 0;
  while (getchar() != EOF)
    ++nc;
  printf("%ld\n", nc);
  */

  for (nc = 0; getchar() != EOF; ++nc)
    ;
  printf("count: %ld\n", nc);
}

#include <stdio.h>

int main(int argc, char *argv[]) {
  printf("int value of EOF constant is %d\n", EOF);
  printf("char value of EOF constant is %c\n", EOF);

  printf("Char isn't equal to EOF: %d\n", getchar() != EOF);
}

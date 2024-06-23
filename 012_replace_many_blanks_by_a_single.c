#include <stdio.h>

int main(int argc, char *argv[]) {
  int c, bl;

  bl = 0;
  while ((c = getchar()) != EOF) {
    if (c != ' ') {
      if (bl)
        putchar(' ');
      putchar(c);
      bl = 0;
    }

    if (c == ' ')
      ++bl;
  }
}

#include <stdio.h>

int main(int argc, char *argv[]) {
  int c, esc;

  while ((c = getchar()) != EOF) {
    esc = 0;

    if (c == '\t') {
      putchar('\\');
      putchar('t');
      esc = 1;
    }

    if (c == '\b') {
      putchar('\\');
      putchar('b');
      esc = 1;
    }

    if (c == '\\') {
      putchar('\\');
      putchar('\\');
      esc = 1;
    }

    if (esc == 0)
      putchar(c);
  }
}

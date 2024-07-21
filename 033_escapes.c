#include <stdio.h>

enum status {
  OK = 200,
  BadRequest = 400,
  Unauthorized = 401,
  Forbidden = 403,
  NotFound = 404,
  InternalServerError = 500,
};

int main(void) {
  // printf("\a");
  printf("aaaa aaaa aaaa\rbbbb cccc dd\n");
  printf("first\vstring\vagain\n");
  printf("first\tsecond\tthird\n");

  printf("first\b\b\b second\n");

  printf("first\fstring\fagain\n");

  printf("%d\n", '\0');

  printf("%d\n", '0' * '1' * '2');
  printf("%d\n", '0' == 48);
  printf("%d\n", '\v');
  printf("%c\t%c\t%c\n", 75, '\113', '\x4b');

  enum status code = 305;
  printf("%d\n", code);

  return 0;
}

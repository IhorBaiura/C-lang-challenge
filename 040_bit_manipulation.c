/*
 *
 * Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n
 * bits that begin at position p set to the rightmost n bits of y, leaving the
 * other bits unchanged.
 *
 * Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits
 * that begin at position p inverted (i.e., 1 changed into 0 and vice versa),
 * leaving the others unchanged.
 *
 * Exercise 2-8. Write a function rightrot(x,n) that returns the value of the
 * integer x rotated to the right by n bit positions.
 *
 */

#include <stdio.h>

#define BITE_SIZE 8

enum SIGN { NEGATIVE, POSITIVE };

void printBits(unsigned int num);

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, int y);
unsigned invert(unsigned x, int p, int n);
unsigned invert_imp(unsigned x, int p, int n);
unsigned rightrot(unsigned x, int p);

int main(int argc, char *argv[]) {

  printf("\n----------- invert ---------\n");
  invert(0xFA, 4, 3);

  printf("\n----------- invert improved ---------\n");
  invert_imp(0xFA, 4, 3);

  printf("\n----------- setbits ---------\n");
  setbits(0xFA, 4, 3, 0xD3);

  return 0;
}

/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n) {
  return (x >> (p + 1 - n)) & ~(~0 << n);
}

unsigned setbits(unsigned x, int p, int n, int y) {
  unsigned char shift = p + 1 - n;
  unsigned char mask = ~(~0 << n);
  printf("x: \t\t\t\t\t");
  printBits(x);

  printf("x & ~(~(~0 << n) << shift): \t\t");
  printBits(x & ~(~(~0 << n) << shift));

  printf("(y & ~(~0 << n)) << shift: \t\t");
  printBits((y & ~(~0 << n)) << shift);

  printf("res: \t\t\t\t\t");
  printBits(x & ~(mask << shift) | (y & mask) << shift);

  return x & ~(mask << shift) | (y & mask) << shift;
}

unsigned invert(unsigned x, int p, int n) {
  unsigned char shift = p + 1 - n;
  unsigned char shift_l = sizeof(unsigned) * 8 - n;

  printf("shift: \t\t\t\t\t%d\n", shift);

  printf("x: \t\t\t\t\t");
  printBits(x);

  printf("x & ~(~(~0 << n) << shift): \t\t");
  printBits(x & ~(~(~0 << n) << shift));

  printf("res: \t\t\t\t\t");
  printBits(x & ~(~(~0 << n) << shift) |
            (~(x >> shift & ~(~0 << n)) << (sizeof(unsigned) * 8 - n) >>
             (sizeof(unsigned) * 8 - n - shift)));

  return x & ~(~(~0 << n) << shift) |
         (~(x >> shift & ~(~0 << n)) << shift_l >> (shift_l - shift));
}

unsigned invert_imp(unsigned x, int p, int n) {
  unsigned mask = ~(~0 << n) << (p + 1 - n);

  printf("~(~0 << n) << (p + 1 - n): \t\t");
  printBits(~(~0 << n) << (p + 1 - n));

  printf("res: \t\t\t\t\t");
  printBits(x ^ mask);

  return x ^ mask;
}

void printBits(unsigned int num) {
  int bits = sizeof(num) * 8;
  for (int i = bits - 1; i >= 0; i--) {
    unsigned int bit = (num >> i) & 1;
    printf("%u", bit);

    if (i % 4 == 0)
      putchar(' ');
  }
  printf("\n");
}

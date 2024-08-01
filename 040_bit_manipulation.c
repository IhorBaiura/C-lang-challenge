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

void printBits(unsigned int num);
void printRes(char title[], unsigned input, unsigned res);

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, int y);
unsigned invert(unsigned x, int p, int n);
unsigned invert_imp(unsigned x, int p, int n);
unsigned rightrot(unsigned x, int n);
unsigned rightrot_imp(unsigned x, int n);

int bitcount_imp(unsigned x);

int main(int argc, char *argv[]) {
  printRes("invert invert(0xFA, 4, 3)", 0xFA, invert(0xFA, 4, 3));
  printRes("invert improved invert_imp(0xFA, 4, 3)", 0xFA,
           invert_imp(0xFA, 4, 3));
  printRes("setbits setbits(0xFA, 4, 3, 0xD3)", 0xFA,
           setbits(0xFA, 4, 3, 0xD3));
  printRes("rightrot rightrot(0xFA, 6)", 0xFA, rightrot(0xFA, 6));
  printRes("rightrot_imp rightrot_imp(0xFA, 6)", 0xFA, rightrot_imp(0xFA, 6));

  printf("\n----------- bitcount_imp ---------\n");
  printf("x: \t\t\t\t\t");
  printBits(0xFF);
  printf("res: \t\t\t\t\t%d\n", bitcount_imp(0xFF));

  return 0;
}

/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n) {
  return (x >> (p + 1 - n)) & ~(~0 << n);
}

unsigned setbits(unsigned x, int p, int n, int y) {
  unsigned char shift = p + 1 - n;
  unsigned mask = ~(~0 << n);

  return (x & ~(mask << shift)) | (y & mask) << shift;
}

unsigned invert(unsigned x, int p, int n) {
  unsigned char shift = p + 1 - n;
  unsigned char shift_l = sizeof(unsigned) * BITE_SIZE - n;

  return x & ~(~(~0 << n) << shift) |
         (~(x >> shift & ~(~0 << n)) << shift_l >> (shift_l - shift));
}

unsigned invert_imp(unsigned x, int p, int n) {
  unsigned mask = ~(~0 << n) << (p + 1 - n);

  return x ^ mask;
}

unsigned rightrot(unsigned x, int n) {
  return (x & ~(~0 << n)) << (sizeof(unsigned) * BITE_SIZE - n) | x >> n;
}

unsigned rightrot_imp(unsigned x, int n) {
  int bits = sizeof(x) * BITE_SIZE;
  n = n % bits; // align n to size of x (case n > bits)

  return (x >> n) | (x << (bits - n));
}

/* bitcount: count 1 bits in x */
int bitcount(unsigned x) {
  int b;
  for (b = 0; x != 0; x >>= 1)
    if (x & 01)
      b++;
  return b;
}

int bitcount_imp(unsigned x) {
  int i;
  for (i = 0; x != 0; i++)
    x &= (x - 1);
  return i;
}

void printBits(unsigned int num) {
  int bits = sizeof(num) * BITE_SIZE;
  for (int i = bits - 1; i >= 0; i--) {
    unsigned int bit = (num >> i) & 1;
    printf("%u", bit);

    if (i % 4 == 0)
      putchar(' ');
  }
  printf("\n");
}

void printRes(char title[], unsigned input, unsigned res) {
  printf("\n----------- %s ---------\n", title);

  printf("x: \t\t\t\t\t");
  printBits(input);

  printf("res: \t\t\t\t\t");
  printBits(res);
}

/*
 *
 * 1. bit masking             (& AND)
 * 2. parity                  (& AND)
 * 3. set_bits_to_zero        (& AND   ~ one’s complement)
 * 4. check_bit               (& AND   << left shift)
 * 5. show_permissions        (& AND)
 *
 */

#include <stdio.h>
// #include <time.h>
#include <stdbool.h>

#define BITE_SIZE 8

enum SIGN { NEGATIVE, POSITIVE };
enum PERMISSIONS {
  READ_PERMISSION = 1,
  WRITE_PERMISSION = 2,
  EXECUTE_PERMISSION = 4,
};

void printb(int num);
void printb_bitwice(int num);

unsigned int bit_masking(unsigned int num, unsigned int mask);
unsigned int set_bits_to_zero(unsigned int num, unsigned int mask);
bool parity(int num);
bool check_bit(unsigned int num, unsigned char bit_position);
void show_permissions(unsigned int permissions);

int main(int argc, char *argv[]) {
  // int num = 125;
  //
  // printb(num);
  // printb(573);
  // printb(0);
  // printb(-16);

  /*clock_t begin_loop = clock();
  for (int i = 0; i < 1000000000; i++)
    printb(15758);
  clock_t end_loop = clock();

  clock_t begin_smart = clock();
  for (int i = 0; i < 1000000000; i++)
    printb_bitwice(15758);
  clock_t end_smart = clock();

  printf("printb\t\t: time: %f\n",
         (double)(end_loop - begin_loop) / CLOCKS_PER_SEC);
  printf("printb_bitwice\t: tiem: %f\n",
         (double)(end_smart - begin_smart) / CLOCKS_PER_SEC);*/

  /*
   *
   * iterations count: 1 000 000
   * printb          : time: 0.076132
   * printb_bitwice  : tiem: 0.047023    ~ 40% faster
   *
   * iterations count: 100 000 000
   * printb          : time: 4.794608
   * printb_bitwice  : tiem: 4.521706    ~ 8% faster
   *
   * iterations count: 1 000 000 000
   * printb          : time: 47.546372
   * printb_bitwice  : tiem: 45.208066   ~ 5% faster
   *
   */

  bit_masking(125, 0xF);
  bit_masking(64507, 0xFF);

  parity(125);
  parity(124);

  set_bits_to_zero(125, 0xF);
  set_bits_to_zero(64507, 0xFF);

  check_bit(15, 3);
  check_bit(15, 4);

  show_permissions(READ_PERMISSION | WRITE_PERMISSION);
  show_permissions(READ_PERMISSION | EXECUTE_PERMISSION);

  return 0;
}

void printb(signed int num) {
  char binary[sizeof(unsigned int) * BITE_SIZE] = {0};
  char sign = POSITIVE;
  char reminder = 1;
  int i, j;

  printf("printb num: %d \t\t", num);

  if (num < 0) {
    num = -num;
    sign = NEGATIVE;
  }

  i = 0;
  if (num == 0)
    binary[i++] = 0;
  else
    while (num > 0) {
      binary[i++] = num % 2;
      num /= 2;
    }

  if (sign == NEGATIVE) {
    for (j = 0; j < sizeof(unsigned int) * BITE_SIZE; j++) {
      if (!binary[j] + reminder > 1) {
        reminder = 1;
        binary[j] = 0;
      } else {
        reminder = 0;
        binary[j] = 1;
      }
    }
  }

  for (j = sizeof(unsigned int) * BITE_SIZE - 1; j >= 0; j--) {
    if ((j + 1) % 4 == 0 && j != sizeof(unsigned int) * BITE_SIZE - 1)
      printf(" ");
    printf("%d", binary[j]);
  }
  printf("\n");
}

void printb_bitwice(int num) {
  char binary[sizeof(unsigned int) * 8], sign;
  int i, j;

  i = 0;
  if (num == 0)
    binary[i++] = 0;
  else
    while (num > 0) {
      binary[i++] = num & 1;
      num >>= 1;
    }

  while (i % (sizeof(unsigned int) * BITE_SIZE) != 0)
    binary[i++] = 0;

  for (j = i - 1; j >= 0; j--) {
    if ((j + 1) % 4 == 0 && j != i - 1)
      printf(" ");
    printf("%d", binary[j]);
  }
  printf("\n");
}

// To extract specific bits from a number or to clear specific bits
unsigned int bit_masking(unsigned int num, unsigned int mask) {
  unsigned int res = num & mask;

  printf("\n---------- bit_masking ----------\n");
  printf("number\t: ");
  printb(num);
  printf("mask\t: ");
  printb(mask);
  printf("result\t: ");
  printb(res);
  printf("\n");

  return res;
}

bool parity(int num) {
  if (num & 1) {
    printf("%d is odd\n", num);
    return 1;
  } else {
    printf("%d is even\n", num);
    return 0;
  }

  // return num & 1;
}

// Setting Specific Bits to Zero. Clear specific bits in a number.
unsigned int set_bits_to_zero(unsigned int num, unsigned int mask) {
  unsigned int res = num & ~mask;

  printf("\n---------- set_bits_to_zero ----------\n");
  printf("number\t: ");
  printb(num);
  printf("mask\t: ");
  printb(mask);
  printf("(~mask)\t: ");
  printb(~mask);
  printf("result\t: ");
  printb(res);
  printf("\n");

  return res;
}

// To test if specific bits in a number are set.
bool check_bit(unsigned int num, unsigned char bit_position) {
  unsigned int mask = 1 << bit_position;

  printf("\n---------- check_bit ----------\n");
  printf("position: %d\n", bit_position);
  printf("number\t: ");
  printb(num);
  printf("mask\t: ");
  printb(mask);

  if (num & mask) {
    printf("The %d bit is set.\n", bit_position);
    return true;
  } else {
    printf("The %d bit is not set.\n", bit_position);
    return false;
  }
}

// To check or set specific permission bits or flags in systems programming.
void show_permissions(unsigned int permissions) {
  printf("\n---------- show_permissions ----------\n");

  if (permissions & READ_PERMISSION) {
    printf("User has read permission.\n");
  } else {
    printf("User does not have read permission.\n");
  }

  if (permissions & WRITE_PERMISSION) {
    printf("User has write permission.\n");
  } else {
    printf("User does not have write permission.\n");
  }

  if (permissions & EXECUTE_PERMISSION) {
    printf("User has execute permission.\n");
  } else {
    printf("User does not have execute permission.\n");
  }
}

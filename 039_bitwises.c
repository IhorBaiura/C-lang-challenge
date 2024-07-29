/*
 *
 * 1. bit masking             (& AND)
 * 2. parity                  (& AND)
 * 3. set_bits_to_zero        (& AND   ~ one’s complement)
 * 4. set_specific_bits       (| OR)
 * 4. check_bit               (& AND   << left shift)
 * 5. show_permissions        (& AND)
 *
 * ...
 *
 */

#include <stdio.h>
// #include <time.h>
#include <stdbool.h>

#define BITE_SIZE 8

enum SIGN { NEGATIVE, POSITIVE };
enum PERMISSIONS {
  READ_PERMISSION = 1,
  WRITE_PERMISSION = 1 << 1,
  EXECUTE_PERMISSION = 1 << 2,
};

void printb(int num);
void printb_bitwice(int num);

unsigned int bit_masking(unsigned int num, unsigned int mask);
unsigned int set_bits_to_zero(unsigned int num, unsigned int mask);
unsigned int set_specific_bits_to_one(unsigned int num, unsigned int mask);
bool parity(int num);
bool check_bit(unsigned int num, unsigned char bit_position);
void show_permissions(unsigned int permissions);
unsigned int align_to_power_of_two(unsigned int num);
unsigned int encrypt(int data, int key);
unsigned int decrypt(int data, int key);
unsigned int multiplying_by_powers_of_two(int num, int power_of_two);

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

  unsigned int permissions =
      READ_PERMISSION | WRITE_PERMISSION; // Combine permissions
  printf("\nPermissions: ");
  printb(permissions); // Output: 3 (binary: 0000 0011)
  show_permissions(permissions);

  unsigned int permissions1 =
      READ_PERMISSION | EXECUTE_PERMISSION; // Combine permissions
  printf("\nPermissions1: ");
  printb(permissions1); // Output: 5 (binary: 0000 0101)
  show_permissions(permissions1);

  align_to_power_of_two(55);
  align_to_power_of_two(132);
  align_to_power_of_two(99);
  align_to_power_of_two(7);

  set_specific_bits_to_one(112, 0x5);
  set_specific_bits_to_one(43776, 0xFF);

  char a = 5;
  printf("a: ");
  printb(a);
  char b = 17;
  printf("b: ");
  printb(b);

  printf("a & b: ");
  printb(a & b);

  printf("a | b: ");
  printb(a | b);

  printf("a ^ b: ");
  printb(a ^ b);

  printf("a << 1: ");
  printb(a << 1);

  printf("a << 3: ");
  printb(a << 3);

  printf("a >> 1: ");
  printb(a >> 1);

  printf("a >> 3: ");
  printb(a >> 3);

  unsigned int red = 0xFF0000;   // Red component (FF0000 in hex)
  unsigned int green = 0x00FF00; // Green component (00FF00 in hex)
  unsigned int blue = 0x0000FF;  // Blue component (0000FF in hex)

  // Combine red, green, and blue into a single color value
  unsigned int color = red | green | blue; // result: 0xFFFFFF (white)

  printf("\n\nCombined color: 0x%X\n", color); // Output: 0xFFFFFF

  // Swapping Two Variables Without a Temporary Variable
  unsigned int x = 5; // 5 in binary: 0000 0101
  unsigned int y = 9; // 9 in binary: 0000 1001

  printf("Before swap: x = %u, y = %u\n", x, y);

  x = x ^ y; // x now becomes 0000 1100 (12 in decimal)
  y = x ^ y; // y now becomes 0000 0101 (5 in decimal)
  x = x ^ y; // x now becomes 0000 1001 (9 in decimal)

  printf("After swap: x = %u, y = %u\n", x, y); // Output: x = 9, y = 5

  printf("\n---------- data encription ----------\n");
  int data = 155;
  int key = 7463;
  printf("original data: %d\n", data);

  data = encrypt(data, key);
  data = decrypt(data, key);

  multiplying_by_powers_of_two(5, 3);

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

// To set specific bits of a number to 1.
unsigned int set_specific_bits_to_one(unsigned int num, unsigned int mask) {
  unsigned int res = num | mask;

  printf("\n---------- set_bits_to_zero ----------\n");
  printf("number\t: ");
  printb(num);
  printf("mask\t: ");
  printb(mask);
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

// Align a number to the nearest lower power of two for memory allocation.
unsigned int align_to_power_of_two(unsigned int num) {
  printf("\n---------- align_to_power_of_two ----------\n");
  printf("num\t: %d\n", num);

  if (num == 0)
    return 0;
  num--;
  num |= num >> 1;
  num |= num >> 2;
  num |= num >> 4;
  num |= num >> 8;
  num |= num >> 16;

  printf("aligned\t: %d\n", num + 1);

  return num + 1;
}

unsigned int encrypt(int data, int key) {
  unsigned int encrypted = data ^ key;
  printf("Encrypted data: %d\n", encrypted);
  return encrypted;
}

unsigned int decrypt(int data, int key) {
  unsigned int decrypted = data ^ key;
  printf("Decrypted data: %d\n", decrypted);
  return decrypted;
}

// To efficiently multiply an integer by a power of two.
unsigned int multiplying_by_powers_of_two(int num, int power_of_two) {
  unsigned int res = num << power_of_two;

  printf("\n---------- multiplying_by_powers_of_two ----------\n");
  printf("%d * 2 ^ %d = %d\n", num, power_of_two, res);

  return res;
}

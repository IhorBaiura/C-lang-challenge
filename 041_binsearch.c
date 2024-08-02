/*
 *
 * Exercise 3-1. Our binary search makes two tests inside the loop, when
 * one
 * would suffice (at the price of more tests outside). Write a version
 * with only
 * one test inside the loop and measure the difference in
 * run-time.
 *
 */

#include <stdio.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int binsearch(int x, int v[], int n);
int binsearch_imp(int x, int v[], int n);

int main(int argc, char *argv[]) {
  int v[ARRAY_SIZE];
  for (int i = 0; i < ARRAY_SIZE; i++) {
    v[i] = i;
  }

  int target = 500000;

  clock_t start = clock();
  for (int i = 0; i < ARRAY_SIZE; i++) {
    binsearch(target, v, ARRAY_SIZE);
  }
  clock_t end = clock();
  double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
  printf("Original binary search time: %f seconds\n", time_spent);

  start = clock();
  for (int i = 0; i < ARRAY_SIZE; i++) {
    binsearch_imp(target, v, ARRAY_SIZE);
  }
  end = clock();
  time_spent = (double)(end - start) / CLOCKS_PER_SEC;
  printf("Improved binary search time: %f seconds\n", time_spent);

  /*
   * Report
   *
   * Case iteration: ARRAY_SIZE
   * Original binary search time: 0.063949 seconds
   * Improved binary search time: 0.040695 seconds
   * ~36% faster
   *
   * Case iteration: ARRAY_SIZE * 100
   * Original binary search time: 3.942716 seconds
   * Improved binary search time: 3.703398 seconds
   * ~6% faster
   *
   * Case iteration: ARRAY_SIZE * 1000
   * Original binary search time: 38.979424 seconds
   * Improved binary search time: 37.083207 seconds
   * ~5% faster
   *
   */
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n) {
  int low, high, mid;
  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (x < v[mid])
      high = mid - 1;
    else if (x > v[mid])
      low = mid + 1;
    else /* found match */
      return mid;
  }
  return -1; /* no match */
}

int binsearch_imp(int x, int v[], int n) {
  int low, high, mid;
  low = 0;
  high = n - 1;
  while (low < high) {
    mid = (low + high) / 2;
    if (x <= v[mid])
      high = mid;
    else
      low = mid + 1;
  }

  return v[low] == x ? low : -1;
}

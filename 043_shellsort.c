#include <assert.h>
#include <stdio.h>
#include <string.h>

void shellsort(int v[], int n);

int main(int argc, char *argv[]) {
  // Test Case 1: An already sorted array
  int arr1[] = {1, 2, 3, 4, 5};
  int expected1[] = {1, 2, 3, 4, 5};
  shellsort(arr1, 5);
  assert(memcmp(arr1, expected1, 5 * sizeof(int)) == 0);

  // Test Case 2: A reverse sorted array
  int arr2[] = {5, 4, 3, 2, 1};
  int expected2[] = {1, 2, 3, 4, 5};
  shellsort(arr2, 5);
  assert(memcmp(arr2, expected2, 5 * sizeof(int)) == 0);

  // Test Case 3: An array with duplicate elements
  int arr3[] = {3, 1, 2, 1, 3};
  int expected3[] = {1, 1, 2, 3, 3};
  shellsort(arr3, 5);
  assert(memcmp(arr3, expected3, 5 * sizeof(int)) == 0);

  // Test Case 4: An array with a single element
  int arr4[] = {1};
  int expected4[] = {1};
  shellsort(arr4, 1);
  assert(memcmp(arr4, expected4, 1 * sizeof(int)) == 0);

  // Test Case 5: An array with all elements the same
  int arr5[] = {2, 2, 2, 2, 2};
  int expected5[] = {2, 2, 2, 2, 2};
  shellsort(arr5, 5);
  assert(memcmp(arr5, expected5, 5 * sizeof(int)) == 0);

  // Test Case 6: An empty array
  int arr6[] = {};
  int expected6[] = {};
  shellsort(arr6, 0);
  assert(memcmp(arr6, expected6, 0 * sizeof(int)) == 0);

  // Test Case 7: A large array (performance test)
  int arr7[] = {50, 23, 9, 18, 61, 32};
  int expected7[] = {9, 18, 23, 32, 50, 61};
  shellsort(arr7, 6);
  assert(memcmp(arr7, expected7, 6 * sizeof(int)) == 0);

  printf("All test cases passed!\n");

  return 0;
}

void shellsort(int v[], int n) {
  int gap, current, position, tmp;

  for (gap = n / 2; gap > 0; gap /= 2) {
    for (current = gap; current < n; current++) {
      tmp = v[current];
      for (position = current; position >= gap && v[position - gap] > tmp;
           position -= gap) {
        v[position] = v[position - gap];
      }
      v[position] = tmp;
    }
  }
}

#include <stdio.h>

void shallsort(int v[], int n);

int main(int argc, char *argv[]) { return 0; }

void shallsort(int v[], int n) {
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

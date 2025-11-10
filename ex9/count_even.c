#include <stdio.h>

int count_even(int* arr, int size) {
  int count = 0;
  int *p = arr  // pointer to current element
  for (int i =0; i<size;i++) {
    if (*p % 2 == 0) {
      count++;
    }
    p++;   // move to the next element
  }
  return count;
}

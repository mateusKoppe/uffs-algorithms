#include "stdio.h"

int binary_search (int values[], int size, int search_for) {
  int start = 0;
  int last = size - 1;
  do {
    int pivot = (last + start)/2;
    if (values[pivot] > search_for) {
      last = pivot;
    } else if (values[pivot] < search_for) {
      start = pivot + 1; 
    } else {
      return pivot; 
    }
  } while (start <= last);
  return -1;
}

int main () {
  int values[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int size = sizeof(values)/sizeof(values[0]);
  printf("index: %d\n", binary_search(values, size, 8));
  printf("index: %d\n", binary_search(values, size, 2));
  printf("index: %d\n", binary_search(values, size, 5));
  return 0;
}

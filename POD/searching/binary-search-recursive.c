#include "stdio.h"

int _binary_search (int values[], int search_for, int start, int end) {
  int pivot = (end + start)/2;
  if (start >= end) return -1;
  if (values[pivot] > search_for) {
    end = pivot;
  } else if (values[pivot] < search_for) {
    start = pivot + 1; 
  } else {
    return pivot; 
  }
  return _binary_search(values, search_for, start, end);
}

int binary_search (int values[], int size, int search_for) {
  return _binary_search(values, search_for, 0, size-1);
}

int main () {
  int values[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int size = sizeof(values)/sizeof(values[0]);
  printf("index: %d\n", binary_search(values, size, 8));
  printf("index: %d\n", binary_search(values, size, 2));
  printf("index: %d\n", binary_search(values, size, 5));
  return 0;
}

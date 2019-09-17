#include "stdio.h"

int linear_search (int values[], int size, int search_for) {
  for (int i = 0; i < size; i ++) {
    if (values[i] == search_for) {
      return i; 
    } 
  }
  return -1;
}

int main () {
  int values[] = {10, 4, 3, 7, 2, 1, 9, 8, 6, 5};
  int size = sizeof(values)/sizeof(values[0]);

  printf("Array:\n");

  for (int i = 0; i < size; i ++) {
    printf("%d ", values[i]);
  }
  printf("\n");

  printf("Search for 10: %d\n", linear_search(values, size, 10));
  printf("Search for 7: %d\n", linear_search(values, size, 7));
  printf("Search for 5: %d\n", linear_search(values, size, 5));
  
  return 1;
}

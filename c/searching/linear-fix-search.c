#include "stdio.h"

int linear_fix_search (int values[], int size, int search_for) {
  for (int i = 0; i < size; i ++) {
    if (values[i] == search_for) {
      for (int j = i; j > 0; j--, values[j+1] = values[j]);
      values[0] = search_for;
      return 0;
    } 
  }
  return -1;
}

int print_array(int values[], int size) {
  for (int i = 0; i < size; i ++) {
    printf("%d ", values[i]);
  }
  printf("\n");
}

int main () {
  int values[] = {10, 4, 3, 7, 2, 1, 9, 8, 6, 5};
  int size = sizeof(values)/sizeof(values[0]);

  printf("Array:\n");
  print_array(values, size);
  printf("Search for 10: %d\n", linear_fix_search(values, size, 10));
  print_array(values, size);
  printf("Search for 7: %d\n", linear_fix_search(values, size, 7));
  print_array(values, size);
  printf("Search for 5: %d\n", linear_fix_search(values, size, 5));
  print_array(values, size);
  printf("Search for 2: %d\n", linear_fix_search(values, size, 2));
  print_array(values, size);
  
  return 1;
}

#include <stdio.h>

void bubble_sort(int values[], int length) {
  int is_changed = 0;
  for(int i = 1; i < length; i++) {
    if (values[i-1] > values[i]) {
      int aux = values[i];
      values[i] = values[i-1];
      values[i-1] = aux;
      is_changed = 1;
    }
  }
  if (length > 1 && is_changed) {
    bubble_sort(values, length-1);
  }
}

int main () {
  int values[] = {8, 2, 1, 3, 4, 6, 7, 10, 5, 9};
  int length = sizeof(values) / sizeof(values[0]);
  bubble_sort(values, length);
  for (int i = 0; i < length; i++) {
    printf("%d ", values[i]);
  }
  printf("\n", values);
  return 0;
}
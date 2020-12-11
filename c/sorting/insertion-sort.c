#include <stdio.h>

void insertion_sort(int values[], int length) {
  for (int i = 1; i < length; i++) {
    int value = values[i];
    int j = i - 1;
    while (j >= 0 && value < values[j]) {
      values[j+1] = values[j];
      j = j - 1;
    }
    values[j+1] = value;
  }
}

int main () {
  int values[] = {5, 1, 7, 2, 4, 3, 6, 8, 10, 9};
  int length = 10;
  insertion_sort(values, length);
  for (int i = 0; i < length; i++) {
    printf("%d ", values[i]);
  }
  printf("\n");
  return 1;
}
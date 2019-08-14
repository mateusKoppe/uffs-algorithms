#include <stdio.h>

void shell_sort(int values[], int length) {
  int h = 1;
  do {
    h = h * 3 + 1;
  } while (h < length);

  do {
    h /= 3;
    for (int i = h; i < length; i++) {
      int value = values[i];
      int j = i;
      while (values[j - h] > value && j > h - 1) {
        values[j] = values[j-h];
        j = j - h;
      }
      values[j] = value;
    }
  } while (h != 1);
}

int main () {
  int values[] = {5, 1, 7, 2, 4, 3, 6, 8, 10, 9};
  int length = 10;
  shell_sort(values, length);
  for (int i = 0; i < length; i++) {
    printf("%d ", values[i]);
  }
  printf("\n");
  return 1;
}
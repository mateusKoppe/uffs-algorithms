#include <stdio.h>

void selection_sort(int number_list[], int length){
  for (int i = 0; i < length; i++) {
    int swapped = 0;
    int lowest_number_index = i;
    for(int j = i; j < length; j++) {
      if (number_list[lowest_number_index] > number_list[j]) {
        lowest_number_index = j;
        swapped = 1;
      }
    }
    int aux = number_list[i];
    number_list[i] = number_list[lowest_number_index];
    number_list[lowest_number_index] = aux;
    if (!swapped) {
      return;
    }
  }
}

int main () {
  int number_list[] = {9, 5, 2, 20, 25, 18, 26, 16, 13, 8, 12, 17, 1, 4, 6, 7, 24, 3, 10};

  printf("Before \n");
  for (int i = 0; i < 19; i++) {
    printf("%d: %d\n", i, number_list[i]);
  }

  selection_sort(number_list, 19);

  printf("\n");
  printf("After \n");
  for (int i = 0; i < 19; i++) {
    printf("%d: %d\n", i, number_list[i]);
  }

  return 0;
}


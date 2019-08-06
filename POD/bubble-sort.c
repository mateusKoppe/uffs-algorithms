#include <stdio.h>

void bubble_sort(int number_list[], int length){
  for (int i = length; i > 0; i--) {
    for(int j = 0; j < i; j++) {
      if (number_list[j] > number_list[j+1]) {
        int aux = number_list[j+1];
        number_list[j+1] = number_list[j];
        number_list[j] = aux;
      }
    }
  }
}

int main () {
  int number_list[] = {9, 5, 2, 20, 25, 18, 26, 16, 13, 8, 12, 17, 1, 4, 6, 7, 8, 3, 10};

  printf("Before \n");
  for (int i = 0; i < 19; i++) {
    printf("%d: %d\n", i, number_list[i]);
  }

  bubble_sort(number_list, 19);

  printf("\n");
  printf("After \n");
  for (int i = 0; i < 19; i++) {
    printf("%d: %d\n", i, number_list[i]);
  }

  return 0;
}


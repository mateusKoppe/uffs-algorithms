#include <stdio.h>
#include <stdlib.h>

int shell_sort(int values[], int length) {
  int h = 1;
  int iterations = 0;
  do {
    h = h * 3 + 1;
    iterations++;
  } while (h < length);

  do {
    h /= 3;
    for (int i = h; i < length; i++) {
      int value = values[i];
      iterations++;
      int j = i;
      while (values[j - h] > value && j > h - 1) {
        iterations++;
        values[j] = values[j-h];
        j = j - h;
      }
      values[j] = value;
    }
  } while (h != 1);

  return iterations;
}

int _quick_sort(int number[], int first, int last) {
  int i, j, pivot, temp;
  int iterations = 0;

  if(first < last){
    pivot = first;
    i = first;
    j = last;

    while(i < j){
      while(number[i] <= number[pivot] && i<last) {
        i++;
        iterations++;
      }
      while(number[j] > number[pivot]) {
        j--;
        iterations++;
      }
      if(i<j){
        temp = number[i];
        number[i] = number[j];
        number[j] = temp;
      }
    }

    temp = number[pivot];
    number[pivot] = number[j];
    number[j] = temp;
    iterations = iterations + _quick_sort(number, first, j-1);
    iterations = iterations + _quick_sort(number, j+1, last);
  }
  return iterations;
}

int quick_sort (int values[], int lenght) {
  return _quick_sort(values, 0, lenght-1);
}

void array_print (int array[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

void analyze_shell_sort (int size) {
  int ordenated_list[size];
  int reversed_list[size];
  int random_list[size];

  for (int i = 0; i < size; i++) {
    ordenated_list[i] = i + 1;
    reversed_list[size - (i + 1)] = i + 1;
    random_list[i] = rand() % size;
  }

  printf(" Shell Sort: \n");

  int iterations_ordenated_list = shell_sort(ordenated_list, size);
  printf("  Iterations with ordenated list : %d\n", iterations_ordenated_list);
  int iterations_reversed_list = shell_sort(reversed_list, size);
  printf("  Iterations with reversed list  : %d\n", iterations_reversed_list);
  int iterations_random_list = shell_sort(random_list, size);
  printf("  Iterations with random list    : %d\n", iterations_random_list);
  printf("\n");
}

void analyze_quick_sort (int size) {
  int ordenated_list[size];
  int reversed_list[size];
  int random_list[size];

  for (int i = 0; i < size; i++) {
    ordenated_list[i] = i + 1;
    reversed_list[size - (i + 1)] = i + 1;
    random_list[i] = rand() % size;
  }

  printf(" Quick Sort: \n");

  int iterations_ordenated_list = quick_sort(ordenated_list, size);
  printf("  Iterations with ordenated list : %d\n", iterations_ordenated_list);
  int iterations_reversed_list = quick_sort(reversed_list, size);
  printf("  Iterations with reversed list  : %d\n", iterations_reversed_list);
  int iterations_random_list = quick_sort(random_list, size);
  printf("  Iterations with random list    : %d\n", iterations_random_list);
  printf("\n");
}

int compare_array_size(int size) {
  printf("%d Indexes ----------------\n", size);
  analyze_shell_sort(size);
  analyze_quick_sort(size);
}

int main () {
  compare_array_size(5000);
  compare_array_size(25000);
  compare_array_size(50000);
  compare_array_size(100000);
}

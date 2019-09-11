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

void _quick_sort_swap (int *i, int *j) {
  int aux = *i;
  *i = *j;
  *j = aux;
}

int _quick_sort_partition (int values[], int low, int high) {
  int pivot = values[high];
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++) { 
    if (values[j] < pivot) {
      i++;
      _quick_sort_swap(&values[i], &values[j]);
    }
  }

  _quick_sort_swap(&values[i + 1], &values[high]);
  return (i + 1);
}

void _quick_sort (int values[], int low, int high) {
  if (low < high) {
    int pi = _quick_sort_partition(values, low, high);

    _quick_sort(values, low, pi - 1);
    _quick_sort(values, pi + 1, high);
  }
}

int quick_sort (int values[], int lenght) {
  _quick_sort(values, 0, lenght-1);
  return 1;
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

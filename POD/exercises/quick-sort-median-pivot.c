#include <stdio.h>

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


void _quick_sort_medians_pivot (int values[], int lenght) {
  int start = 0,
    middle = (int) lenght/2,
    end = lenght-1;

  if (values[start] > values[middle]) {
    _quick_sort_swap(&values[start], &values[middle]);
  }
  if (values[middle] > values[end]) {
    _quick_sort_swap(&values[middle], &values[end]);
  }
}

void _quick_sort (int values[], int low, int high) {
  if (low < high) {
    int pi = _quick_sort_partition(values, low, high);

    _quick_sort(values, low, pi - 1);
    _quick_sort(values, pi + 1, high);
  }
}

void quick_sort (int values[], int lenght) {
  _quick_sort_medians_pivot(values, lenght);
  _quick_sort(values, 0, lenght-1);
}

int main () {
  int values[] = {9, 2, 1, 5, 10, 4, 6, 3, 7, 8};
  int lenght = sizeof(values) / sizeof(values[0]);

  quick_sort(values, lenght);

  for (int i = 0; i < lenght; i++)
  {
    printf("i -> %d\n", values[i]);
  }
}
#include <stdio.h>
#include <stdlib.h>


void _merge_sort_merge (int values[], int begin, int middle, int end) {
  int size = end - begin +1;
  int aux_begin = begin;
  int aux_middle = middle+1;
  int aux = 0;
  int *aux_values = (int*) malloc(size * sizeof(int));


  while (aux_begin <= middle && aux_middle <= end) {
    if (values[aux_begin] < values[aux_middle]) {
      aux_values[aux] = values[aux_begin];
      aux_begin++;
    } else {
      aux_values[aux] = values[aux_middle];
      aux_middle++;
    }
    aux++;
  } 

  while (aux_begin <= middle) {
    aux_values[aux] = values[aux_begin];
    aux++;
    aux_begin++;
  }

  while (aux_middle <= end) {
    aux_values[aux] = values[aux_middle];
    aux++;
    aux_middle++;
  }

  for (aux = begin; aux <= end; aux++) {
    values[aux] = aux_values[aux-begin];
  }

  free(aux_values);
}

void _merge_sort(int values[], int begin, int end) {
  if (begin < end) {
    int middle = (begin+end)/2;

    _merge_sort(values, begin, middle);
    _merge_sort(values, middle+1, end);
    _merge_sort_merge(values, begin, middle, end);
  }
}

void merge_sort(int values[], int end) {
  _merge_sort(values, 0, end - 1);
}

int main () {
  int values[] = {5, 1, 7, 2, 4, 3, 6, 8, 10, 9};
  int length = 10;
  merge_sort(values, length);
  for (int i = 0; i < length; i++) {
    printf("%d ", values[i]);
  }
  printf("\n");
  return 1;
}
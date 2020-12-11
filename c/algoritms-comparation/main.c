#include <stdio.h>
#include <stdlib.h>
#include <time.h>

clock_t start, stop;

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

void swap(int array[], int i1, int i2) {
  int aux = array[i1];
  array[i1] = array[i2];
  array[i2] = aux;
}

int quicksort_iterations = 0;
int _quick_sort(int array[], int l, int r) {
  int pivot, x, y;
  x = l;
  y = r;
  pivot = array[(int)((x+y)/2)];
  do {
    while (array[x] < pivot && x < r) {
      x++;
      quicksort_iterations++;
    }
    while (array[y] > pivot && y > l) {
      y--;
      quicksort_iterations++;
    }
    if (x <= y) {
      swap(array,x,y);
      x++;
      y--;
    }
  } while(x <= y);
  if(l < y) _quick_sort(array, l, y);
  if(x < r) _quick_sort(array, x, r);
  return quicksort_iterations;
}


int merge_iterations = 0;
void _merge_sort_merge (int values[], int begin, int middle, int end) {
  int size = end - begin +1;
  int aux_begin = begin;
  int aux_middle = middle+1;
  int aux = 0;
  int *aux_values = (int*) malloc(size * sizeof(int));


  while (aux_begin <= middle && aux_middle <= end) {
    merge_iterations++;
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
    merge_iterations++;
    aux_values[aux] = values[aux_begin];
    aux++;
    aux_begin++;
  }

  while (aux_middle <= end) {
    merge_iterations++;
    aux_values[aux] = values[aux_middle];
    aux++;
    aux_middle++;
  }

  for (aux = begin; aux <= end; aux++) {
    merge_iterations++;
    values[aux] = aux_values[aux-begin];
  }

  free(aux_values);
}

int _merge_sort(int values[], int begin, int end) {
  if (begin < end) {
    int middle = (begin+end)/2;

    _merge_sort(values, begin, middle);
    _merge_sort(values, middle+1, end);
    _merge_sort_merge(values, begin, middle, end);
  }
  return merge_iterations;
}

int merge_sort(int values[], int end) {
  merge_iterations = 0;
  return _merge_sort(values, 0, end - 1);
}

int quick_sort (int values[], int lenght) {
  quicksort_iterations = 0;
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

  start = clock();
  int iterations_ordenated_list = shell_sort(ordenated_list, size);
  stop = clock();
  printf("  Iterations with ordenated list : %d\n", iterations_ordenated_list);
  printf("  Time with ordenated list : %.5fs\n", (double) (stop-start)/CLOCKS_PER_SEC);
  start = clock();
  int iterations_reversed_list = shell_sort(reversed_list, size);
  stop = clock();
  printf("  Iterations with reversed list  : %d\n", iterations_reversed_list);
  printf("  Time with ordenated list : %.5fs\n", (double) (stop-start)/CLOCKS_PER_SEC);
  start = clock();
  int iterations_random_list = shell_sort(random_list, size);
  stop = clock();
  printf("  Iterations with random list    : %d\n", iterations_random_list);
  printf("  Time with ordenated list : %.5fs\n", (double) (stop-start)/CLOCKS_PER_SEC);
  printf("\n");
}

void analyze_merge_sort (int size) {
  int ordenated_list[size];
  int reversed_list[size];
  int random_list[size];

  for (int i = 0; i < size; i++) {
    ordenated_list[i] = i + 1;
    reversed_list[size - (i + 1)] = i + 1;
    random_list[i] = rand() % size;
  }

  printf(" Merge Sort: \n");

  start = clock();
  int iterations_ordenated_list = merge_sort(ordenated_list, size);
  stop = clock();
  printf("  Iterations with ordenated list : %d\n", iterations_ordenated_list);
  printf("  Time with ordenated list : %.5fs\n", (double) (stop-start)/CLOCKS_PER_SEC);
  start = clock();
  int iterations_reversed_list = merge_sort(reversed_list, size);
  stop = clock();
  printf("  Iterations with reversed list  : %d\n", iterations_reversed_list);
  printf("  Time with ordenated list : %.5fs\n", (double) (stop-start)/CLOCKS_PER_SEC);
  start = clock();
  int iterations_random_list = merge_sort(random_list, size);
  stop = clock();
  printf("  Iterations with random list    : %d\n", iterations_random_list);
  printf("  Time with ordenated list : %.5fs\n", (double) (stop-start)/CLOCKS_PER_SEC);
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

  start = clock();
  int iterations_ordenated_list = quick_sort(ordenated_list, size);
  stop = clock();
  printf("  Iterations with ordenated list : %d\n", iterations_ordenated_list);
  printf("  Time with ordenated list : %.5fs\n", (double) (stop-start)/CLOCKS_PER_SEC);
  start = clock();
  int iterations_reversed_list = quick_sort(reversed_list, size);
  stop = clock();
  printf("  Iterations with reversed list  : %d\n", iterations_reversed_list);
  printf("  Time with ordenated list : %.5fs\n", (double) (stop-start)/CLOCKS_PER_SEC);
  start = clock();
  int iterations_random_list = quick_sort(random_list, size);
  stop = clock();
  printf("  Iterations with random list    : %d\n", iterations_random_list);
  printf("  Time with ordenated list : %.5fs\n", (double) (stop-start)/CLOCKS_PER_SEC);
  printf("\n");
}

int compare_array_size(int size) {
  printf("%d Indexes ----------------\n", size);
  analyze_shell_sort(size);
  analyze_quick_sort(size);
  analyze_merge_sort(size);
}

int main () {
  compare_array_size(5000);
  compare_array_size(25000);
  compare_array_size(50000);
  compare_array_size(100000);
}

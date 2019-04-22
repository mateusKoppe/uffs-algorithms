#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int push_back_to_array(int x, int v[], int n) {
  v = realloc(v, sizeof(int*) * (n + 1));
  if (v == 0) return 0;
  v[n] = x;
  return 1;
}

int erase_from_array(int x, int v[], int n) {
  int count = 0, i, j;
  for (i = 0; i < n; i++) {
    if (v[i] == x) {
      for (j = i; j < n - count; j++) {
        v[j] = v[j + 1];
      }
      count++;
    }
  }
  v = realloc(v, sizeof(int*) * (n - count));
  if (v == 0) return 0;
  return 1;
}

int main (void) {
  int *prime_numbers;
  int size = 0;
  int i;

  prime_numbers = malloc(0);
  push_back_to_array(1, prime_numbers, size++);
  push_back_to_array(2, prime_numbers, size++);
  push_back_to_array(3, prime_numbers, size++);
  push_back_to_array(5, prime_numbers, size++);
  push_back_to_array(7, prime_numbers, size++);
  push_back_to_array(9, prime_numbers, size++);
  push_back_to_array(11, prime_numbers, size++);
  push_back_to_array(13, prime_numbers, size++);
  push_back_to_array(15, prime_numbers, size++);
  push_back_to_array(17, prime_numbers, size++);
  push_back_to_array(19, prime_numbers, size++);
  push_back_to_array(21, prime_numbers, size++);
  push_back_to_array(9, prime_numbers, size++);
  push_back_to_array(23, prime_numbers, size++);

  printf("prime numbers: ");
  for (i = 0; i < size; i++) {
    printf("%d ", prime_numbers[i]);
  }
  printf("\n");

  erase_from_array(9, prime_numbers, size--);
  size--;
  erase_from_array(15, prime_numbers, size--);
  erase_from_array(21, prime_numbers, size--);

  printf("prime numbers: ");
  for (i = 0; i < size; i++) {
    printf("%d ", prime_numbers[i]);
  }
  printf("\n");

  free(prime_numbers);
}
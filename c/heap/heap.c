#include <stdlib.h>
#include <stdio.h>

#define get_father(n) (((n)-1)/2)
#define get_left(n) (2*(n)+1)
#define get_right(n) (2*(n)+2)

typedef struct {
  int size;
  int max;
  int* list;
} heap;

static void heap_swap (heap* h, int n1, int n2) {
  int aux = h->list[n1];
  h->list[n1] = h->list[n2];
  h->list[n2] = aux;
}

static void heap_up (heap *h, int n) {
  while (n > 0) {
    int father = get_father(n);
    if (h->list[father] > h->list[n]) {
      break;
    }
    heap_swap(h, father, n);
    n = father;
  }
}

static void heap_down (heap* h, int n) {
  int left_child = get_left(n);
  while (left_child < h->size) {
    int right_child = get_right(n);
    if (right_child < h->size
      && h->list[right_child] > h->list[left_child] 
    ) {
      left_child = right_child;
    }
    if (h->list[left_child] < h->list[n]) {
      break;
    }
    heap_swap(h, n, left_child);
    n = left_child;
    left_child = get_left(n);
  }
}

heap* heap_init (int max) {
  heap *h = (heap*) malloc(sizeof(heap));
  h->size = 0;
  h->max = max;
  h->list = (int*) malloc(h->max * sizeof(int));
  return h;
}

void heap_free (heap *h) {
  free(h->list);
  free(h);
}

void heap_insert (heap* h, int value) {
  h->list[h->size] = value;
  h->size++;
  heap_up(h, h->size - 1);
}

int heap_extract(heap* h) {
  int root = h->list[0];
  h->list[0] = h->list[h->size - 1];
  heap_down(h, 0);
  h->size--;
  return root;
}

int main () {
  heap* h = heap_init(10);
  srand(0);
  for (int i = 0; i < 10; i++) {
    heap_insert(h, rand() % 100);
  }
  for (int i = 0; i < 10; i++) {
    printf("%d\n", h->list[i]);
  }
}
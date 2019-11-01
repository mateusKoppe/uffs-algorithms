#include <stdio.h>

int main () {
  FILE* file = fopen("storage/products.txt", "r");
  float total = 0;

  char name[80];
  int quantity;
  float price;

  while (fscanf(file, "%s %d %f", name, &quantity, &price) != -1) {
    total += quantity * price;
    printf("%s %.02f\n", name, quantity * price);
  }
  
  printf("total: %.02f\n", total);

  return 0;
}
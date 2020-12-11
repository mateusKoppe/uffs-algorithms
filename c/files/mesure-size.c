#include <stdio.h>
#include <string.h>

int main () {
  char filename[20];

  printf("Enter the file path:");
  scanf("%s", filename);

  FILE* file = fopen(filename, "rt");

  if (file == NULL) {
    printf("\nFile access error");
    return 1;
  }

  char c;
  int lines = 1, size = 0;
  while ((c = fgetc(file)) != EOF) {
    size++;
    if (c == '\n') {
      lines++;
    }
  }

  printf("file: %s\n", filename);
  printf("  size: %d\n", size);
  printf("  lines: %d\n", lines);

  return 0;
}
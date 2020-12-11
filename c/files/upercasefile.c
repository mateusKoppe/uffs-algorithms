#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main () {
  char filename[20];
  char filename_target[20];

  printf("Enter the file to read: ");
  scanf("%s", filename);
  printf("Enter the file to write: ");
  scanf("%s", filename_target);

  FILE* file = fopen(filename, "rt");
  FILE* file_target = fopen(filename_target, "w");

  if (file == NULL) {
    printf("\nFile access error");
    return 1;
  }

  char c;
  int lines = 1, size = 0;
  while ((c = fgetc(file)) != EOF) {
    char a = toupper(c);
    fputc(a, file_target);
  }

  printf("Created %s!\n", filename_target);

  return 0;
}
#include <stdio.h>
#include <string.h>

int main () {
  char filename[20];

  printf("Enter the first file path: ");
  scanf("%s", filename);

  FILE* file1 = fopen(filename, "rt");

  printf("Enter the second file path: ");
  scanf("%s", filename);

  FILE* file2 = fopen(filename, "rt");

  if (file1 == NULL || file2 == NULL) {
    printf("\nFile access error");
    return 1;
  }

  printf("Enter the result file path: ");
  scanf("%s", filename);

  FILE* file_result = fopen(filename, "w");
  
  char line[256];
  int lines = 1, size = 0;
  while (fgets(line, 256, file1) != NULL) {
    fprintf(file_result, "%s", line);
  }

  fclose(file1);

  fprintf(file_result, "%s", "\n");

  while (fgets(line, 256, file2) != NULL) {
    fprintf(file_result, "%s", line);
  }
  
  fclose(file2);
  fclose(file_result);

  return 0;
}
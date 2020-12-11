#include <stdio.h>
#include <string.h>

void concat_files_into (FILE* file1, FILE* file2, FILE* result);

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
  
  concat_files_into(file1, file2, file_result);

  fclose(file1);
  fclose(file2);
  fclose(file_result);

  return 0;
}

void concat_files_into (FILE* file1, FILE* file2, FILE* result) {
  char line[256];
  while (fgets(line, 256, file1) != NULL) {
    fprintf(result, "%s", line);
  }
  fprintf(result, "%s", "\n");
  while (fgets(line, 256, file2) != NULL) {
    fprintf(result, "%s", line);
  }
}
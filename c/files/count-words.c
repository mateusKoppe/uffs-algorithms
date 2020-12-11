#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]) {
  char *filename;

  if (argc >= 2) {
    filename = argv[1];
  } else {
    printf("Enter the file path: ");
    char input[80];
    scanf("%s", input);
    filename = input;
  }

  FILE* file = fopen(filename, "rt");

  if (file == NULL) {
    printf("\nFile access error\n");
    return 1;
  }

  char word[256];
  int words = 0;
  while (fscanf(file, "%s", word) != -1) {
    words++;
  }

  printf("words: %d\n", words);

  return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char letter, *p_msg, **p_lines;
  int *p_msg_size;
  int i = 0, j = 0;
  int lines_amount = 1, actual_line = 0;

  p_msg = malloc(0);
  p_lines = malloc(sizeof(int));
  p_lines[0] = p_msg;
  p_msg_size = malloc(sizeof(int));
  p_msg_size[0] = 0;
  while (scanf("%c", &letter) != EOF) {
    if (!strncmp(&letter, "\n", 1)) {
      lines_amount++;
      actual_line++;
      p_msg = malloc(0);
      p_msg_size = realloc(p_msg_size, lines_amount * sizeof(int));
      p_msg_size[actual_line] = 0;
      p_lines = realloc(p_lines, lines_amount * sizeof(int));
      p_lines[actual_line] = &p_msg;
    } else {
      p_msg_size[actual_line]++;
      p_msg = realloc(p_msg, p_msg_size[actual_line] * sizeof(char));
      p_lines[actual_line] = p_msg;
      p_msg[p_msg_size[actual_line] - 1] = letter;
    }
  }

  for(i = 0; i < lines_amount; i++){
    printf("%s", p_lines[i]);
    free(p_lines[i]);
  }

  free(p_msg_size);
  free(p_lines);
  return 0;
}


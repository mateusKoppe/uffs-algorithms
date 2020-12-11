#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char *msg, **lines, letter;
  int msg_size = 0, lines_size = 1;
  int i;

  msg = (char *) malloc(0);
  lines = (char **) malloc(sizeof(char**));
  lines[0] = msg;

  while (scanf("%c", &letter) != EOF) {
    if (!strncmp(&letter, "\n", 1)) {
      if (msg_size > 0) {
        msg_size = 0;
        lines_size++;
        msg = (char *) malloc(0);
        lines = realloc(lines, sizeof(char**) * lines_size);
        lines[lines_size -1] = msg;
      }
    } else {
      msg_size++;
      msg = realloc(msg, sizeof (char*) * msg_size);
      msg[msg_size - 1] = letter;
      lines[lines_size - 1] = msg;
    }
  }

  printf("\n");
  for (i = 0; i < lines_size; i++) {
    printf(">%s<\n", lines[i]);
    free(lines[i]);
  }
  free(lines);

  return 0;
}
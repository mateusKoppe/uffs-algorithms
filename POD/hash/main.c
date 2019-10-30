#include <stdio.h>
#include "./studant.h"

void screen();
void add_studant();
void list_studants();
void search_studant();
void free_studants();

studant** studant_list;
int studant_count = 0;
int studant_size;

int hash (int registration) {
  return registration % studant_size;
}

int main () {
  printf("How many studants do you want to save?\n");
  scanf("%d", &studant_size);
  studant_list = malloc(sizeof(studant) * studant_size);
  screen();
  return 0;
}

void screen () {
  printf("Menu:\n");
  printf("[1] - Add studant\n");
  printf("[2] - List studants\n");
  printf("[3] - Search studant\n");
  printf("[4] - Exit\n");
  int option;
  scanf("%d", &option);

  switch (option) {
    case 1:
      add_studant();
      break;
    case 2:
      list_studants();
      break;
    case 3:
      search_studant();
      break;
    case 4:
      free_studants();
      break;
    default:
      printf("Invalid option, try again.\n");
      screen();
  }
}

void add_studant () {
  studant* new_studant = studant_create();
  if (studant_count >= studant_size) {
    printf("Size limit, you cannot create another studant.\n");
    screen();
    return;
  }
  printf("New studant--\n");
  printf("Registration: ");
  scanf(" %d", &new_studant->registration);
  printf("Name: ");
  scanf(" %s", &new_studant->name);
  printf("E-mail: ");
  scanf(" %s", &new_studant->email);
  printf("Class: ");
  scanf(" %c", &new_studant->clas);
  int is_created = 0;
  int i = 0;
  int h = hash(new_studant->registration);
  while (1) {
    if (h >= studant_size - 1) i = hash(new_studant->registration) * -1;
    h = hash(new_studant->registration) + i;
    if (studant_list[h] == NULL)
      break;
    i++;
  }
  studant_list[h] = new_studant;
  studant_count++;
  screen();
}

void list_studants () {
  printf("Studants list--\n");
  for (int i = 0; i < studant_size; i++) {
    studant* s = studant_list[i];
    if (s != NULL)
      printf("%02d | %s (%d)\n", i, s->name, s->registration);
    else 
      printf("%02d | --\n", i);
  }
  screen();
}

void search_studant () {
  int registration; 
  printf("Studant data--\n");
  printf("Enter registration to search: ");
  scanf("%d", &registration);
  int h = hash(registration);
  int i = 0, attemp = 0;
  while (1) {
    if (h >= studant_size - 1) i = hash(registration) * -1;
    if (attemp >= studant_size) {
      h = -1;
      break;
    }
    h = hash(registration) + i;
    if (studant_list[h] != NULL && studant_list[h]->registration == registration)
      break;
    i++;
    attemp++;
  }
  if (h != -1) {
    studant* s = studant_list[h];
    printf("Registration: %d\n", s->registration);
    printf("Name: %s\n", s->name);
    printf("E-mail: %s\n", s->email);
    printf("Class: %c\n", s->clas);
  } else {
    printf("Not found.\n");
  }
  screen();
}

void free_studants () {
  for (int i = 0; i < studant_size; i++) {
    free(studant_list[i]);
  }
  free(studant_list);
}

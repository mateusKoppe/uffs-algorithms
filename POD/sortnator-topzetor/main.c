#include <stdio.h>
#include "./list.h"

void view ();
void menu ();
void view_add_number ();
void view_remove_number ();
void view_show_list ();
void view_show_list_size ();

int option;
list number_list;

int main () {
  printf("- = = = = = = = == = = = = = = = -\n");
  printf("-       Sortnator Topzetor       -\n");
  printf("-      Just sort your stuff      -\n");
  printf("- = = = = = = = == = = = = = = = -\n");
  view();
}

void view () {
  printf("Options:\n");
  printf("[1] - Add number\n");
  printf("[2] - Remove number\n");
  printf("[3] - Show list\n");
  printf("[4] - Show list size\n");
  printf("[5] - Quit\n");
  menu();
}

void view_add_number () {
  printf("Enter a number to add it in the list: ");
  int entered_number;
  scanf("%d", &entered_number);
  if (list_insert(&number_list, entered_number)) {
    printf("Value %d added successfully\n", entered_number);
    view();
  } else {
    printf("Error to add %d\n", entered_number);
  }
}

void view_remove_number () {
  printf("Enter a number to remove it: ");
  int entered_number;
  scanf("%d", &entered_number);
  list_remove(&number_list, entered_number);
  printf("Number %d was removed.\n", entered_number);
  view();
}

void view_show_list () {
  list_print(&number_list);
  view();
}

void view_show_list_size () {
}

void menu () {
  scanf("%d", &option);
  switch (option) {
    case 1:
      view_add_number();
      break;
    case 2:
      view_remove_number();
      break;
    case 3:
      view_show_list();
      break;
    case 4:
      view_show_list_size();
      break;
    case 5:
      list_free(&number_list);
      break;
    default:
      printf("Invalid command, please, try again...\n");
      menu();
  } 
}

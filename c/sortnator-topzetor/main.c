#include <stdio.h>
#include <stdlib.h>
#include "./list.h"
#include "./listsort.h"

void view ();
void menu ();
void clean_screen();
void action_order_bubble ();
void action_order_selection ();
void action_add_number ();
void action_remove_number ();

int option;
list number_list;

int main () {
  clean_screen();
  list_construct(&number_list);
  printf("- = = = = = = = == = = = = = = = -\n");
  printf("-       Sortnator Topzetor       -\n");
  printf("-      Just sort your stuff      -\n");
  printf("- = = = = = = = == = = = = = = = -\n");
  view();
}

void clean_screen() {
  system("@cls||clear");
}

void view () {
  printf("\n");
  list_print(&number_list);
  printf("--------------------------\n");
  printf("List size: %d\n\n", number_list.size);
  printf("Options: \n");
  printf(" [1] - Add number\n");
  printf(" [2] - Remove number\n");
  printf(" [3] - Order (Bubble Sort)\n");
  printf(" [4] - Order (Selection Sort)\n");
  printf(" [5] - Quit\n");
  menu();
}

void action_add_number () {
  clean_screen();
  printf("Enter a number to add it in the list: ");
  int entered_number;
  scanf("%d", &entered_number);
  if (list_insert(&number_list, entered_number)) {
    clean_screen();
    printf("Value %d added successfully\n", entered_number);
    view();
  } else {
    printf("Error to add %d\n", entered_number);
  }
}

void action_remove_number () {
  clean_screen();
  printf("Enter a number to remove it: ");
  int entered_number;
  scanf("%d", &entered_number);
  int removed_items = list_remove(&number_list, entered_number);
  clean_screen();
  printf("%d item(s) were removed.\n", removed_items);
  view();
}

void action_order_bubble () {
  clean_screen();
  listsort_bubble_sort(&number_list);
  printf("List sorted with bubble sort.\n");
  view();
}

void action_order_selection () {
  clean_screen();
  listsort_selection_sort(&number_list);
  printf("List sorted with selection sort.\n");
  view();
}

void menu () {
  scanf("%d", &option);
  switch (option) {
    case 1:
      action_add_number();
      break;
    case 2:
    clean_screen();
      action_remove_number();
      break;
    case 3:
      action_order_bubble();
      break;
    case 4:
      action_order_selection();
      break;
    case 5:
      list_free(&number_list);
      break;
    default:
      printf("Invalid command, please, try again...\n");
      menu();
  } 
}

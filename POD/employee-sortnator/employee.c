#include <stdio.h>
#include <string.h>
#include "./employee.h"

void employee_init (employee *empl) {
  strcpy(empl->name, "");
  empl->salary = 0;
}

void employee_print (employee *empl) {
  printf("employee ----\n");
  printf("name  : %s\n", empl->name);
  printf("salary: %.2f\n", empl->salary);
  printf("-------------\n");
}
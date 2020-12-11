#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./employee.h"

void employees_initialize (employee employees[], int length) {
  for (int i = 0; i < length; i++) {
    employee_init(&employees[i]);
  }
}

void employees_fill (employee employees[], int index, char name[], float salary) {
  employee *empl = &employees[index];
  employee_init(empl);
  strcpy(empl->name, name);
  empl->salary = salary;
}

void _quick_sort_swap (employee *i, employee *j) {
  employee aux = *i;
  *i = *j;
  *j = aux;
}

int _quick_sort_partition (employee employees[], int low, int high) {
  employee *pivot = &employees[high];
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++) { 
    if (employees[j].salary > pivot->salary) {
      i++;
      _quick_sort_swap(&employees[i], &employees[j]);
    }
  }

  _quick_sort_swap(&employees[i + 1], &employees[high]);
  return (i + 1);
}

void _quick_sort (employee employees[], int low, int high) {
  if (low < high) {
    int pi = _quick_sort_partition(employees, low, high);

    _quick_sort(employees, low, pi - 1);
    _quick_sort(employees, pi + 1, high);
  }
}

void employees_sort (employee employees[], int length) {
  _quick_sort(employees, 0, length-1);
}

void employees_print_richest(employee employees[], int how_many) {
  for (int i = 0; i < how_many; i++) {
    employee_print(&employees[i]);
  }
}

int main () {
  employee employees[10];
  employees_initialize(employees, 10);
  employees_fill(employees, 0, "Charlie Brown", 1300.5);
  employees_fill(employees, 1, "Pericles", 1100);
  employees_fill(employees, 2, "Marcelo Camelo", 1200);
  employees_fill(employees, 3, "Zeca Little Pagode", 500);
  employees_fill(employees, 4, "Little Kevin", 100);
  employees_fill(employees, 5, "Scorpions", 800);
  employees_fill(employees, 6, "Ryu", 200);
  employees_fill(employees, 7, "Megaman", 400);
  employees_fill(employees, 8, "Any and Ta", 1300);
  employees_fill(employees, 9, "Mario", 700);
  employees_sort(employees, 10);
  employees_print_richest(employees, 5);
  return 0;
}
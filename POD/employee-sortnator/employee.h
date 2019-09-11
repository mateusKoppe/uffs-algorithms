#ifndef _EMPLOYEE
#define _EMPLOYEE

typedef struct employee employee;
struct employee {
  char name[85];
  float salary;
};

void employee_init (employee *empl);
void employee_print (employee *empl);

#endif
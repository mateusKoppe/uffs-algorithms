#ifndef _STUDANT
#define _STUDANT

#include <stdlib.h>

typedef struct studant studant;
struct studant {
  int registration;
  char name[80];
  char email[50];
  char clas;
};

studant* studant_create () {
  return malloc(sizeof(studant));
}

#endif

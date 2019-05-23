#ifdef _SLLIST
#define _SLLIST

typedef struct _node {
  int key;
  struct _node *next;
} node;

typedef struct {
  node *head;
} sllist;

void sllist_init (sllist *list) 

int _node sllist_insert(sllist *list, int key)

void _node sllist_erase(sllist *list, int key)

void _node sllist_free(sllist *list)

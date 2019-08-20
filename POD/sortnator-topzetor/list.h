#ifndef _list
#define _list

typedef struct _list_node {
  struct _list_node *next;
  struct _list_node *prev;
  int value;
} list_node;

typedef struct {
  list_node *head;
  int size; 
} list;

void list_construct (list *l_list);
list_node* list_get_node (list *l_list, int value);
list_node* list_get_last_node (list *l_list);
list_node* list_insert (list *l_list, int value);
void list_print (list *l_list);
void list_remove (list *l_list, int value);
void list_free (list *l_list);

#endif
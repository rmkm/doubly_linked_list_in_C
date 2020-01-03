#ifndef _DOUBLY_LINKED_LIST_
#define _DOUBLY_LINKED_LIST_

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    const char *data;
    struct node* next;
    struct node* prev;
} node_t;

node_t *dll_new();
void dll_insert_after(node_t *prev, const char *data);
void dll_print(node_t *head);

#endif

#ifndef _DOUBLY_LINKED_LIST_
#define _DOUBLY_LINKED_LIST_

typedef struct node {
	const char *data;
	struct node* next;
	struct node* prev;
} node_t;

void dll_insert_after(node_t *prev, const char *data);

#endif
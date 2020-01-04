#ifndef _LINKED_LIST_
#define _LINKED_LIST_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    const char *data;
    struct node *next;
    struct node *prev;
} node_t;

typedef struct list {
    struct node *dummy;
} list_t;

list_t *list_new();
int list_len(list_t *list);
void append(list_t *list, const char *data);
void prepend(list_t *list, const char *data);
void insert_before(node_t *prev, const char *data);
void insert_after(node_t *prev, const char *data);
bool find_node(list_t *list, const char *data);
node_t *get_node(list_t *list, const char *data);
node_t *get_node_by_index(list_t *list, int i);
const char *get_data_by_index(list_t *list, int i);
void remove_head(list_t *list);
void remove_tail(list_t *list);
void remove_node(list_t *list, const char *data);
void remove_by_index(list_t *list, int i);
void remove_list(list_t *list);
void print_list(list_t *list);
void print_list_reverse(list_t *list);

#endif

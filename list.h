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
int list_count(list_t *list, const char *data);
void list_append(list_t *list, const char *data);
void list_prepend(list_t *list, const char *data);
void list_insert(list_t *list, int i, const char *data);
bool list_find(list_t *list, const char *data);
int list_index(list_t *list, const char *data);
const char *list_pop(list_t *list);
const char *list_push(list_t *list);
const char *list_data(list_t *list, int i);
void list_clear(list_t *list);
void list_remove(list_t *list, const char *data);
void list_remove_by_index(list_t *list, int i);
void list_free(list_t *list);
void list_print(list_t *list);
void list_print_reverse(list_t *list);

#endif

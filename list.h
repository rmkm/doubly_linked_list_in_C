#ifndef _LINKED_LIST_
#define _LINKED_LIST_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    const char *value;
    struct node *next;
    struct node *prev;
} node_t;

typedef struct list {
    struct node *dummy;
} list_t;

// create new list
list_t *list_new();

// Returns the length of the list
int list_len(list_t *list);

// Returns the number of elements with the specified value
int list_count(list_t *list, const char *value);

// Adds an element at the end of the list
void list_append(list_t *list, const char *value);

// Adds an element at the start of the list
void list_prepend(list_t *list, const char *value);

// Adds an element at the specified position
void list_insert(list_t *list, int i, const char *value);

// Returns if the specified value is in the list
bool list_find(list_t *list, const char *value);

// Returns the position of the specified value
int list_index(list_t *list, const char *value);

// Removes the element at the specified position
const char *list_pop(list_t *list, int i);

// Returns the value at the specified position
const char *list_value(list_t *list, int i);

// Returns the copy (malloc) the given list
list_t *list_copy(list_t *list);

// Appends all the elements of 'src' to 'dest'
// Returns the pointer to 'dest'
list_t *list_concat(list_t *dest, list_t *src);

// Removes all the elements from the list
void list_clear(list_t *list);

// Removes the first item with the specified value
void list_remove(list_t *list, const char *value);

// Free the list
void list_free(list_t *list);

// print out the list
void list_print(list_t *list);

// print out the list in reverse order
void list_print_reverse(list_t *list);

#endif

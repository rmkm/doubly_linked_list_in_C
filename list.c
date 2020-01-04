#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "list.h"

list_t *list_new() {
    list_t *new_list = (list_t *)malloc(sizeof(list_t));
    new_list->dummy = (node_t *)malloc(sizeof(node_t));
    new_list->dummy->data = NULL;
    new_list->dummy->next = new_list->dummy;
    new_list->dummy->prev = new_list->dummy;
    return new_list;
}

int list_len(list_t *list) {
    int len = 0;
    node_t *current = list->dummy;
    while (current->next->data != NULL) {
        current = current->next;
        len++;
    }
    return len;
}

void append(list_t *list, const char *data) {
    node_t *current = list->dummy;
    while (current->next->data != NULL) {
        current = current->next;
    }
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = list->dummy;
    new_node->prev = current;
    current->next = new_node;
    list->dummy->prev = new_node;
}

void prepend(list_t *list, const char *data) {
    node_t *head = list->dummy->next;
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = head;
    new_node->prev = list->dummy;
    list->dummy->next = new_node;
    head->prev = new_node;
}

void insert_before(node_t *next, const char *data) {
    node_t *prev = next->prev;
    node_t *new_node = (node_t *)malloc(sizeof(node_t)); 
    new_node->data = data; 
    new_node->next = next; 
    new_node->prev = next->prev; 
    prev->next = new_node; 
    next->prev = new_node;
}

void insert_after(node_t *prev, const char *data) {
    node_t *next = prev->next;
    node_t *new_node = (node_t *)malloc(sizeof(node_t)); 
    new_node->data = data; 
    new_node->next = prev->next; 
    new_node->prev = prev; 
    prev->next = new_node; 
    next->prev = new_node;
}

bool find_node(list_t *list, const char *data) {
    node_t *current = list->dummy;
    while (current->next->data != NULL) {
        current = current->next;
        if (!strcmp(data, current->data)) {
            return true;
        }
    }
    return false;
}

node_t *get_node(list_t *list, const char *data) {
    node_t *current = list->dummy;
    while (current->next->data != NULL) {
        current = current->next;
        if (!strcmp(data, current->data)) {
            return current;
        }
    }
    return NULL;
}

node_t *get_node_by_index(list_t *list, int i) {
    if (i < 0) {
        return NULL;
    }
    int len = list_len(list);
    if (len - 1 < i) {
        return NULL;
    }
    node_t *current = list->dummy;
    for (int j = 0; j < i + 1; j++) {
        current = current->next;
    }
    return current;
}

const char *get_data_by_index(list_t *list, int i) {
    if (i < 0) {
        return NULL;
    }
    int len = list_len(list);
    if (len - 1 < i) {
        return NULL;
    }
    node_t *current = list->dummy;
    for (int j = 0; j < i + 1; j++) {
        current = current->next;
    }
    return current->data;
}

void remove_head(list_t *list) {
    node_t *head = list->dummy->next;
    if (head->data == NULL) { // list is empty
        return;
    }
    node_t *next = head->next;
    list->dummy->next = next;
    next->prev = list->dummy;
    free(head);
}

void remove_tail(list_t *list) {
    node_t *tail = list->dummy->prev;
    if (tail->data == NULL) { // list is empty
        return;
    }
    node_t *prev = tail->prev;
    prev->next = list->dummy;
    list->dummy->prev = prev;
    free(tail);
}

void remove_node(list_t *list, const char *data) {
    node_t *current = list->dummy;
    while (current->next->data != NULL) {
        current = current->next;
        if (!strcmp(data, current->data)) {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            free(current);
        }
    }
}

void remove_by_index(list_t *list, int i) {
    if (i < 0) {
        return;
    }
    int len = list_len(list);
    if (len - 1 < i) {
        return;
    }
    node_t *current = list->dummy;
    for (int j = 0; j < i + 1; j++) {
        current = current->next;
    }
    current->prev->next = current->next;
    current->next->prev = current->prev;
    free(current);
}

void remove_list(list_t *list) {
    node_t *current = list->dummy;
    while (current->next->data != NULL) {
        current = current->next;
        free(current);
    }
    free(list->dummy);
    free(list);
}

void print_list(list_t *list) {
    node_t *current = list->dummy;
    while (current->next->data != NULL) {
        current = current->next;
        printf("%s\n", current->data);
    }
}

void print_list_reverse(list_t *list) {
    node_t *current = list->dummy;
    while (current->prev->data != NULL) {
        current = current->prev;
        printf("%s\n", current->data);
    }
}

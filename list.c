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

int list_count(list_t *list, const char *data) {
    int count = 0;
    node_t *current = list->dummy;
    while (current->next->data != NULL) {
        current = current->next;
        if (!strcmp(data, current->data)) {
            count++;
        }
    }
    return count;
}

void list_append(list_t *list, const char *data) {
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

void list_prepend(list_t *list, const char *data) {
    node_t *head = list->dummy->next;
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = head;
    new_node->prev = list->dummy;
    list->dummy->next = new_node;
    head->prev = new_node;
}

void list_insert(list_t *list, int i, const char *data) {
    int len = list_len(list);
    if (i < 0 || len - 1 < i) {
        i = len; // same as append
    }
    node_t *current = list->dummy->next;
    for (int j = 0; j < i; j++) {
        current = current->next;
    }
    node_t *next = current;
    node_t *prev = current->prev;
    node_t *new_node = (node_t *)malloc(sizeof(node_t)); 
    new_node->data = data; 
    new_node->next = next; 
    new_node->prev = prev; 
    prev->next = new_node; 
    next->prev = new_node;
    return;
}

bool list_find(list_t *list, const char *data) {
    node_t *current = list->dummy;
    while (current->next->data != NULL) {
        current = current->next;
        if (!strcmp(data, current->data)) {
            return true;
        }
    }
    return false;
}

int list_index(list_t *list, const char *data) {
    int i = 0;
    node_t *current = list->dummy;
    while (current->next->data != NULL) {
        current = current->next;
        if (!strcmp(data, current->data)) {
            return i;
        }
        i++;
    }
    return -1;
}

const char *list_pop(list_t *list, int i) {
    int len = list_len(list);
    if (i < 0 || len - 1 < i) {
        return NULL;
    }
    node_t *current = list->dummy;
    for (int j = 0; j < i + 1; j++) {
        current = current->next;
    }
    const char *data = current->data;
    current->prev->next = current->next;
    current->next->prev = current->prev;
    free(current);
    return data;
}

const char *list_data(list_t *list, int i) {
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

list_t *list_copy(list_t *list) {
    list_t *new_list = list_new();
    node_t *current = list->dummy;
    while (current->next->data != NULL) {
        current = current->next;
        list_append(new_list, current->data);
    }
    return new_list;
}

list_t *list_concat(list_t *dest, list_t *src) {
    node_t *current = src->dummy;
    while (current->next->data != NULL) {
        current = current->next;
        list_append(dest, current->data);
    }
    return dest;
}

void list_clear(list_t *list) {
    node_t *current = list->dummy;
    while (current->next->data != NULL) {
        current = current->next;
        free(current);
    }
    list->dummy->next = list->dummy;
    list->dummy->prev = list->dummy;
}

void list_remove(list_t *list, const char *data) {
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

void list_free(list_t *list) {
    node_t *current = list->dummy;
    while (current->next->data != NULL) {
        current = current->next;
        free(current);
    }
    free(list->dummy);
    free(list);
}

void list_print(list_t *list) {
    node_t *current = list->dummy;
    printf("[");
    while (current->next->data != NULL) {
        current = current->next;
        printf("'%s'", current->data);
        if (current->next->data != NULL) {
            printf(", ");
        }
    }
    printf("]\n");
}

void list_print_reverse(list_t *list) {
    node_t *current = list->dummy;
    printf("[");
    while (current->prev->data != NULL) {
        current = current->prev;
        printf("'%s'", current->data);
        if (current->prev->data != NULL) {
            printf(", ");
        }
    }
    printf("]\n");
}

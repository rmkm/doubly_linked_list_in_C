#include <stdio.h>
#include <stdlib.h>
#include "dll.h"

node_t *dll_new() {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = NULL;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void dll_insert_after(node_t *prev, const char *data) {

    if (prev == NULL) { 
        printf("the given previous node cannot be NULL"); 
        return; 
    } 

    node_t *new_node = (node_t *)malloc(sizeof(node_t)); 
    prev->next = new_node; 
    new_node->prev = prev; 
    new_node->next = prev->next; 
    new_node->data = data; 
    printf("dll_insert_after\n");
  
    if (new_node->next != NULL) { 
        new_node->next->prev = new_node;
    }

}

void dll_print(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        printf("%s\n", current->data);
        current = current->next;
    }
}

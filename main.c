#include <stdio.h>  
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

int main() {  
    
    list_t *list1, *list2;
    int len, count;
    bool found;
    const char *value;

    list1 = list_new();
    list_append(list1, "apple");
    list_append(list1, "banana");
    list_append(list1, "cat");
    list_prepend(list1, "dog");
    list_prepend(list1, "elephant");
    list_prepend(list1, "frog");
    list_insert(list1, 1, "dog");
    printf("list1: ");
    list_print(list1);

    len = list_len(list1);
    printf("Length of list1: %d\n", len);

    found = list_find(list1, "apple");
    if (found) {
        printf("list1 contains 'apple'\n");
    }
    found = list_find(list1, "goat");
    if (!found) {
        printf("list1 does not contain 'goat'\n");
    }

    count = list_count(list1, "dog");
    printf("The number of element 'dog': %d\n", count);

    value = list_pop(list1, 0);
    printf("Remove the element at 0 of list1: '%s'\n", value);

    list2 = list_new();
    list_append(list2, "goat");
    list_append(list2, "hamburger");
    list_append(list2, "ice cream");
    printf("list2: ");
    list_print(list2);

    printf("Concatenate list1 and list2\n");
    list_concat(list1, list2);
    printf("list1: ");
    list_print(list1);

    list_free(list1);
    list_free(list2);

    return 0;  
}

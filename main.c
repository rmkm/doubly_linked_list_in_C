#include <stdio.h>  
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

int main() {  
    
    int len, i, count;
    bool ret;
    node_t *node;
    const char *data;

    list_t *list = list_new();
    len = list_len(list);
    printf("length %d\n", len);
    list_append(list, "30");
    list_append(list, "40");
    list_append(list, "50");
    list_append(list, "100");
    list_prepend(list, "20");
    list_prepend(list, "10");
    list_prepend(list, "10");
    list_prepend(list, "10");

    count = list_count(list, "200");
    printf("count of 200 %d\n", count);
    //list_clear(list);
    list_insert(list, 100, "1");
    list_print(list);
    i = list_index(list, "100");
    printf("index of 100: %d\n", i);
    //node = get_node_by_index(list, 1);
    //printf("index 1 data %s\n", node->data);
    data = list_pop(list);
    printf("pop data %s\n", data);
    data = list_push(list);
    printf("push data %s\n", data);
    len = list_len(list);
    printf("length %d\n", len);
    bool match = list_find(list, "30");
    if (match) {
        printf("30 found\n");
    }
    //node = get_node(list, "40");
    //insert_before(node, "35");
    //insert_after(node, "45");
    //printf("node->data %s\n", node->data);
    list_remove(list, "30");
    list_remove_by_index(list, 10);
    list_print(list);
    printf("\n");
    list_print_reverse(list);
    list_free(list);
    return 0;  
}

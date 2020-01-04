#include <stdio.h>  
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

int main() {  
    
    int len;
    node_t *node;
    const char *data;

    list_t *list = list_new();
    len = list_len(list);
    printf("length %d\n", len);
    append(list, "30");
    append(list, "40");
    append(list, "50");
    append(list, "100");
    prepend(list, "20");
    prepend(list, "10");
    //node = get_node_by_index(list, 1);
    //printf("index 1 data %s\n", node->data);
    data = get_data_by_index(list, 1);
    printf("index 1 data %s\n", data);
    len = list_len(list);
    printf("length %d\n", len);
    bool match = find_node(list, "30");
    if (match) {
        printf("30 found\n");
    }
    node = get_node(list, "40");
    insert_before(node, "35");
    insert_after(node, "45");
    printf("node->data %s\n", node->data);
    remove_node(list, "30");
    remove_by_index(list, 10);
    print_list(list);
    printf("\n");
    print_list_reverse(list);
    remove_list(list);
    return 0;  
}

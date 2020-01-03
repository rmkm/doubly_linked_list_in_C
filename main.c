#include <stdio.h>  
#include <stdlib.h>
#include "dll.h"

int main() {  

    node_t *head = dll_new();

    dll_insert_after(head, "30");
    dll_insert_after(head, "40");
    dll_insert_after(head, "50");
  
    dll_print(head);

    return 0;  
}
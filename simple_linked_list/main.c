#include "simple_linked_list.h"
#include <stdio.h>

DEFINE_SLLIST_WITH_TYPE(int);
INITIALIZE_SLLIST_WITH_TYPE(int);
int_sllist_t intlinked;

void print_int_sllist(int_sllist_t intlinked);

int main() {
    initialize_int_sllist(&intlinked);
    for (int i = 0; i < 20; i++)
        insert_tail_int_sllist(&intlinked, 2*i + 1, i);
    insert_head_int_sllist(&intlinked, 99, 89);
    print_int_sllist(intlinked);
    delete_head_int_sllist(&intlinked);
    delete_tail_int_sllist(&intlinked);
    print_int_sllist(intlinked);
    return 0;
}

void print_int_sllist(int_sllist_t intlinked) {
    int_node_t *node = intlinked.head;
    printf("[ ");
    do {
        printf("(%d, %d) ", node->key, node->data);
        node = node->next;
    }while(node != NULL);
    printf(" ]\n");

}

#include <stdio.h>
#include "dynamic_list_tool.h"

DEFINE_DYNAMIC_LIST_WITH_TYPE(int);
INITIALIZE_DYNAMIC_LIST_WITH_TYPE(int);
int_list_t intlist;

void int_list_print(int_list_t *inlist);
void int_list_stat(int_list_t *intlist, char * name);

int testarr[] = {1,2,3,4,5};

int main(){
    /*Print list before initialization*/
    int_list_stat(&intlist, "Before Initialization");

    /*Print list after initialization*/
    initialize_int_list(&intlist, 5);
    int_list_stat(&intlist, "After Initialization");

    /*Print list after Clean*/
    clear_int_list(&intlist);
    int_list_stat(&intlist, "After Clear");

    /*Print list after appending testarr*/
    push_back_arr_int_list(&intlist, testarr, 5);
    int_list_stat(&intlist,"After Appending an Array");

    insert_arr_int_list(&intlist, 1, testarr, 5);
    int_list_stat(&intlist,"After Inseting an Array at index 1");

    printf("Integer at the start: %d\n", *begin_int_list(&intlist));
    printf("Integer at the end: %d\n", *end_int_list(&intlist));
    printf("Integer at the index %d : %d\n", 3, at_int_list(&intlist, 3));

    shrink_to_fit_int_list(&intlist);
    int_list_stat(&intlist,"After Shrink");

    for (int i = 0; i < 200; i++)
        push_back_int_list(&intlist, i);
    int_list_stat(&intlist,"After 200 Elements");

    for (int i = 0; i < 200; i++)
        pop_back_int_list(&intlist);
    int_list_stat(&intlist,"After evaluating pop_back 200 times");

    erase_int_list(&intlist, 3);
    int_list_stat(&intlist,"After Erasing the int at index 3");

    insert_int_list(&intlist, 3, 45);
    int_list_stat(&intlist,"After Inserting 45 to index 3");

    resize_int_list(&intlist, 10);
    setlen_int_list(&intlist, 10);
    int_list_stat(&intlist,"After Resizing to Size 10");

    clear_int_list(&intlist);
    return 0;
}


void int_list_print(int_list_t *inlist){
    printf("[ ");
    for (int i = 0; i < size_int_list(inlist); i++)
        printf("%d ", at_int_list(inlist, i));
    printf("]\n");
}

void int_list_stat(int_list_t *intlist, char* name){
    printf("%s:\n", name);
    printf("SIZE: %d\n", size_int_list(intlist));
    printf("CAPACITY: %d\n", capacity_int_list(intlist));
    printf("HEAD POINTER: %ld\n", (long int)data_int_list(intlist));
    printf("LIST ITSELF: ");
    int_list_print(intlist);
    printf("\n");
}

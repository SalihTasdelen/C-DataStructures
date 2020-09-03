#ifndef _DYNLIST_H
#define _DYNLIST_H
#include <stdlib.h>

#define DEFINE_LIST(type) \
    typedef struct type##_list { \
        type *data; \
        int length; \
    } type##_list_t;

#define INITIALIZE_LIST_TYPE(type) \
    void initialize_##type##_list(type##_list_t *list, int length) { \
        list->length = length; \
        list->data = malloc(length * sizeof(type)); \
    } \
    void free_##type##_list(type##_list_t *list) { \
        free(list->data); \
        list->length = 0; \
    } \
    \
    void resize_##type##_list(type##_list_t *list, int length) { \
       list->data = realloc(list->data, length * sizeof(type)); \
       list->length = length; \
    } \
    \
    type get_##type##_list(type##_list_t *list, int index) { \
        return list->data[index]; \
    } \
    \
    type *return_##type##_list(type##_list_t *list, int index) { \
        return &list->data[index]; \
    } \
    \
    void set_##type##_list(type##_list_t *list, int index, type value) { \
        list->data[index] = value; \
    } \
    \
    void append_##type##_list(type##_list_t *list, type element) { \
        list->data = realloc(list->data, ++list->length * sizeof(type)); \
        list->data[list->length-1] = element; \
    } \
    type pop_##type##_list(type##_list_t *list) { \
        type retval = list->data[list->length - 1]; \
        list->data = realloc(list->data, --list->length * sizeof(type)); \
        return retval; \
    } \
    void remove_##type##_list(type##_list_t *list, int index) { \
        for (int i = index; i < (list->length - 1); i++) \
            list->data[i] = list->data[i+1]; \
        list->data = realloc(list->data, --list->length * sizeof(type)); \
    } \
    void insert_##type##_list(type##_list_t *list, int index, type value) { \
        list->data = realloc(list->data, ++list->length * sizeof(type)); \
        for (int i = index + 1; i < (list->length - 1); i++) \
            list->data[i+1] = list->data[i]; \
        list->data[index] = value; \
    } \
    \
    int length_##type##_list(type##_list_t *list) { \
        return list->length; \
    } \
    \
    type peek_##type##_list(type##_list_t *list) { \
        return list->data[list->length - 1]; \
    }
    
#endif
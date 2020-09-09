#ifndef _DYNLIST_H
#define _DYNLIST_H
#include <stdlib.h>
#define BLOCK_SIZE 25

#define DEFINE_DYNAMIC_LIST_WITH_TYPE(type) \
    typedef struct type##_list { \
        type *data; \
        int length; \
        int allocated; \
    } type##_list_t;

#define INITIALIZE_DYNAMIC_LIST_WITH_TYPE(type) \
    void initialize_##type##_list(type##_list_t *list, int length) { \
        list->length = length; \
        list->allocated = length + (BLOCK_SIZE - length%BLOCK_SIZE); \
        list->data = malloc(list->allocated * sizeof(type)); \
    } \
    void clear_##type##_list(type##_list_t *list) { \
        free(list->data); \
        list->length = 0; \
        list->allocated = 0; \
    } \
    void setlen_##type##_list(type##_list_t *list, int size) { \
        list->length = size; \
    } \
    \
    type *begin_##type##_list(type##_list_t *list) { \
        return list->data; \
    } \
    type *end_##type##_list(type##_list_t *list) { \
        return list->data + list->length; \
    } \
    const type *cbegin_##type##_list(type##_list_t *list) { \
        return (const type*)(list->data); \
    } \
    const type *cend_##type##_list(type##_list_t *list) { \
        return (const type*)(list->data + list->length); \
    } \
    int size_##type##_list(type##_list_t *list) { \
        return list->length; \
    } \
    void resize_##type##_list(type##_list_t *list, int length) { \
        list->allocated = length + (BLOCK_SIZE - length%BLOCK_SIZE); \
        list->data = realloc(list->data, list->allocated * sizeof(type)); \
    } \
    int capacity_##type##_list(type##_list_t *list) { \
        return list->allocated; \
    } \
    void shrink_to_fit_##type##_list(type##_list_t *list) { \
        list->allocated = list->length; \
        list->data = realloc(list->data, list->allocated * sizeof(type)); \
    } \
    \
    type at_##type##_list(type##_list_t *list, int index) { \
        return list->data[index]; \
    } \
    type front_##type##_list(type##_list_t *list) { \
        return list->data[0]; \
    } \
    type back_##type##_list(type##_list_t *list) { \
        return list->data[list->length - 1]; \
    } \
    type *data_##type##_list(type##_list_t *list) { \
        return list->data; \
    } \
    void push_back_##type##_list(type##_list_t *list, type value) { \
        if (list->length == list->allocated){ \
            list->allocated += (BLOCK_SIZE - list->allocated%BLOCK_SIZE); \
            list->data = realloc(list->data, list->allocated * sizeof(type)); \
        } \
        list->data[list->length++] = value; \
    } \
    void pop_back_##type##_list(type##_list_t *list) { \
        if ((list->allocated - list->length) > BLOCK_SIZE) { \
            list->allocated -= (BLOCK_SIZE - list->allocated%BLOCK_SIZE); \
            list->data = realloc(list->data, list->allocated * sizeof(type)); \
        } \
        list->length--; \
    } \
    \
    void insert_##type##_list(type##_list_t *list, int index, type value) { \
        if (list->length == list->allocated){ \
            list->allocated += (BLOCK_SIZE - list->allocated%BLOCK_SIZE); \
            list->data = realloc(list->data, list->allocated * sizeof(type)); \
        } \
        list->length++; \
        for (int i = (list->length - 1); i >= index; i--) \
            list->data[i + 1] = list->data[i]; \
        list->data[index] = value; \
    } \
    void erase_##type##_list(type##_list_t *list, int index) { \
        for (int i = index; i < (list->length - 1); i++) \
            list->data[i] = list->data[i+1]; \
        if ((list->allocated - list->length) > BLOCK_SIZE) { \
             list->allocated -= (BLOCK_SIZE - list->allocated%BLOCK_SIZE); \
             list->data = realloc(list->data, list->allocated * sizeof(type)); \
        } \
        list->length--; \
    } \
    type *return_##type##_list(type##_list_t *list, int index) { \
        return &list->data[index]; \
    } \
    \
    void set_##type##_list(type##_list_t *list, int index, type value) { \
        list->data[index] = value; \
    } \
    void push_back_arr_##type##_list(type##_list_t *list, type *arr, int size){ \
        if ((size + list->length) >= list->allocated){ \
            list->allocated += size; \
            list->allocated += (BLOCK_SIZE - (list->allocated%BLOCK_SIZE)); \
            list->data = realloc(list->data, list->allocated * sizeof(type)); \
        } \
        for (int i = 0; i < size; i++){ \
            list->data[list->length + i] = arr[i]; \
        } \
        list->length += size; \
    } \
    void insert_arr_##type##_list(type##_list_t *list, int index, type *arr, int size) { \
        if ((size + list->length >= list->allocated)) { \
            list->allocated += size; \
            list->allocated += (BLOCK_SIZE - (list->allocated%BLOCK_SIZE)); \
            list->data = realloc(list->data, list->allocated * sizeof(type)); \
        } \
        for (int i = list->length - 1; i >= index; i--) \
            list->data[i + size] = list->data[i]; \
        for (int i = 0; i < size; i++) \
            list->data[i + index] = arr[i]; \
        list->length += size; \
    }

#endif

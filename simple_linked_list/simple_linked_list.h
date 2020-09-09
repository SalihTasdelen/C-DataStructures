#ifndef _SIMPLE_LINKED_LIST_H
#define _SIMPLE_LINKED_LIST_H
#include <stdlib.h>

#define DEFINE_SLLIST_WITH_TYPE(type) \
    typedef struct type##_node { \
        type data; \
        int key; \
        struct type##_node *next; \
    } type##_node_t; \
    \
    typedef struct type##_sllist { \
        int length; \
        type##_node_t *head; \
    } type##_sllist_t;

#define INITIALIZE_SLLIST_WITH_TYPE(type) \
    void initialize_##type##_sllist(type##_sllist_t *list) { \
        list->length = 0; \
        list->head = malloc(sizeof(type##_node_t)); \
        list->head->next = NULL; \
    } \
    void insert_head_##type##_sllist(type##_sllist_t *list, type val, int key) { \
        type##_node_t *newh = malloc(sizeof(type##_node_t)); \
        newh->data = val; \
        newh->key = key; \
        newh->next = list->head; \
        list->head = newh; \
        list->length++; \
    } \
    void delete_head_##type##_sllist(type##_sllist_t *list) { \
        type##_node_t *todel = list->head; \
        list->head = list->head->next; \
        free(todel); \
        list->length--; \
    } \
    void insert_tail_##type##_sllist(type##_sllist_t *list, type val, int key) { \
        type##_node_t *newt = malloc(sizeof(type##_node_t)); \
        newt->data = val; \
        newt->key = key; \
        newt->next = NULL; \
        if (list->length == 0){ \
            list->head = newt; \
            list->length++; \
            return; \
        } \
        type##_node_t *tmp = list->head; \
        while(tmp->next != NULL) { \
            tmp = tmp->next; \
        } \
        tmp->next = newt; \
        list->length++; \
    } \
    void delete_tail_##type##_sllist(type##_sllist_t *list) { \
        type##_node_t *newt = list->head; \
        list->length--; \
        for (int i = 0; i < list->length - 1; i++) \
            newt = newt->next; \
        newt->next = NULL; \
    }

#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct __node {                   
    int value;
    struct __node *next;
} node_t;

void list_add_node_t(node_t **list, node_t *node_t) {
    node_t->next = *list;
    *list = node_t;
}

void list_concat(node_t **left, node_t *right) {
    while (*left)
        left = &((*left)->next);
    *left = right;
}

int list_is_sorted(node_t *list);

void list_display(node_t *list);

node_t *list_init(node_t *list, long num);

void list_free(node_t **list);

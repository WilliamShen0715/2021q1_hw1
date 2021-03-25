#include "quicksort.h"

void quicksort(node_t **list);

void quicksort(node_t **list)
{
    if (!*list)
        return;

    node_t *pivot = *list;
    int value = pivot->value;
    node_t *p = pivot->next;
    pivot->next = NULL;

    node_t *left = NULL, *right = NULL;
    while (p) {
        node_t *n = p;
        p = p->next;
        list_add_node_t(n->value > value ? &right : &left, n);
    }

    quicksort(&left);
    quicksort(&right);

    node_t *result = NULL;
    list_concat(&result, left);
    list_concat(&result, pivot); list_concat(&result, right);
    *list = result;
}

void list_display(node_t *list) {
    while (list) {
        printf("%d ", list->value);
        list = list->next;
    }
    printf("\n");
}

node_t *list_init(node_t *list, long num){
    node_t *tmp = malloc(sizeof(node_t));
    if (!tmp){
        return list;
    }
    tmp->value = num;
    tmp->next = list;
    return tmp;
}

void list_free(node_t **list){
    node_t *tmp;
    while (*list)
    {
        tmp = *list;
        *list = (*list)->next;
        free(tmp);
    }
}
int list_is_sorted(node_t *list) {
    int first = 1;
    int value;
    while (list) {
        if (first) {
            value = list->value;
            first = 0;
        } else {
            if (list->value < value)
                return 0;
            value = list->value;
        }
        list = list->next;
    }
    return 1;
}
int main(int argc, char **argv) {
    size_t count = 100;

    node_t *list = NULL;
    srand(time(NULL));
    while (count--) list = list_init(list, rand() % 100);

	printf("origin:\n");
    list_display(list);
    quicksort(&list);
    printf("sorted:\n");
    list_display(list);

    if (!list_is_sorted(list))
        return EXIT_FAILURE;

    list_free(&list);
    return EXIT_SUCCESS;
}

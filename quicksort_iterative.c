#include "quicksort.h"

void quicksort_iterative(node_t **list);

void quicksort_iterative(node_t **list)
{
    #define  MAX_LEVELS  1000
    if (!*list)
        return;
    int i = 0, j = 0;
    node_t *stack[MAX_LEVELS];
    node_t *sorted;
    sorted = NULL;
    stack[0] = *list;
    while(i>=0 && i<MAX_LEVELS){
        if(!stack[i]){
            i--;
            continue;
        }
        if(!stack[i]->next){
            stack[i]->next = sorted;
            sorted = stack[i];
            i--;
            continue;
        }
        node_t *pivot = stack[i];
        int value = pivot->value;
        node_t *p = pivot->next;
        pivot->next = NULL;
        node_t *left = NULL, *right = NULL;
        while (p) {
            node_t *n = p;
            p = p->next;
            list_add_node_t(n->value > value ? &right : &left, n);
        }
        stack[i] = left;
        stack[i+1] = pivot;
        stack[i+2] = right;
        i +=2;
    }
    *list = sorted;
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

int main(int argc, char **argv) {
    size_t count = 100;

    node_t *list = NULL;
    srand(time(NULL));
    while (count--) list = list_init(list, rand() % 100);

	printf("origin:\n");
    list_display(list);
    quicksort_iterative(&list);
    printf("sorted:\n");
    list_display(list);

    if (!list_is_sorted(list))
        return EXIT_FAILURE;

    list_free(&list);
    return EXIT_SUCCESS;
}

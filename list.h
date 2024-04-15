#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int pos;
    char kierunek;
    struct node *next;
} node;

typedef struct {
    node *head;
    int size;
} node_list;

node_list *init_list(bool empty) {
    if (empty)
        return NULL;
    node_list *list = malloc(sizeof(node_list));
    if (list == NULL) {
        fprintf(stderr, "Błąd alokacji pamięci!\n");
        exit(1);
    }
    list->head = NULL;
    list->size = 0;
    return list;
}

void add_node(node_list *list, int pos, char kierunek) {
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL) {
        fprintf(stderr, "Błąd alokacji pamięci!\n");
        exit(1);
    }
    new_node->pos = pos;
    new_node->kierunek = kierunek;
    new_node->next = list->head;
    list->head = new_node;
    list->size++;
}

void free_list(node_list *list) {
    if (list == NULL)
        return;
    node *current = list->head;
    while (current != NULL) {
        node *next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

void print_list(node_list *list,FILE *out) {
    if (list == NULL)
        return;
    node *current = list->head;
    while (current != NULL) {
        fprintf(out,"(%d, %d) ", current->pos, current->kierunek);
        current = current->next;
    }
    fprintf(out,"\n");
}
int get_direction(node_list *list, int curpos) {
    if (list == NULL || list->head == NULL) {
        fprintf(stderr, "Lista jest pusta!\n");
        exit(1);
    }
    
    node *current = list->head;
    while (current != NULL) {
        if (current->pos == curpos) {
            return current->kierunek;
        }
        current = current->next;
    }
    
    fprintf(stderr, "Brak elementu o pozycji %d w liście!\n", curpos);
    exit(1);
}


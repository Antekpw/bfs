#include "parents.h"
#include <stdlib.h>
#include <stdio.h>
stos insert(stos t,int x, int y){
        stos nowy = malloc(sizeof*(nowy));
        nowy->x = x;
        nowy->y = y;
        nowy->next = t;
        return nowy;
    
}
void printstos_to_FILE(stos t,FILE *out){
        stos temp = t;
        int i = 0;
    while (temp != NULL) {
        fprintf(out,"(%d, %d) ", temp->x, temp->y);
        temp = temp->next;
        if(i==10){
            break;
        }
        i++;
    }
}
stos remove_last(stos t) {
    if (t == NULL || t->next == NULL) {
        // Jeśli lista jest pusta lub zawiera tylko jeden element, zwolnij pamięć dla tego elementu i zwróć NULL
        free(t);
        return NULL;
    }

    stos temp = t;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    // Zwolnij pamięć dla ostatniego elementu
    free(temp->next);
    // Ustaw wskaźnik na NULL, aby oznaczyć nowy koniec listy
    temp->next = NULL;
    return t;
}

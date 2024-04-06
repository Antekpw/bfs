#include "parents.h"
#include <stdio.h>
int main(){
    stos t = NULL;
    t = insert(t,3,2);
    t = insert(t,8,9);
    t = insert(t,99,100);
    stos temp = t;
    while(temp!=NULL){
        printf("(%d,%d) ", temp->x, temp->y);
        temp = temp->next;
    }
    printf("\n");
}
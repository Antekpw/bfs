#include "queue.h"
#include <stdlib.h>
#include <stdio.h>


queue enqueue(queue q,int x, int y){
    if(q==NULL){
        queue nowy = malloc(sizeof *nowy);
        nowy->x = x;
        nowy->y = y;
        nowy->next = q;
        return nowy;
    }
    queue l = q;
    while(l->next != NULL){
        l = l->next;
    }
    l->next = malloc(sizeof *(l->next));
    l->next->x = x;
    l->next->y = y;
    l->next->next = NULL;
    return q;
    
}
queue dequeue(queue q,int *x, int *y){
    if(q==NULL){
        fprintf(stderr,"pusta kolejka!\n");
        return NULL;
    }
    queue temp = q;
    *x = temp->x;
    *y = temp->y;
    q = q->next;
    free(temp);
    
    return q;
}
void readqueue(queue q){
    if(q==NULL){
        fprintf(stderr,"kolejka pusta!\n");
    }
    queue temp = q;
    while (temp != NULL) {
        printf("(%d, %d) ", temp->x, temp->y);
        temp = temp->next;
        
    }
    
}
void free_queue(queue q) {
    if(q==NULL){
    //    fprintf(stderr,"cos sie popsulo");            coś nie działa
    }
    while (q != NULL) {
        queue temp = q;
        q = q->next;
        free(temp);
    }
}

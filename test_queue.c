#include "queue.h"
#include <stdio.h>

int main() {
    // Inicjalizacja pustej kolejki
    queue q = NULL;
    int x0 = 0;
    int y0 =1;
    // Dodawanie kilku elementów do kolejki
    q = enqueue(q, x0, y0);
    

    // Wyświetlanie zawartości kolejki
    printf("Zawartość kolejki:\n");
    readqueue(q);

    // Usuwanie kilku elementów z kolejki i wyświetlanie ich wartości
    int x, y;
    int i = 0;
    while(1){
        i++;
        if(i==4){
            break;
        }
    q = dequeue(q, &x, &y);
    printf("Usunięty element: (%d, %d)\n", x, y);
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
 for(int i=0;i<4;i++){   
int newx = x+dx[i];
int newy = y+dy[i];
q = enqueue(q,newx,newy);
 }
readqueue(q);
    }
    return 0;
}

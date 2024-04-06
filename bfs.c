#include "bfs.h"
#include "queue.h"
#include "parents.h"
#include "readFile.h"
#include <stdio.h>
int bfs(FILE *in){
    int x0, y0, xk, yk,w,h;
    read(in,&x0,&y0,&xk,&yk,&w,&h);
    printf("xk=%d, yk =%d\n",xk,yk);
    queue q = NULL;
    stos t = NULL;
    markVisited(in,x0,y0, w); // oznacz jako odwiedzony w pliku 
    q = enqueue(q,x0,y0);
    int x, y;
    int j =0;
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    int ile_odwiedzonych = 0;
    while(q!=NULL){
        q = dequeue(q, &x, &y);
        if(x==xk && y == yk){
            break;
            
            return 0;
        }

        for(int i=0;i<4;i++){   
            int newx = x+dx[i];
            int newy = y+dy[i];
            if((newx<0 || newx>=w) || (newy<0 || newy>=h) ){
                continue;
            }
            if(isInvalidPosition(in,newx,newy,w)==1){
                continue; // to znaczy ze albo sciana albo juz odwiedzony czyli wsm mozna zwolnic pamiec dla rodzica i go usunac-jezeli plusik
            }
            markVisited(in,newx,newy, w);
            q = enqueue(q,newx,newy);
            t = insert(t,x,y); // wstawianie na stos rodzica(poprzedniego punktu);
            ile_odwiedzonych++;
        }
        
    }
    FILE *out = fopen("plik","w");
    if(out==NULL){
        fprintf(stderr,"blad z plikiem");
    }
    printstos_to_FILE(t,out);
   readqueue(q);
   printf("ile_odwiedzonych = %d\n",ile_odwiedzonych);
}

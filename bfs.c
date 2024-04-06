#include "bfs.h"
#include "queue.h"
#include "parents.h"
#include "readFile.h"
int bfs(FILE *in){
    int x0, y0, xk, yk,w,h;
    read(in,&x0,&y0,&xk,&yk,&w,&h);
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
                continue;
            }
            markVisited(in,newx,newy, w);
            q = enqueue(q,newx,newy);
            ile_odwiedzonych++;
        }
        
    }
   readqueue(q);
   printf("ile_odwiedzonych = %d\n",ile_odwiedzonych);
}

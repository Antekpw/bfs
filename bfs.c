#include "bfs.h"
#include "queue.h"
#include "parents.h"
#include "readFile.h"
#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// stop on node (bool) 
void bfs(FILE *in,int x0,int y0,int xk, int yk, int w, int h, bool stop_on_node){
    queue q = NULL;
    
    markVisited(in,x0,y0, w); // oznacz jako odwiedzony w pliku 
    q = enqueue(q,x0,y0);
    int x, y;
    /*int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};*/
    int dx[4] = {0,1,0,-1};
    int dy[4] = {-1,0,1,0};
    int ile_odwiedzonych = 0;
    int ile_node = 0;
    int stop = 0;
    int path_len = 0;
    node_list* nodes = init_list(stop_on_node);
    
    while(q!=NULL && stop == 0){
        q = dequeue(q, &x, &y);   
        markVisited(in,x,y, w);

        if(x==xk && y == yk){
            break;
            exit(1);
        }
        for(int i=0;i<4;i++){   
            int newx = x+dx[i];
            int newy = y+dy[i];
            if((newx<0 || newx>=w) || (newy<0 || newy>=h) ){
                continue;
            }
            if(checkifdeadend(in,newx,newy,w)==0){
                /*printf("punkt (%d,%d) jest slepym zaulkiem\n",newx,newy);
                fbs(in,newx,newy,w,h); // zalej */
                continue;
            }
            if(isInvalidPosition(in,newx,newy,w)==1){   
                //printf("punkt (%d,%d) jest albo sciana albo plusem albo N",newx,newy);
                continue; 
            }
            if((check_if_node(newx,newy,in,w))==0){
              //  printf("punkt (%d,%d) jest rozwidleniem stawiam N\n",newx,newy);      
                ile_node++;
                if (stop_on_node){
                    stop = 1;
                }else{
                    markNode(newx,newy,in,w);
                    int pos = newy*w + newx;
                    add_node(nodes,pos,(i+2) %4 );
                }
            } 

            q = enqueue(q,newx,newy);
            ile_odwiedzonych++;
            }   
        }
    free_queue(q);
  
    
    if(stop_on_node==false){
        queue q2 = NULL;
        markPath(xk,yk,in,w); // tu moze byc problem
        q2 = enqueue(q2,xk,yk);
        int x2,y2;
        int stop2 = 0;
        while(q2!=NULL && stop2==0){
            
            q2 = dequeue(q2,&x2,&y2);

            if((check_if_node_marked(x2,y2,in,w))==0){
                int curpos = y2 * w + x2;
                int dir = get_direction(nodes,curpos);
               //printf("dir=%d\n",dir);
                // 0 gora 1 prawo 2 dol 3 lewo
                markPath(x2,y2,in,w);
                x2 += dx[dir];
                y2 +=dy[dir];
                markPath(x2,y2,in,w);
                q2 = enqueue(q2,x2,y2);
                continue;
            }
            for(int i=0;i<4;i++){   
                int newx2 = x2+dx[i];
                int newy2 = y2+dy[i];
                if(newx2==x0 && newy2 ==y0){
                     markPath(x0,y0,in,w);
                    stop2 = 1;
                }
                if((newx2<0 || newx2>w) || (newy2<0 || newy2>h) ){
                    continue;
                }
                
                if(isInvalidPosition2(in,newx2,newy2,w) ==1){
                    continue;
                }         
                
                q2 = enqueue(q2,newx2,newy2);
                break;
            }
            markPath(x2,y2,in,w);
    }
    free_queue(q2);
    free_list(nodes);
}
}

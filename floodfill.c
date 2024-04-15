#include <stdio.h>
#include "parents.h"
#include "readFile.h"
#include "bfs.h"

int floodfill(FILE *in,int x0,int y0, int xk,int yk, int w, int h){
    int x = 0;
    int y =1;
    char c ;
    rewind(in);
    while(( c = fgetc(in))!=EOF){
        if(checkifdeadend(in,x,y,w)== 0){
            bfs(in, x, y, 0, 0, w, h, true);
        }
        if(c=='\n'){
            y++;
            x = 0;
            continue;
        }
        x++;
    }
    return 0;
}

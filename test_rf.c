#include "readFile.h"
int main(){
    FILE *in = fopen("test.txt","r+");
    int x0, y0, xk, yk,w,h;
    read(in,&x0,&y0,&xk,&yk,&w,&h);
    printf("(w=%d,h=%d)\n",w,h);
    /*markVisited(in,1,3);
    if(isVisited(in,1,2)==0){
        printf("nieodwiedzony!\n");
    }else {
        printf("odwiedzony\n");
    }
    
    if(isInvalidPosition(in,0,1,w,h)==0){
       printf("nie jest sciana\n"); 
    }
    else { printf("jest sciana\n");}*/
}
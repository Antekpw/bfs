#include "readFile.h"
#include "floodfill.h"
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "bfs.h"
int main(){
    clock_t start_t, end_t;
    double total_t;
    start_t=clock();
    FILE *in = fopen("duzy.txt","r+");
    FILE *out = fopen("plik","w");
    if(out==NULL){
      fprintf(stderr,"blad z plikem wyjsciowym\n");
      return 1;
    }
    int x0, y0, xk, yk,w,h;
    read(in,&x0,&y0,&xk,&yk,&w,&h);

    floodfill(in,x0,y0,xk,yk,w,h);

    zamiana(in);

    bfs(in, x0, y0, xk, yk, w, h, false);

    int ile_curves = steps_to_File(in,out,x0,y0,xk,yk,w);

    zamiana2(in);
    printf("ile_curves=%d\n",ile_curves);
    fclose(out);
    end_t = clock();
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("%f",total_t);
}

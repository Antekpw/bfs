#include <time.h>
#include "bfs.h"
#include "queue.h"
#include "parents.h"
#include "readFile.h"
#include <stdio.h>
int main(){
    clock_t start_t, end_t;
    double total_t;
    start_t=clock();
    FILE *in = fopen("1024x1024.txt","r+");
    bfs(in);
    
    end_t = clock();
     total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
   printf("%f",total_t);
}
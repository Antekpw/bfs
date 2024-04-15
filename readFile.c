#include "readFile.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
void read(FILE *in, int *x0, int *y0, int *xk, int *yk, int *width, int *height) {
    char c;
    int x = 0;
    int y = 0;
    int maxWidth = 0;
    while ((c = fgetc(in)) != EOF) {
        switch (c) {
            case 'P':
                *x0 = x;
                *y0 = y;
                break;
            case 'K':
                *xk = x;
                *yk = y;
                break;
            case '\n':
                if (x > maxWidth) {
                    maxWidth = x;
                }
                y++;
                x = 0;
                break;
            default:
                x++;
                break;
        }
    }
    *width = maxWidth +1; // Szerokość to największa liczba znaków w wierszu + 1
    *height = y+1; // Wysokość to liczba wierszy + 1
}
void markVisited(FILE *in, int x, int y, int w) {
    fseek(in, y * (w) + x , SEEK_SET);
    if (fgetc(in) != 'N'){
        fseek(in, -1, SEEK_CUR);
        fputc('+', in); 
    }
}
void markNode(int x,int y, FILE *in, int w){
    fseek(in,y*(w) +x, SEEK_SET);
    fputc('N',in);
}
void markPath(int x,int y, FILE *in, int w){
    fseek(in,y*(w) +x, SEEK_SET);
    fputc('O',in);
}
int isInvalidPosition(FILE *in, int x, int y, int w) {
    fseek(in, y * (w) + x , SEEK_SET);
    char c = fgetc(in);
    if ( c == 'X' || c == '\n' || c == '+' || c =='N'){
        return 1;
    }
    else
        return 0;
}
int isInvalidPosition2(FILE *in, int x, int y, int w) {
    fseek(in, y * (w) + x , SEEK_SET);
    char c = fgetc(in);
    if ( c == 'X' || c == '\n' || c== ' ' || c == 'O'){
        return 1;
    }
    else
        return 0;
}
int isPath(FILE *in,int x,int y,int w){
    fseek(in, y*w + x, SEEK_SET);
    char c = fgetc(in);
    if(c =='O' && c!='0'){
        return 0;
    } else {
    return 1;
    }
}
void close(FILE *in,int x,int y,int w){
    fseek(in, y * (w) + x , SEEK_SET);
    fputc('X', in);
}
void zamiana(FILE *in) {
    rewind(in);
    char c ;
    while ((c=fgetc(in))!=EOF){
        if(c=='+'){
            fseek(in,-1,SEEK_CUR);
            fputc('X',in);
        }
    }
}
void zamiana2(FILE *in) {
   rewind(in);
    char znak;

    while ((znak = fgetc(in)) != EOF) {
        switch(znak){
            case '+':
            fseek(in, -1, SEEK_CUR);
            fputc('X', in);
            break;
            case 'N':
            fseek(in, -1, SEEK_CUR);
            fputc('X', in);
            break;
            case ' ':
            fseek(in, -1, SEEK_CUR);
            fputc('X', in);
            break;
            case '0':
            fseek(in, -1, SEEK_CUR);
            fputc(' ', in);
            break;
        }
    }
}

void markPath_visited(FILE *in, int x, int y,int w){
    fseek(in, y*w +x,SEEK_SET);
    fputc('0',in);
}
int steps_to_File(FILE *in,FILE *out,int x0, int y0,int xk,int yk,int w){
    int forward_count = 0;
    int dir = 1;
    int x=0,y=0;
    markPath_visited(in,x0,y0,w);
    queue q = NULL;
    q = enqueue(q,x0,y0);
    int ile_curves = 0;
    int dx[4] = {0,1,0,-1};
    int dy[4] = {-1,0,1,0};
    int stop = 0;
    fprintf(out,"START\n");
    while(q!=NULL && stop == 0 ){
        q = dequeue(q,&x,&y);
        if(x==xk && y == yk){
            forward_count++;
            fprintf(out,"MOVE FORWARD %d\n",forward_count);
            fprintf(out,"STOP\n");
            stop = 1;
            return (ile_curves+1);
        }
        for(int i=0;i<4;i++){   
            int newx = x+dx[i];
            int newy = y+dy[i];
            if(isInvalidPosition(in,newx,newy,w)==1){
                continue;
            }
            if(isPath(in,newx,newy,w)==0){
                markPath_visited(in,newx,newy,w);
                forward_count++;
                if(dir == i){
                    q = enqueue(q,newx,newy);
                }
                if(dir!=i){
                    ile_curves++;
                    fprintf(out,"MOVE FORWARD %d\n",forward_count);
                    forward_count = 0;
                    if(dir==0){
                        switch(i){
                            case 1 :
                            fprintf(out,"TURN RIGHT\n");
                            break;
                            case 3 :
                            fprintf(out,"TURN LEFT\n");
                            break;
                        }
                    }
                    if(dir==1){
                        switch(i){
                            case 2 :
                            fprintf(out,"TURN RIGHT\n");
                            break;
                            case 0 :
                            fprintf(out,"TURN LEFT\n");
                            break;
                        }
                    }
                    if(dir==2){
                        switch(i){
                            case 3 :
                            fprintf(out,"TURN RIGHT\n");
                            break;
                            case 1:
                            fprintf(out,"TURN LEFT\n");
                            break;
                    }
                    }
                    if(dir==3){
                        switch(i){
                            case 0 :
                            fprintf(out,"TURN RIGHT\n");
                            break;
                            case 2 :
                            fprintf(out,"TURN LEFT\n");
                            break;
                        }
                    }
                    dir = i;
                    q = enqueue(q,newx,newy);
                    break;
                }
            }   
            }   
        }
        
}












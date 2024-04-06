#include "readFile.h"
#include <stdio.h>
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
    fputc('+', in);

 
}
// Funkcja sprawdzająca, czy nowa pozycja jest prawidłowa
int isInvalidPosition(FILE *in, int x, int y, int w) {

    fseek(in, y * (w) + x , SEEK_SET);
    char c = fgetc(in);
    if ( c == 'X' || c == '\n' || c == '+'){
        return 1;
    }
    else
        return 0;



}
int isVisited(FILE *in, int x, int y){
    rewind(in);
    int curx = 0;
    int cury = 0;
    char c;
    while((c=fgetc(in))!=EOF){
        if(cury==y && curx == x){
            //fseek(in,0,SEEK_CUR);
            if(c=='+'){
                return -1;
                break;
            }
        }
        if(c=='\n'){
            cury++;
            curx = 0;
        }
        else {
            curx++;
        }
    }
    return 0;
}



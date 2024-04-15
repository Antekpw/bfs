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
// Funkcja sprawdzająca, czy nowa pozycja jest prawidłowa
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
void close(FILE *in,int x,int y,int w){
    fseek(in, y * (w) + x , SEEK_SET);
    fputc('X', in);
}

void zamiana(FILE *in) {
   rewind(in);
    char znak;

    while ((znak = fgetc(in)) != EOF) {
        if (znak == '+') {
            fseek(in, -1, SEEK_CUR);
            fputc('X', in);
        }
    }
}
void clearpath(FILE *in) {
    rewind(in);
    char zm;
    while ((zm = fgetc(in)) != EOF) {
        if (zm == ' ' || zm == '+' || zm == 'N') {
            fseek(in, -1, SEEK_CUR);
            fputc('X', in); 
        }
    }
}
void blankpath(FILE *in){
    rewind(in);
    char zm;
    while ((zm = fgetc(in)) != EOF) {
        if (zm == 'O') {
            fseek(in, -1, SEEK_CUR);
            fputc(' ', in); 
        }
    }
}
void clearmaze(FILE *in, int x, int y, int xk, int yk){
    char zm;
    int counter = 0;

    rewind(in);
    while ((zm = fgetc(in)) != '\n' && zm != EOF) {
         counter++;
        }
    rewind(in);
    for(int i=0; i<yk;i++){
    fseek(in,counter+1,SEEK_CUR);
    }
    for(int i=0; i<xk;i++){
    fseek(in,1,SEEK_CUR);
    }
    fputc('K', in);
    counter=0;

    rewind(in);
    while ((zm = fgetc(in)) != '\n' && zm != EOF) {
         counter++;
        }
    rewind(in);
    for(int i=0; i<y;i++){
    fseek(in,counter+1,SEEK_CUR);
    }
    for(int i=0; i<x;i++){
    fseek(in,1,SEEK_CUR);
    }
    fputc('P', in);

}













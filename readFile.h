#include <stdio.h>
void read(FILE *in, int *x0, int *y0, int *xk, int *yk, int *width, int *height);
void markVisited(FILE *in, int x, int y, int w);
void markPath(int x,int y, FILE *in, int w);
int isInvalidPosition(FILE *in, int x, int y, int h);
int isInvalidPosition2(FILE *in, int x, int y, int h);
void markNode(int x,int y,FILE *in,int w);
void close(FILE *in,int x,int y,int w);
void zamiana(FILE *in);
void clearpath(FILE *in);
void blankpath(FILE *in);
void clearmaze(FILE *in, int x, int y, int xk, int yk);


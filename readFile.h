#include <stdio.h>
void read(FILE *in, int *x0, int *y0, int *xk, int *yk, int *width, int *height);
void markVisited(FILE *in, int x, int y, int w);
int isInvalidPosition(FILE *in, int x, int y, int h);
int isInvalidPosition2(FILE *in, int x, int y, int h);
void markNode(int x,int y,FILE *in,int w);
void close(FILE *in,int x,int y,int w);
void zamiana(FILE *in);
void zamiana2(FILE *in);

int isPath(FILE *out,int x,int y,int w);
int steps_to_File(FILE *in,FILE *out,int x0, int y0,int xk,int yk,int w);
void markPath_visited(FILE *in,int x, int y, int w);
void markPath(int x,int y, FILE *in, int w);

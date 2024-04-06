#include <stdio.h>
void read(FILE *in, int *x0, int *y0, int *xk, int *yk, int *width, int *height);
void markVisited(FILE *in, int x, int y, int w);
int isInvalidPosition(FILE *in, int x, int y, int h);
int isVisited(FILE *in, int x, int w);
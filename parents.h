#include <stdio.h>
typedef struct e {
    int x;
    int y;
    struct e *next;
} *stos;

stos insert(stos t,int x, int y);
void printstos_to_FILE(stos t,FILE *out);
stos remove_last(stos t);
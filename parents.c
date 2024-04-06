#include "parents.h"
#include <stdlib.h>

stos insert(stos t,int x, int y){
        stos nowy = malloc(sizeof*(nowy));
        nowy->x = x;
        nowy->y = y;
        nowy->next = t;
        return nowy;
    
}
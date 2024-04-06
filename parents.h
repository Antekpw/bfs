typedef struct e {
    int x;
    int y;
    struct e *next;
} *stos;

stos insert(stos t,int x, int y);
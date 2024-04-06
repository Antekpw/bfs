typedef struct elem{
    int x;
    int y;
    struct elem *next;
}*queue;

queue enqueue(queue q,int x,int y);
queue dequeue(queue q,int *x,int *y);
void readqueue(queue q);
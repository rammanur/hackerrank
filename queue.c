#include "bool.h"

typedef struct queue_st {
   int capacity;
   int front;
   int rear;
   int size;
   int *elements;
} queue;

queue *createQueue (int maxElements)
{
    queue *q = (queue*)malloc(sizeof(queue));
    q->elements = (int*)malloc(sizeof(int)*maxElements);
    q->capacity = maxElements;
    q->front = 0;
    q->rear = maxElements-1;
    q->size = 0;
    return q;
}

enqueue(queue *q, int x)
{
    if (q->size >= q->capacity) {
        printf("Warning: queue overflow enqueue x=%d\n",x);
    } else {
        q->rear = (q->rear+1) % q->capacity;
        q->elements[ q->rear ] = x;    
        q->size += 1;
    }
}

int dequeue(queue *q)
{
    int x;

    if (q->size <= 0) {
        printf("Warning: empty queue dequeue.\n");
    } else {
        x = q->elements[ q->front ];
        q->front = (q->front+1) % q->capacity;
        q->size -= 1;
    }

    return(x);
}

int empty(queue *q)
{
    if (q->size <= 0) {
       return (TRUE);
    } else {
       return (FALSE);
    }
}

print_queue(queue *q)
{
    int i,j;

    i=q->front; 
        
    while (i != q->rear) {
        printf("%c ",q->elements[i]);
        i = (i+1) % q->capacity;
    }

    printf("%2d ",q->elements[i]);
    printf("\n");
}


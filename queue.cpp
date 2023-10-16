#include <stdio.h>
#include <stdlib.h>

#define max 5

typedef struct 
{
    int data[max];
    int front,rear;
}sqqueue;

void init(sqqueue *&q)
{
    q=(sqqueue *)malloc(sizeof(sqqueue));
    q->front=q->rear=0;
}

void destroy(sqqueue *&q)
{
    free(q);
}

bool empty(sqqueue *q)
{
    return(q->front==q->rear);
}

enqueue(sqqueue *&q,int e)
{
    if((q->rear+1)%max==q->front)
    {
        return false;
    }
    q->rear=(q->rear+1)%max;
    q->data[q->rear]=e;
    return true;
}

bool dequeue(sqqueue *&q,int &e)
{
    if(q->front==q->rear)
    {
        return false;
    }
    q->front=(q->front+1)%max;
    e=q->data[q->front];
    return true;
}

int count(sqqueue *q)
{
    return((q->rear-q->front+max)%max);
}

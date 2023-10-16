#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define max 6
typedef struct qnode 
{
    int data[max];
    struct qnode *next;
}datanode;

typedef struct 
{
    datanode *front;
    datanode *rear;
}linkqunode;

void init(linkqunode *&q)
{
    q=(linkqunode *)malloc(sizeof(linkqunode));
    q->front=q->rear=NULL;
}

void destroy(linkqunode *&q)
{
    datanode *pre=q->front,*p;
    if(pre!=NULL)
    {
        p=pre->next;
        while(p!=NULL)
        {
            free(pre);
            pre=p;
            p=p->next;
        }
        free(pre);
    }
    free(q);
}

bool empty(linkqunode *q)
{
    return(q->rear==NULL);
}

bool enqueue(linkqunode *&q,int e)
{
    datanode *p;
    p=(datanode *)malloc(sizeof(datanode));
    p->next=NULL;
    p->data=e;
    if(q->rear==NULL)
    {
        q->front=q->rear=p;
    }
    else
    {
        q->rear->next=p;
        q->rear=p;
    }
    return true;
}

bool dequeue(linkqunode *&q,int &e)
{
    datanode *t;
    if(q->rear==NULL)
    {
        return false;
    }
    t=q->front;
    if(q->front==q->rear)
    {
        q->front=q->rear=NULL;
    }
    else
    {
        q->front=q->front->next;
    }
    e=t->data;
    free(t);
    return true;
}


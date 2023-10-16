#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct linknode
{
    int data;
    struct linknode *next;
}linkstnode;

//初始化
void init(linkstnode *&s)
{
    s=(linkstnode *)malloc(sizeof(linkstnode));
    s->next=NULL;
}

//销毁
void destroy(linkstnode *&s)
{
    linkstnode *p=s,*q=s->next;
    while(q!=NULL)
    {
        free(p);
        free(q);
        q=q->next;
    }
}

//入栈
bool push(linkstnode *&s,int e)
{
    linkstnode *p;
    p=(linkstnode *)malloc(sizeof(linkstnode));
    p->data=e;
    p->next=s->next;
    s->next=p;
    return true;
}

//出栈
bool pop(linkstnode *&s,int &e)
{
    linkstnode *p;
    if(s->next==NULL)
    {
        return false;
    }
    else
    {
        p=s->next;
        e=p->data;
        s->next=p->next;
        free (p);
        return true;
    }
}

//是否为空
bool empty(linkstnode *s)
{
    return(s->next==NULL);
}

//取栈顶元素
bool get(linkstnode *s,int &e)
{
    linkstnode *p;
    if(s->next==NULL)
    {
        return false;
    }
    else
    {
        p=s->next;
        e=p->data;
        return true;
    }
}

//十进制转换二进制
void trans(int d)
{   int e=0,m=0,i=0;
    linkstnode *q;
    init(q);
    while(d)
    {
        i++;
        push(q,d%2);
        d=d/2;
    }
    while(!empty(q))
    {
        pop(q,e);
        printf("%d",e);
    }
    printf("\n");
    destroy(q);
}

int main()
{
    trans(25555);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct dnode
{
    int data;
    struct dnode *prior;
    struct dnode *next;
}dnode;

//头表
void create1(dnode *&L,int a[],int n)
{
    dnode *s;
    L=(dnode *)malloc(sizeof(dnode));
    L->next=NULL;
    L->prior=NULL;
    for(int i=0;i<n;i++)
    {
        s=(dnode *)malloc(sizeof(dnode));
        s->data=a[i];
        s->next=L->next;
        if(s->next!=NULL)
        {
            s->next->prior=s;
        }
        s->prior=L;
        L->next=s;
    }
}

//尾插法
void create2(dnode *&L,int a[],int n)
{
    dnode *s,*r;
    L=(dnode *)malloc(sizeof(dnode));
    r=(dnode *)malloc(sizeof(dnode));
    L->next=NULL;
    L->prior=NULL;
    r=L;
    for(int i=0;i<n;i++)
    {
        s=(dnode *)malloc(sizeof(dnode));
        s->data=a[i];
        r->next=s;
        r->next->prior=r;
        s->next=r->next;
        r=s;
    }
    r->next=NULL;
}

//正向输出
void output1(dnode *&L)
{
    dnode *p=L->next;
    while (p!=NULL)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
}

//反向输出
void output2(dnode *&L)
{
    dnode *p=L->next;
    while (p!=NULL)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
}

//插入元素
bool listinsert(dnode *&L,int i,int &x)
{
    int j=0;
    dnode *p=L,*q;
    if(i<=0||p->next==NULL)
    {
        return false;
    }
    while(j<i-1&&p->next!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p==NULL)
    {
        return false;
    }
    else
    {
        q=(dnode *)malloc(sizeof(dnode));
        q->next=p->next;
        p->next=q;
        q->data=x;
        if(q==NULL)
        {
            return false;
        }
        q->prior=p;
        q->next->prior=q;
        return true;
    }
}

int main()
{   
    int a[4]={1,5,6,7};
    dnode *L;
    int x=5;
    create2(L,a,4);
    listinsert(L,1,x);
    output1(L);
    free(L);
    return 0;
}
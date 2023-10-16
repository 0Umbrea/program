#include <stdio.h>
#include <stdlib.h>

//结构体定义
typedef struct lnode
{
    int data;
    struct lnode *next;
}linknode;

//头表法
void create1(linknode *&L,int a[],int n)
{
    linknode *s;
    L=(linknode*)malloc(sizeof(linknode));
    L->next=NULL;
    for(int i=0;i<n;i++)
    {
        s=(linknode*)malloc(sizeof(linknode));
        s->data=a[i];
        s->next=L->next;
        L->next=s;
    }
}

//尾表法
void create2(linknode *&L,int a[],int n)
{
    linknode *s,*r;
    L=(linknode *)malloc(sizeof(linknode));
    r=L;
    for(int i=0;i<n;i++)
    {
        s=(linknode*)malloc(sizeof(linknode));
        s->data=a[i];
        r->next=s;
        r=s;
    }
    r->next=NULL;
}

//创建循环单链表
void create3(linknode *&L,int a[],int n)
{
    linknode *s,*r;
    L=(linknode *)malloc(sizeof(linknode));
    r=L;
    for(int i=0;i<n;i++)
    {
        s=(linknode*)malloc(sizeof(linknode));
        s->data=a[i];
        r->next=s;
        r=s;
    }
    r->next=L;
}

//输出链表
void output1(linknode *&L)
{
    linknode *p=L->next;
    while(p!=NULL)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
    printf("\n");
}

//输出循环单链表
void output3(linknode *&L,int n,int x)
{
    linknode *p=L->next;
    int i=0,m=0;
    while(m<x)
    {
        i=0;
        while(p!=NULL&&i<=n)
        {
            printf("%d\n",p->data);
            p=p->next;
            i++;
        }
        m++;
        p=p->next;
    }
    printf("\n");
}

//输出序号
void output2(linknode *&L,int i,int n)
{
    linknode *p=L->next;
    int x=1;
    if(i<=0||i>n||p->next==NULL)
    {
        printf("不存在该元素\n");
    }
    else
    {
    while(x!=i)
    {
        x++;
        p=p->next;
    }
    printf("%d\n",p->data);
    }
}

//查找序号
bool getelem(linknode *L,int i,int &e)
{
    int j=0;
    linknode *p=L;
    if(i<=0)
    {
        return false ;
    }
    while(j<i&&p!=NULL)
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
        e=p->data;
        return true;
    }
}

//查找元素值
int locateElem(linknode *L,int n)
{
    linknode *p=L;
    int i=0;
    while(p!=NULL&&p->data!=n)
    {
        i++;
        p=p->next;
    }
    return i;
}

//查找最大元素逻辑序号
int locate1(linknode *L,int n)
{
    linknode *p=L;
    int i=0,m=0,x=0;
    int a[n];
    if(n<=0||p->next==NULL)
    {
        printf("输入有误");
    }
    while (p!=NULL&&i<n)
    {
        a[i]=p->next->data;
        i++;
        p=p->next;
    }
    i=a[0];
    for(m=1;m<n;m++)
    {
        if(i<a[m])
        {
            i=a[m];
            x=m;
        }
    }
    return x+1;
}

//查找最大元素逻辑值
int locate2(linknode *L,int n)
{
    linknode *p=L;
    int i=0,m=0;
    int a[n];
    if(n<=0||p->next==NULL)
    {
        printf("输入有误");
    }
    while (p!=NULL&&i<n)
    {
        a[i]=p->next->data;
        i++;
        p=p->next;
    }
    i=a[0];
    for(m=1;m<n;m++)
    {
        if(i<a[m])
        {
            i=a[m];
        }
    }
    return i;
}

//求长度
int listlength(linknode *L)
{
    int n=0;
    linknode *p=L;
    while(p!=NULL)
    {
        n++;
        p=p->next;
    }
    return (n);
}

//插入数据
bool listinsert(linknode *&L,int i,int e)
{
    int j=0;
    linknode *p=L,*s;
    if(i<=0)
    {
        return false;
    }
    while(j<i&&p!=NULL)
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
        s=(linknode *)malloc(sizeof(linknode));
        s->data=e;
        s->next=p->next;
        p->next=s;
        return true;
    }
}

//删除
bool dlete(linknode *&L,int i,int &e)
{
    int j=0;
    linknode *p=L,*q;
    if(i<=0)
    {
        return false;
    }
    while(j<i-1&&p!=NULL)
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
        q=p->next;
        e=q->data;
        if(q==NULL)
        {
            return false;
        }
        p->next=q->next;
        free(q);
        return true;
    }
}


int main()
{
    int x[4]={2,7,5,4};
    linknode *L;
    int i=0;
    create2(L,x,4);
    listinsert(L,4,3);
    output1(L);
    free(L);
    return 0;
}
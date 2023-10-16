#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int data[60];
    int length;
}sqlist;

//判断
bool determine(sqlist *&L)
{
    int a=0;
    for(int i=0;i<L->length-1;i++)
    {
        if(L->data[i]<L->data[i+1])
        {
            a++;
        }
    }
    if(a==(L->length-1))
    {
        return true;
    }
    else
    {
        return false;
    }
}

//创建
void create (sqlist *&L,int a[],int n)
{
    int i=0;
    L=(sqlist *)malloc(sizeof(sqlist));
    for(i=0;i<n;i++)
    {
        L->data[i]=a[i];
    }
    L->length=n;
}

//输出
void output(sqlist *L)
{
    for(int i=0;i<L->length;i++)
    {
        printf ("%d\n",L->data[i]);
    }
}

//查找
void locate(sqlist *L,int x)
{
    int a=0;
    for(int i=0;i<L->length;i++)
    {
        if(L->data[i]==x)
        {
            a++;
        }
    }
    printf("%d\n",a);
}

//删除值在x，y之间的元素
void fun(sqlist *&L,int x,int y)
{
    int i,j;
    for(i=0,j=0;i<L->length;i++)
    { 
        if(L->data[i]>=x&&L->data[i]<=y)
        {
            continue;
        }
        L->data[j]=L->data[i];
        j++;
    }
    L->length=j;
}
int main()
{
    sqlist *L;
    sqlist *s;
    s=(sqlist *)malloc(sizeof(sqlist));
    int a[4]={-1,0,-1,34};
    create(L,a,4);
    fun(L,0,2);
    output(L);
    return 0;
}
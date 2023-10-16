#include <stdio.h>
#include <stdlib.h>

#define max  60

typedef struct
{
    int i;
    int j;
    int di;
}box;

typedef struct
{
    box data[max];
    int top;
}sttype;

//初始化
void init(sttype *&s)
{
    s=(sttype *)malloc(sizeof(sttype));
    s->top=-1;
}

void destroy(sttype *&s)
{
    free(s);
}

//进栈
bool push(sttype *&s,box e)
{
    if(s->top==max-1)
    {
        return false;
    }
    else
    {
        s->top++;
        s->data[s->top]=e;
        return true;
    }
}

//出栈
bool pop(sttype *&s,box &e)
{
    if(s->top==-1)
    {
        return false;
    }
    else
    {
        e=s->data[s->top];
        s->top--;
        return true;
    }
}

//判断是否为空
bool empty(sttype *s)
{
    return(s->top==-1);
}

//取值
bool get(sttype *s,box &e)
{
    if(s->top==-1)
    {
        return false;
    }
    e=s->data[s->top];
    return true;
}

void mgpath(int xi,int yi,int xe,int ye)
{
    int mg[8][8]=
    {
        {1,1,1,1,1,1,1,1},
        {1,0,0,1,0,0,1,1},
        {1,0,0,1,1,1,1,1},
        {1,0,1,1,1,1,1,1},
        {1,0,0,0,0,1,1,1},
        {1,0,1,0,0,0,0,1},
        {1,0,1,1,1,1,1,1},
        {1,0,1,1,1,1,1,1}
    };
    sttype *st;
    init(st);
    int i,j,di,i1,j1,k;
    bool find;
    box e,path[max];
    e.i=xi;
    e.j=yi;
    e.di=-1;
    push(st,e);
    mg[xi][yi]=-1;
    while(!empty(st))
    {
        get(st,e);
        i=e.i;
        j=e.j;
        di=e.di;
        if(i==xe&&j==ye)
        {
            printf("迷宫的一条路径");
            k=0;
            while(!empty(st))
            {
                pop(st,e);
                path[k]=e;
                k++;
            }
            while (k>0)
            {
                printf("(%d,%d)",path[k-1].i,path[k-1].j);
                k--;
                printf("\n");
            }
        }
        find=false;
        while(di<4&&!find)
        {
            di++;
            switch (di)
            {
            case 0:
                i1=i-1;
                j1=j;
                break;
            case 1:
                i1=i;
                j1=j+1;
                break;
            case 2:
                i1=i+1;
                j1=j;
                break;
            case 3:
                i1=i;
                j1=j-1;
                break;
            }
            if(mg[i1][j1]==0)
            {
                find=true;
            }
        }
        if(find)
        {
                st->data[st->top].di=di;
                e.i=i1;
                e.j=j1;
                e.di=-1;
                push(st,e);
                mg[i1][j1]=-1;
        }
        else
        {
                pop(st,e);
                mg[e.i][e.j]=0;
        }
    }
    destroy(st);
}

int main()
{
    mgpath(1,1,7,1);
    return 0;
}

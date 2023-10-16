#include <stdio.h>
#include <stdlib.h>

#define max  60

typedef struct
{
    char data[max];
    int top;
}spstack;

//初始化
void init(spstack *&s)
{
    s=(spstack *)malloc(sizeof(spstack));
    s->top=-1;
}


void destroy(spstack *&s)
{
    free(s);
}

//进栈
bool push(spstack *&s,char e)
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
bool pop(spstack *&s,char &e)
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
bool empty(spstack *s)
{
    return(s->top==-1);
}

//取值
bool get(spstack *s,char &e)
{
    if(s->top==-1)
    {
        return false;
    }
    e=s->data[s->top];
    return true;
}

//加减同一量级，乘除同一量级，栈顶应小于输入操作数运算级，大于或等于则输出，输入乘除判断是否含有加减或本身
void trans(char *exp,char postexp[])
{
    char e;
    spstack *optr;
    init(optr);
    int i=0;
    while(*exp!='\0')
    {
        switch(*exp)
        {
            case '(':
            push(optr,'(');
            exp++;
            break;
            case ')':
                get(optr,e);
                while(e!='(')
                {
                    postexp[i++]=e;
                    pop(optr,e);
                }
                exp++;
                break;
            case '+':
            case '-':
                while(!empty(optr))
                {
                    get(optr,e);
                    if(e!='(')
                    {
                        postexp[i++]=e;
                        pop(optr,e);
                    }
                    else
                    {
                        break;
                    }
                }
                push(optr,*exp);
                exp++;
                break;
            case '*':
            case '/':
                while(!empty(optr))
                {
                    get(optr,e);
                    if(e=='*'||e=='/')
                    {
                        postexp[i++]=e;
                        pop(optr,e);
                    }
                    else
                    {
                        break;
                    }
                }
                push(optr,*exp);
                exp++;
                break;
            default:
                while(*exp>='0'&&*exp<='9')
                {
                    postexp[i++]=*exp;
                    exp++;
                }
                postexp[i++]='#';
        }
    }
    while (!empty(optr))
    {
        pop(optr,e);
        postexp[i++]=e;
    }
    postexp[i]='\0';
    free(optr);
    
}


int main()
{
    char x[]={'(','5','6','+','5',')','\0'};
    char *exp=x;
    char postexp[60];
    spstack *p;
    init(p);
    trans(exp,postexp);
    for(int i=0;i<6;i++)
    {
        printf("%c",postexp[i]);
    }
    printf("\n");
    return 0;
}
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

//销毁
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

bool push1(spstack *&s,double e)
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

bool pop1(spstack *&s,double &e)
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

bool get(spstack *s,double &e)
{
    if(s->top==-1)
    {
        return false;
    }
    e=s->data[s->top];
    return true;
}

//加减同一量级，乘除同一量级，栈顶应小于输入操作数运算级，大于或等于则输出，输入乘除判断是否含有加减或本身
void trans(char *exp,spstack *p)
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
                    push(p,e);
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
                        push(p,e);
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
                        push(p,e);
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
                    push(p,*exp);
                    exp++;
                }
                push(p,'#');
        }
    }
    while (!empty(optr))
    {
        pop(optr,e);
        push(p,e);
    }
    push(p,'\0');
    free(optr);
    
}

//求值
double compvalue(char *postexp)
{
    double a,b,c,d,e;
    spstack *opnd;
    init(opnd);
    while(*postexp!='\0')
    {
        switch(*postexp)
        {
            case '+':
                pop1(opnd,a);
                pop1(opnd,b);
                c=b+a;
                push1(opnd,c);
                break;
            case '-':
                pop1(opnd,a);
                pop1(opnd,b);
                c=b-a;
                push1(opnd,c);
                break;
            case '*':
                pop1(opnd,a);
                pop1(opnd,b);
                c=b*a;
                push1(opnd,c);
                break;
            case '/':
                pop1(opnd,a);
                pop1(opnd,b);
                if(a==0)
                {
                    printf("输入有误\n");
                    break;
                }
              else
                {
                    c=b/a;
                    push1(opnd,c);
                    break;
                }
                break;
            default:
                d=0;
                while(*postexp>='0' && *postexp<='9')
                {
                    d=10*d+*postexp-'0';
                    postexp++;
                }
                push1(opnd,d);
                break;
        }
        postexp++;
    }
    get(opnd,e);
    destroy(opnd);
    return e;
}


int main()
{
    char x[]={'(','5','6','+','5',')','\0'};
    char *exp=x;
    char postexp[60];
    spstack *p;
    init(p);
    trans(exp,p);
    for(int i=0;i<6;i++)
    {
        postexp[i]=p->data[i];
    }
    printf("%g\n",compvalue(postexp));
    return 0;
}
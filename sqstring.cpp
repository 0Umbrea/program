#include <stdio.h>
#include <stdlib.h>

#define max 60
typedef struct 
{
    char data[max];
    int length;
}sqstring;

sqstring insstr(sqstring s1,int i,sqstring s2)
{
    int j;
    sqstring str;
    str.length=0;
    if(i<=0||i>s1.length+1)
    {
        return str;
    }
    for(j=0;j<i-1;j++)
    {
        str.data[j]=s1.data[j];
    }
    for(j=0;j<s2.length;j++)
    {
        str.data[i+j-1]=s2.data[j];
    }
    for(j=i-1;j<s1.length;j++)
    {
        str.data[s2.length+1]=s1.data[j];
    }
    str.length=s1.length+s2.length;
    return str;
}

void RepChar(sqstring &s,int x,int y)
{
    int i;
    for(i=0;i<s.length;i++)
    {
        if(s.data[i]==x)
        {
            s.data[i]=y;
        }
    }
}

bool push(sqstring &s,char x)
{
    s.data[s.length]=x;
    s.length++;
    return true;
}

bool init(sqstring &s)
{
    s.length==0;
    return true;
}

bool distinguish(sqstring s,sqstring &s1,sqstring &s2)
{
    //s1数字s2字母
    int i;
    s1.length=0;
    s2.length=0;
    for(i=0;i<s.length;i++)
    {
        if((s.data[i]>='a'&&s.data[i]<='z')||(s.data[i]>='A'&&s.data[i]<='Z'))
        {
            push(s2,s.data[i]);
        }
        if(s.data[i]>='0'&&s.data[i]<='9')
        {
            push(s1,s.data[i]);
        }
    }
    return true;
}

int main()
{
    sqstring s,s1,s2;
    init(s);
    push(s,'a');
    push(s,'7');
    distinguish(s,s1,s2);
    for(int i=0;i<s1.length;i++)
    {
        printf("%c\n",s1.data[i]);
    }
    for(int i=0;i<s.length;i++)
    {
        printf("%c\n",s2.data[i]);
    }
    return 0;
}
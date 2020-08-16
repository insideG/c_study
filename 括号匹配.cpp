#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable : 4996)
#define Maxsize 50
typedef char Datatype;
typedef struct {
    Datatype data[Maxsize];
    int top;
}SqStack;
void InitStack(SqStack* S)
{
    S->top = -1;
}
int StackEmpty(SqStack* S)
{
    if (S->top == -1)
        return 0;
    else
        return 1;
}
int Push(SqStack* S, Datatype x)
{
    if (S->top == Maxsize - 1)
        return 0;
    else
        S->data[++(S->top)] = x;
    return 1;
}
int Pop(SqStack* S, Datatype* x)
{
    if (S->top == -1)
        return 0;
    else
        *x = S->data[(S->top)--];
    return 1;
}
int GetTop(SqStack S, Datatype* x)
{
    if (S.top == -1)
        return 0;
    else
        *x = S.data[S.top];
    return 1;
}
int Bracketscheck(SqStack* S, char* str)
{
    InitStack(S);
    char e;
    int i = 0;
    while (str[i] != '\0')
    {
        switch (str[i]) {
        case '(':
            Push(S, '(');
            break;
        case '{':
            Push(S, '{');
            break;
        case '[':
            Push(S, '[');
            break;
        case ')':
            Pop(S, &e);
            if (e != '(')
                return 0;
            break;
        case '}':
            Pop(S, &e);
            if (e != '{')
                return 0;
            break;
        case ']':
            Pop(S, &e);
            if (e != '[')
                return 0;
            break;
        default:
            break;

        }
        i++;
    }
    int h = StackEmpty(S);
    if (h == 1)
        return 0;
    else
        return 1;
}
int main()
{
    SqStack S;
    char str[Maxsize];
    printf("请输入你要收入的字符串：");
    scanf("%s", str);
    int h = Bracketscheck(&S, str);
    if (h == 1)
        printf("括号不匹配");
    else
        printf("括号匹配");
    return 0;
}


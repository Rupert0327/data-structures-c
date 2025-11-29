#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100

typedef char DataType;

typedef struct 
{
    DataType data[MaxSize];
    int top;
} SeqStack;

//初始化
void InitStack(SeqStack *S){S->top = -1;}

//判栈空
int StackEmpty(SeqStack S){return S.top == -1;}  

//判栈满
int StackFull(SeqStack S){return S.top == MaxSize - 1;}

//入栈
int Push(SeqStack *S, DataType x){
    if (StackFull(*S))
    {
        printf("The stack is full!\n");
        return 0;
    }
    S->data[++(S->top)] = x;
    return 1;
}

//出栈（同时也取栈顶了）
int Pop(SeqStack *S, DataType *x){
    if (StackEmpty(*S))
    {
        printf("The stack is empty!\n");
        return 0;
    }
    *x = S->data[(S->top)--];
    return 1;
}

int main(){
    SeqStack S;
    InitStack(&S);

    char str[MaxSize];
    printf("Please enter a string of brackets:\n");
    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++)
    {
        char c = str[i];
        // process character c 
        if (c == '(' || c == '[' || c == '{')
            Push(&S, c);
        else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
        {
            if (StackEmpty(S))
            {
                printf("Brackets do not match!\n");
                return 0;
            }
            Pop(&S, &c);
            if ((str[i] == ')' && c != '(') || 
                (str[i] == ']' && c != '[') || 
                (str[i] == '}' && c != '{'))
            {
                printf("Brackets do not match!\n");
                return 0;
            }
        }
    }
    if (StackEmpty(S))
    {
        printf("Brackets match!\n");
        return 1;
    }
    else
    {
        printf("Brackets do not match!\n");
        return 0;
    }
    return 0;
}
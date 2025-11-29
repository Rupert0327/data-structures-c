#include<stdio.h>
#include<stdio.h>

#define MaxSize 100
#define DataType int

typedef struct 
{
    DataType data[MaxSize];
    int top;
} SeqStack;

//初始化
void InitStack(SeqStack *S){
    S->top = -1;
}

//判栈空
int StackEmpty(SeqStack S){
    return S.top == -1;
}

//判栈满
int StackFull(SeqStack S){
    return S.top == MaxSize - 1;
}

//求栈长
int StackLength(SeqStack S){
    return S.top + 1;
}

//入栈
int Push(SeqStack *S){
    DataType x;
    printf("Please enter the value of the element:");
    scanf("%d", &x);
    if (StackFull(*S))
    {
        printf("The stack is full!\n");
        return 0;
    }
    S->data[++(S->top)] = x;
    return 1;
}

//出栈
int Pop(SeqStack *S, DataType *x){
    if (StackEmpty(*S))
    {
        printf(" The stack is empty!\n");
        return 0;
    }
    *x = S->data[(S->top)--];
    return 1;
}

//取栈顶
int GetTop(SeqStack S, DataType *x){
    if (StackEmpty(S))
    {
        printf("The stack is empty,  top element does not exist.");
        return 0;
    }
    *x = S.data[S.top];
    return 1;
}

int main(){
    SeqStack S;
    DataType x;
    InitStack(&S);

    Push(&S);
    Push(&S);
    Push(&S);

    printf("The length of the stack: %d\n", StackLength(S));

    Pop(&S, &x);
    printf("Popped element: %d\n", x);
    
    return 0;
}
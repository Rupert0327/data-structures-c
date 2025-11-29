#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

typedef struct StackNode {
    DataType data;
    struct StackNode *next;
} StackNode, *LinkStack;

void InitStack(LinkStack *S){
    *S = NULL;
}

int IsEmpty(LinkStack S) {
    return S == NULL;
}

void PushStack(LinkStack *S){
    printf("Please enter the value the element:\n");
    StackNode *node = (StackNode *)malloc(sizeof(StackNode));
    if (!node)
        return;
    
    scanf("%d", &node->data);
    node->next = *S;
    *S = node;
}

int Pop(LinkStack *S, DataType *x){
    if (IsEmpty(*S))
        return 0;
    
    StackNode *p = *S;
    *x = p->data;
    *S = p->next;
    free(p);
    return 1;
}

int GetTop(LinkStack S, DataType *x){
    if (IsEmpty(S))
        return 0;
    
    *x = S->data;
    return 1;
}

void ClearStack(LinkStack *S){
    StackNode *p, *q;
    p = *S;
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
    *S = NULL;
}

int StackLength(LinkStack S){
    int length = 0;
    StackNode *p = S;
    while (p) {
        length++;
        p = p->next;
    }
    return length;
}

int StackTraverse(LinkStack S){
    StackNode *p = S;
    if (IsEmpty(S))
        return 0;
    
    printf("The elements in the stack are:\n");
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    return 1;
}

int DestroyStack(LinkStack *S){
    ClearStack(S);
    return 1;
}

int main() {
    LinkStack S;
    DataType x;
    InitStack(&S);
    
    PushStack(&S);
    PushStack(&S);
    PushStack(&S);
    
    StackTraverse(S);
    
    GetTop(S, &x);
    printf("Top element: %d\n", x);
    
    Pop(&S, &x);
    printf("Popped element: %d\n", x);
    
    StackTraverse(S);
    
    printf("Stack length: %d\n", StackLength(S));
    
    ClearStack(&S);
    printf("Stack cleared.\n");
    
    DestroyStack(&S);
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
    char data;
    struct Node *next;
} Node, *LinkStack;

void InitStack(LinkStack *S){
    *S = NULL;
}

void Push(LinkStack *S, char x){
    Node *node = (Node *)malloc(sizeof(Node));
    if (!node)
        return;
    node->data = x;
    node->next = *S;
    *S = node;
}

void Pop(LinkStack *S, char *x){
    if (*S == NULL)
        return;
    
    Node *p = *S;
    *x = p->data;
    *S = p->next;
    free(p);
}

int main(){
    LinkStack S;
    InitStack(&S);

    char str[100];
    printf("Please enter a string:\n");
    scanf("%s", str);

    
    int len = strlen(str);
    int i, j;
    
    for (i = 0; i < len && str[i] != '@'; i++) {
        Push(&S, str[i]);
    }
    
    for (j = 0; j < i; j++)
    {
        char ch;
        Pop(&S, &ch);
        //printf("%c", ch);
        if (str[j] != ch) {
            printf("The string is not a palindrome.\n");
            return 0;
        }
    }
    printf("The string is a palindrome.\n");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#define DataType int

typedef struct node{
	DataType data;
	struct node *next;
}NODE, *LinkList;

//初始化
void InitList_L(LinkList *L){
	*L = (NODE *)malloc(sizeof(NODE));
	if(!(*L)) 
		exit(-1);
	(*L)->next = NULL;
}

//尾插法建立循环链表
int CreatList_CR(LinkList *L){
    NODE *s, *rear;
	int i, n;
	InitList_L(L);
	printf("Please enter the length n: ");
	scanf("%d", &n);
	if(n < 1){
		printf("The length is unreasonable!\n");
		return 0;
	}
	rear = *L; 
	printf("Please enter the value of each element:\n");
	for(i = 0; i < n; i++){
		s = (NODE *)malloc(sizeof(NODE));
		if(!s)
			exit(-1);
		scanf("%d", &s->data);
		
		s->next = NULL;
		rear->next = s;
		rear = s;
	}
    rear->next = *L;
	return 1;
}

//取值
int GetElem_L(LinkList L, int i, DataType *x){
	NODE *p;
	p = L->next;		
	int j = 1;
	while(p != L && j < i){		
		p = p->next;
		j++;
	}
	if(p == L || j > i)
		return 0;
	else{
		*x = p->data;
		return 1; 
	}
}

//插入
int ListInsert_CL(LinkList *L, int i, DataType t){
    NODE *p = *L, *s;
    int flag = 1;
    int j = 0;
    while ((p != *L || flag == 1) && j < i-1)
    {
        flag = 0;
        p = p->next;
        j++;
    }
    if ((p == *L && flag == 0) || j > i-1)
        return 0;
	else{
		s = (NODE *)malloc(sizeof(NODE));
		if(!s) 
			exit(-1);
		
		s->data = t;
		s->next = p->next;
		p->next = s;
		return 1;
    }
    /*
        ------
    */
}
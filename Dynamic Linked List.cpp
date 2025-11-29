#include <stdio.h>
#include <stdlib.h>

#define DataType int

typedef struct node{
	DataType data;
	struct node *next;
}NODE, *LinkList;

//typedef NODE* LinkList;

//初始化
void InitList_L(LinkList *L){
	*L = (NODE *)malloc(sizeof(NODE));
	if(!(*L)) 
		exit(-1);
	(*L)->next = NULL;
}

//取值
int GetElem_L(LinkList L, int i, DataType *x){
	NODE *p;
	p = L->next;		
	int j = 1;
	while(p && j < i){		
		p = p->next;
		j++;
	}
	if(!p || j > i)
		return 0;
	else{
		*x = p->data;
		return 1; 
	}
} 

//插入
int ListInsert_L(LinkList *L, int i, DataType t){
	NODE *p = *L, *s;
	int j = 0;
	while(p && j < i-1){
		p = p->next;
		j++;
	}
	if(!p || j > i+1)
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
} 

int ListDelete_L(LinkList *L, int i, DataType *x){
	NODE *p = *L, *q;
	int j = 0;
	while(p->next && j < i-1){
		p = p->next;
		j++;
	}
	if(!(p->next) || j > i-1)
		return 0;
	else{
		q = p->next;
		p->next = q->next;
		*x = q->data;
		free(q);
	}
	return 1;
}
 
int FindElem_LA(LinkList L, DataType x){
	NODE *p = L->next;
	int pos = 1;
	while(p && p->data!= x){
		p = p->next;
		pos++;
	}
	if(!p)
		return 0;
	else
		return pos;
}


NODE *FindElem_LB(LinkList L, DataType x){
	NODE *p = L->next;
	while(p && p->data!=x)
		p = p->next;
	return p;
}

int ListLength_L(LinkList L){
	NODE *p = L->next;
	int num = 0;
	while(p){
		num++;
		p = p->next;
	}
	return num;
}

//尾插法
int CreatList_R(LinkList *L){
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
	return 1;
} 

//头插法
int CreatList_F(LinkList *L){
	NODE *s, *head;
	int i, n;
	InitList_L(L);
	printf("Please enter the length n: ");
	scanf("%d", &n);
	if(n < 1){
		printf("The length is unreasonable!\n");
		return 0;
	}
	
	head  = *L;
	printf("Please enter the value of each element:\n");
	for(i = 0; i < n; i++){
		s = (NODE *)malloc(sizeof(NODE));
		if(!s)
			exit(-1);
		scanf("%d", &s->data);
			
		s->next = head->next;
		head->next = s;
	}
	return 1;
}

void PrintList_L(LinkList L){
    NODE *p = L->next;
    printf("List: ");
    while(p){
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

void DestroyList_L(LinkList *L){
	NODE *p = *L, *q;
	while(p){
		q = p->next;
		free(p);
		p = q;
	}
	*L = NULL;
} 

int main(){
    LinkList head = NULL;
    
    CreatList_R(&head);
    PrintList_L(head);
    return 0;
}

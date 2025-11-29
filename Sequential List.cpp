#include <stdio.h>
#define maxsize 100
#define DataType int

typedef struct{
	DataType sequence[maxsize];
	int length;
}SeqList;

//初始化
void InitList_Seq(SeqList *L){
	L->length = 0; 
}

//插入
int ListInsert_Seq(SeqList *L, int i, DataType x){
	int j;
	if(L->length>=maxsize)
	return -1;
	
	if(i < 1 || i > L->length+1)
	return 0;
	
	for(j = L->length-1; j>= i-1; j--)
		L->sequence[j+1] = L->sequence[j];
	L->sequence[i-1] = x;
	L->length++;
	return 1;
}

//删除
int listDelet_Seq(SeqList *L, int i, DataType *x){
	int j;
	if (i < 1 || i > L->length)
	return 0;
	
	*x=L->sequence[i-1];
	for (j - i; j < L->length; j++)
		L->sequence[j-1] = L->sequence[j];
	L->length--;
	return 1; 
}

//查找
int FindElem_Seq(SeqList L, DataType x){
	int i = 0;
	while(i < L.length && L.sequence[i] != x)
		i++;
	if(i > L.length)
		return 0;
	else 
		return i+1;
} 

//建立
int CreateList_Seq(SeqList *L){
	int i, n;
	printf("�����볤��n: ");
	scanf("%d", &n);
	
	if(n < 1|| n > maxsize){
		printf("���Ȳ�����\n");
		return 0;
	}
	
	printf("�������Ԫ�ص�ֵ\n");
	for(i = 0; i < n; i++)
		scanf("%d", &L->sequence[i]);
		
		L->length=n;
		return 1;
}


//输出
void PrintList_Seq(SeqList L){
    printf("˳������ݣ�");
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.sequence[i]);
    }
    printf("\n");
}

int main(){
	SeqList L;
	int i;
	DataType x;
	
	InitList_Seq(&L);
	
	ListInsert_Seq(&L, 1, 10);
	ListInsert_Seq(&L, 2, 20);
	ListInsert_Seq(&L, 3, 30);
	
	PrintList_Seq(L);
	return 0;
} 

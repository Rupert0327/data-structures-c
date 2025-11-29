#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1000     
#define DataType int

typedef struct {
    DataType data;   
    int next;        
} SNode;

typedef struct {
    SNode nodes[MAXSIZE];  
    int head;               //下标
    int free;
} SLinkList;

// 初始化静态链表空间
void InitSpace(SLinkList *space) {
    for (int i = 0; i < MAXSIZE - 1; i++) {
        space->nodes[i].next = i + 1;  // 将所有结点连成备用链表
    }
    space->nodes[MAXSIZE - 1].next = -1; // -1 表示空
    space->head = -1;  // 空链表
    space->free = 0;   // 空闲链表起点为 0
}

// 分配结点
int Malloc_SL(SLinkList *space) {
    int i = space->free;
    if (i != -1) {
        space->free = space->nodes[i].next;
    }
    return i;
}

// 释放结点（相当于 free）
void Free_SL(SLinkList *space, int index) {
    space->nodes[index].next = space->free;
    space->free = index;
}

// 头插法建立链表
void CreateListHead(SLinkList *space, int n) {
    space->head = -1;
    for (int i = 0; i < n; i++) {
        int idx = Malloc_SL(space);
        if (idx == -1) {
            printf("空间不足！\n");
            return;
        }
        printf("请输入第%d个元素: ", i + 1);
        scanf("%d", &space->nodes[idx].data);
        space->nodes[idx].next = space->head;
        space->head = idx;
    }
}

// 按位置插入元素（第i个位置前插入）
int Insert_SL(SLinkList *space, int i, DataType e) {
    if (i < 1) return 0;

    int newNode = Malloc_SL(space);
    if (newNode == -1) return 0;

    space->nodes[newNode].data = e;

    if (i == 1) { // 插入到表头
        space->nodes[newNode].next = space->head;
        space->head = newNode;
        return 1;
    }

    int p = space->head;
    for (int j = 1; j < i - 1 && p != -1; j++) {
        p = space->nodes[p].next;
    }

    if (p == -1) return 0;

    space->nodes[newNode].next = space->nodes[p].next;
    space->nodes[p].next = newNode;
    return 1;
}

// 按位置删除元素
int Delete_SL(SLinkList *space, int i) {
    if (space->head == -1 || i < 1) return 0;

    int q;
    if (i == 1) {
        q = space->head;
        space->head = space->nodes[q].next;
        Free_SL(space, q);
        return 1;
    }

    int p = space->head;
    for (int j = 1; j < i - 1 && p != -1; j++) {
        p = space->nodes[p].next;
    }

    if (p == -1 || space->nodes[p].next == -1) return 0;

    q = space->nodes[p].next;
    space->nodes[p].next = space->nodes[q].next;
    Free_SL(space, q);
    return 1;
}

// 查找值为 e 的元素位置
int LocateElem_SL(SLinkList space, DataType e) {
    int p = space.head;
    int index = 1;
    while (p != -1) {
        if (space.nodes[p].data == e) return index;
        p = space.nodes[p].next;
        index++;
    }
    return 0;
}

// 输出链表
void PrintList_SL(SLinkList space) {
    int p = space.head;
    printf("链表内容: ");
    while (p != -1) {
        printf("%d ", space.nodes[p].data);
        p = space.nodes[p].next;
    }
    printf("\n");
}

//========================= 主函数测试 =========================//

int main() {
    SLinkList list;
    InitSpace(&list);

    int n;
    printf("请输入要创建的元素个数: ");
    scanf("%d", &n);
    CreateListHead(&list, n);

    PrintList_SL(list);

    printf("在第2个位置插入99...\n");
    Insert_SL(&list, 2, 99);
    PrintList_SL(list);

    printf("删除第3个元素...\n");
    Delete_SL(&list, 3);
    PrintList_SL(list);

    int pos = LocateElem_SL(list, 99);
    if (pos)
        printf("元素99在第%d个位置。\n", pos);
    else
        printf("未找到元素99。\n");

    return 0;
}
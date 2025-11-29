#include<stdio.h>

#define MAX_SIZE 7

typedef struct {
    int Data[MAX_SIZE];
    int size;
} SeqCBT, *PSeqCBT;

void InitSeqCBT(PSeqCBT T) {
    T->size = 0;
}

int IsFull(SeqCBT T) {
    return T.size == MAX_SIZE;
}

void InsertSeqCBT(PSeqCBT T, int value) {
    if (IsFull(*T)) {
        printf("The tree is full!\n");
        return;
    }
    T->Data[T->size++] = value;
}

void PreOrder(PSeqCBT T, int index) {
    if (index >= T->size) return;
    printf("%d ", T->Data[index]);
    PreOrder(T, 2 * index + 1);
    PreOrder(T, 2 * index + 2);
}

int main() {
    SeqCBT tree;
    InitSeqCBT(&tree);

    InsertSeqCBT(&tree, 1);
    InsertSeqCBT(&tree, 2);
    InsertSeqCBT(&tree, 3);
    InsertSeqCBT(&tree, 4);
    InsertSeqCBT(&tree, 5);
    InsertSeqCBT(&tree, 6);
    InsertSeqCBT(&tree, 7);

    printf("Pre-order Traversal of Sequential Complete Binary Tree:\n");
    PreOrder(&tree, 0);
    printf("\n");

    return 0;
}
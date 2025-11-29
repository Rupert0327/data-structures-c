#include<stdio.h>
#include<stdlib.h>

#define MaxSize 5

typedef struct CircularQueue {
    int data[MaxSize];
    int front;
    int rear;
} CircularQueue;

void InitQueue(CircularQueue* Q) {
    Q->front = Q->rear = 0;
}

int IsEmpty(CircularQueue Q) {
    return Q.front == Q.rear;
}

int IsFull(CircularQueue Q) {
    return (Q.rear + 1) % MaxSize == Q.front;
}

void EnQueue(CircularQueue* Q) {
    int x;
    printf("Please enter the value of the element:\n");
    scanf("%d", &x);
    if (IsFull(*Q)) {
        printf("The queue is full!\n");
        return;
    }
    Q->data[Q->rear] = x;
    Q->rear = (Q->rear + 1) % MaxSize;
}

void DeQueue(CircularQueue* Q) {
    int x;
    if (IsEmpty(*Q)) {
        printf("The queue is empty!\n");
        return;
    }
    x = Q->data[Q->front];
    Q->front = (Q->front + 1) % MaxSize;
    printf("Dequeued element: %d\n", x);
}

int QueueLength(CircularQueue Q) {
    return (Q.rear - Q.front + MaxSize) % MaxSize;
}

void TraverseQueue(CircularQueue Q) {
    if (IsEmpty(Q)) {
        printf("The queue is empty!\n");
        return;
    }
    printf("Queue elements are:\n");
    for (int i = Q.front; i != Q.rear; i = (i + 1) % MaxSize) {
        printf("%d ", Q.data[i]);
    }
    printf("\n");
}

void ClearQueue(CircularQueue* Q) {Q->front = Q->rear = 0;}

void GetFront(CircularQueue Q) {
    if (IsEmpty(Q)) {
        printf("The queue is empty!\n");
        return;
    }
    printf("Front element: %d\n", Q.data[Q.front]);
}

void GetRear(CircularQueue Q) {
    if (IsEmpty(Q)) {
        printf("The queue is empty!\n");
        return;
    }
    int rearIndex = (Q.rear - 1 + MaxSize) % MaxSize;
    printf("Rear element: %d\n", Q.data[rearIndex]);
}

int main() {
    CircularQueue Q;
    InitQueue(&Q);

    EnQueue(&Q);
    EnQueue(&Q);
    EnQueue(&Q);
    EnQueue(&Q);
    EnQueue(&Q);

    DeQueue(&Q);

    GetFront(Q);
    GetRear(Q);

    TraverseQueue(Q);

    if (IsFull(Q))
        printf("The queue is full now.\n");
    if (IsEmpty(Q))
        printf("The queue is empty now.\n");
    

    ClearQueue(&Q);
    return 0;
}
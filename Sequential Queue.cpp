#include<stdio.h>
#include<stdlib.h>

#define MaxSize 5

typedef struct QueueNode {
    int data[MaxSize];
    int front;
    int rear;
} QueueNode;

void InitQueue(QueueNode *Q){Q->front = Q->rear = 0;}

int IsEmpty(QueueNode Q){return Q.front == Q.rear;}

int IsFull(QueueNode Q){return Q.rear == MaxSize;}

void EnQueue(QueueNode *Q){
    int x;
    printf("Please enter the value of the element:\n");
    scanf("%d", &x);
    if (IsFull(*Q)){
        printf("The queue is full!\n");
        return;
    }
    Q->data[Q->rear++] = x;
}

void DeQueue(QueueNode *Q){
    int x;
    if (IsEmpty(*Q)){
        printf("The queue is empty!\n");
        return;
    }
    x = Q->data[Q->front++];
    printf("Dequeued element: %d\n", x);
}

int QueueLength(QueueNode Q){return Q.rear - Q.front;}

void TraverseQueue(QueueNode Q){
    if (IsEmpty(Q)){
        printf("The queue is empty!\n");
        return;
    }
    printf("Queue elements are:\n");
    for (int i = Q.front; i < Q.rear; i++){
        printf("%d ", Q.data[i]);
    }
    printf("\n");
}

void ClearQueue(QueueNode *Q){Q->front = Q->rear = 0;}


void GetFront(QueueNode Q){
    if (IsEmpty(Q)){
        printf("The queue is empty!\n");
        return;
    }
    printf("Front element: %d\n", Q.data[Q.front]);
}

void GetRear(QueueNode Q){
    if (IsEmpty(Q)){
        printf("The queue is empty!\n");
        return;
    }
    printf("Rear element: %d\n", Q.data[Q.rear - 1]);
}

int main(){
    QueueNode Q;
    InitQueue(&Q);
    
    EnQueue(&Q);
    EnQueue(&Q);
    EnQueue(&Q);
    EnQueue(&Q);
    EnQueue(&Q);
    EnQueue(&Q);

    DeQueue(&Q);
    TraverseQueue(Q);
    printf("Queue length after dequeue: %d\n", QueueLength(Q));

    GetFront(Q);
    GetRear(Q);
    ClearQueue(&Q);
    TraverseQueue(Q);
    return 0;
}
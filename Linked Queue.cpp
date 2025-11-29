#include<stdio.h>
#include<stdlib.h>

typedef struct QNode {
    int data;
    struct QNode *next;
} QNode, *QueuePtr;

typedef struct {
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;


void InitQueue(LinkQueue *Q) {
    Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
    if (!Q->front)
        return;
    Q->front->next = NULL;
}

int IsEmpty(LinkQueue Q) {
    return Q.front == Q.rear;
}

void EnQueue(LinkQueue *Q) {
    int x;
    printf("Please enter the value of the element:\n");
    scanf("%d", &x);
    //s is a new node
    QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
    if (!s)
        return;
    s->data = x;
    s->next = NULL;
    Q->rear->next = s;
    Q->rear = s;
}

void DeQueue(LinkQueue *Q) {
    if (IsEmpty(*Q)) {
        printf("The queue is empty!\n");
        return;
    }
    QueuePtr p = Q->front->next;
    int x = p->data;
    Q->front->next = p->next;
    if (Q->rear == p)
        Q->rear = Q->front;
    free(p);
    printf("Dequeued element: %d\n", x);
}

int QueueLength(LinkQueue Q) {
    int length = 0;
    QueuePtr p = Q.front->next;
    while (p) {
        length++;
        p = p->next;
    }
    return length;
}

void TraverseQueue(LinkQueue Q) {
    if (IsEmpty(Q)) {
        printf("The queue is empty!\n");
        return;
    }
    printf("Queue elements are:\n");
    QueuePtr p = Q.front->next;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void ClearQueue(LinkQueue *Q) {
    QueuePtr p, q;
    p = Q->front->next;
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
    Q->front->next = NULL;
    Q->rear = Q->front;
}

void GetFront(LinkQueue Q) {
    if (IsEmpty(Q)) {
        printf("The queue is empty!\n");
        return;
    }
    printf("Front element: %d\n", Q.front->next->data);
}

void GetRear(LinkQueue Q) {
    if (IsEmpty(Q)) {
        printf("The queue is empty!\n");
        return;
    }
    printf("Rear element: %d\n", Q.rear->data);
}

int main() {
    LinkQueue Q;
    InitQueue(&Q);

    EnQueue(&Q);
    EnQueue(&Q);
    EnQueue(&Q);
    EnQueue(&Q);

    TraverseQueue(Q);

    ClearQueue(&Q);

    return 0;
}
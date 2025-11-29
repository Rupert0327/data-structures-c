#include<stdio.h>

#define MAX 100


typedef struct {
    int data[MAX];
    int size;
}MinHeap;

void InitHeap(MinHeap* heap) {
    heap->size = 0;
}

int IsFull(MinHeap* heap) {
    return heap->size == MAX;
}

int IsEmpty(MinHeap* heap) {
    return heap->size == 0;
}

void ShiftUp(MinHeap* heap, int index) {
    while (index > 0) 
    {
        int parent = (index - 1) / 2;
        if (heap->data[parent] > heap->data[index]) {

            //change parent and current node
            int temp = heap->data[parent];
            heap->data[parent] = heap->data[index];
            heap->data[index] = temp;

            index = parent;
        } else break;
    }
}

void ShiftDown(MinHeap* heap, int index) {
    while (1)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        //Find the smallest among index, left and right
        if (left < heap->size && heap->data[left] < heap->data[smallest]) {
            smallest = left;
        }
        if (right < heap->size && heap->data[right] < heap->data[smallest]) {
            smallest = right;
        }

        //If smallest is not index, swap and continue downwards
        if (smallest != index) {
            int temp = heap->data[index];
            heap->data[index] = heap->data[smallest];
            heap->data[smallest] = temp;

            index = smallest;
        } else break;
    }
}

void Insert(MinHeap* heap, int value) {
    if (IsFull(heap)) {
        printf("Heap is full\n");
        return;
    }
    int i = heap->size++;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap->data[parent] <= value) 
            break;
        heap->data[i] = heap->data[parent];
        i = parent;
    }
    heap->data[i] = value;
}

void GetMin(MinHeap* heap) {
    if (IsEmpty(heap)) {
        printf("Heap is empty\n");
        return; // Indicate error
    }
    printf("Min element: %d\n", heap->data[0]);
}

int DeleteMin(MinHeap* heap) {
    if (IsEmpty(heap))
    {
        printf("Heap is empty\n");
        return -1; // Indicate error
    }
    
    int min_value = heap->data[0];
    heap->data[0] = heap->data[--heap->size];
    ShiftDown(heap, 0);
    return min_value;
}

void PrintHeap(MinHeap* heap) {
    printf("Min Heap elements: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->data[i]);
    }
    printf("\n");
}

int main() {
    MinHeap heap;
    InitHeap(&heap);

    Insert(&heap, 30);
    Insert(&heap, 20);
    Insert(&heap, 40);
    Insert(&heap, 10);
    Insert(&heap, 25);
    PrintHeap(&heap);

    GetMin(&heap);

    printf("Deleting min element: %d\n", DeleteMin(&heap));
    PrintHeap(&heap);

    return 0;
}
#include<stdio.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int size;
}MaxHeap;

void InitHeap(MaxHeap* heap) {
    heap->size = 0;
}

int IsFull(MaxHeap* heap) {
    return heap->size == MAX;
}

int IsEmpty(MaxHeap* heap) {
    return heap->size == 0;
}

void ShiftUp(MaxHeap* heap, int index) {
    int temp = heap->data[index];
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap->data[parent] >= temp) 
            break;
        heap->data[index] = heap->data[parent];
        index = parent;
    }
    heap->data[index] = temp;
}

//This version of ShiftUp below is easier to understand

// void ShiftUp(MaxHeap *heap, int index) {
//     while (index > 0) 
//     {
//         int parent = (index - 1) / 2;
//         if (heap->data[parent] < heap->data[index]) {

//             //change parent and current node
//             int temp = heap->data[parent];
//             heap->data[parent] = heap->data[index];
//             heap->data[index] = temp;

//             index = parent;
//         } else break;
//     }
// }

void ShiftDown(MaxHeap* heap, int index) {
    int temp = heap->data[index];
    int child;
    while (2 * index + 1 < heap->size) {
        child = 2 * index + 1;
        if (child + 1 < heap->size && heap->data[child + 1] > heap->data[child]) {
            child++;
        }
        if (temp >= heap->data[child]) 
            break;
        heap->data[index] = heap->data[child];
        index = child;
    }
    heap->data[index] = temp;
}

//This version of ShiftDown below is easier to understand

// void ShiftDown(MaxHeap* heap, int index){
//     while (1)
//     {
//         int left = 2 * index + 1;
//         int right = 2 * index + 2;
//         int largest = index;

//         //Find the largest among index, left and right
//         if (left < heap->size && heap->data[left] > heap->data[largest]) {
//             largest = left;
//         }
//         if (right < heap->size && heap->data[right] > heap->data[largest]) {
//             largest = right;
//         }

//         //If largest is not index, swap and continue downwards
//         if (largest != index) {
//             int temp = heap->data[index];
//             heap->data[index] = heap->data[largest];
//             heap->data[largest] = temp;

//             index = largest;
//         } else break;
//     }
// }

void Insert(MaxHeap* heap, int value) {
    if (IsFull(heap)) {
        printf("Heap is full\n");
        return;
    }
    int i = heap->size++;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap->data[parent] >= value) 
            break;
        heap->data[i] = heap->data[parent];
        i = parent;
    }
    heap->data[i] = value;
}

// void Insert(MaxHeap* heap, int value) {
//     if (IsFull(heap)) {
//         printf("Heap is full\n");
//         return;
//     }
//     heap->data[heap->size] = value;
//     ShiftUp(heap, heap->size);
//     heap->size++;
// }

void GetMax(MaxHeap* heap) {
    if (IsEmpty(heap)) {
        printf("Heap is empty\n");
        return; // Indicate error
    }
    printf("Max element: %d\n", heap->data[0]);
}

int DeleteMax(MaxHeap* heap) {
    if (IsEmpty(heap)) {
        printf("Heap is empty\n");
        return -1; // Indicate error
    }

    int max_value = heap->data[0];
    heap->data[0] = heap->data[--heap->size];

    ShiftDown(heap, 0);
    return max_value;
}

// int DeleteMax(MaxHeap* heap) {
//     if (IsEmpty(heap))
//     {
//         printf("Heap is empty\n");
//         return -1; // Indicate error
//     }
    
//     int MaxValue = heap->data[0];
//     int lastValue = heap->data[--heap->size];
//     int i = 0;
//     int child;
//     while (2 * i + 1 < heap->size) {
//         child = 2 * i + 1;
//         if (child + 1 < heap->size && heap->data[child + 1] > heap->data[child]) {
//             child++;
//         }
//         if (lastValue >= heap->data[child]) 
//             break;
//         heap->data[i] = heap->data[child];
//         i = child;
//     }
//     heap->data[i] = lastValue;
//     return MaxValue;
// }



void PrintHeap(MaxHeap* heap) {
    printf("Max Heap elements: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->data[i]);
    }
    printf("\n");
}

int main() {
    MaxHeap heap;
    InitHeap(&heap);

    Insert(&heap, 10);
    Insert(&heap, 20);
    Insert(&heap, 5);
    Insert(&heap, 30);
    Insert(&heap, 15);

    PrintHeap(&heap);

    printf("This operation is just to get the max element:\n");
    GetMax(&heap);

    printf("This operation is to delete the max element, \n");
    printf("At the same time, print the deleted max element:%d\n", DeleteMax(&heap));

    printf("After deletion:\n");
    PrintHeap(&heap);

    return 0;
}
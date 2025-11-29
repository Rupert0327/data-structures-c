#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 256

// Definition of HaffmanNode structure
typedef struct HaffmanNode {
    unsigned char data;
    int weight;
    struct HaffmanNode *left, *right;
} HaffmanNode;

// Definition of MinHeap structure
typedef struct {
    HaffmanNode **nodes;
    int size;
    int capacity;
} MinHeap;

void swap(HaffmanNode **a, HaffmanNode **b) {
    HaffmanNode *temp = *a;
    *a = *b;
    *b = temp;
}

void ShiftUp(MinHeap *heap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap->nodes[index]->weight < heap->nodes[parent]->weight) {
            swap(&heap->nodes[index], &heap->nodes[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

void ShiftDown(MinHeap *heap, int index) {
    int left, right, smallest;
    while (1) {
        left = 2 * index + 1;
        right = 2 * index + 2;
        smallest = index;

        if (left < heap->size && heap->nodes[left]->weight < heap->nodes[smallest]->weight) {
            smallest = left;
        }
        if (right < heap->size && heap->nodes[right]->weight < heap->nodes[smallest]->weight) {
            smallest = right;
        }
        if (smallest != index) {
            swap(&heap->nodes[index], &heap->nodes[smallest]);
            index = smallest;
        } else {
            break;
        }
    }
}

void InsertMinHeap(MinHeap *heap, HaffmanNode *node) {
    if (heap->size >= heap->capacity) return;
    heap->nodes[heap->size] = node;
    ShiftUp(heap, heap->size);
    heap->size++;
}
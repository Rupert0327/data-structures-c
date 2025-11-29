// // #include <stdio.h>
// // #include <stdlib.h>

// // #define MAX_SIZE 100

// // // ==================== 堆结构 ====================
// // typedef struct {
// //     int data[MAX_SIZE];
// //     int size;              // 当前元素个数
// // } MaxHeap;

// // // ==================== 初始化堆 ====================
// // void InitHeap(MaxHeap *H) {
// //     H->size = 0;
// // }

// // // ==================== 判断是否为空/满 ====================
// // int IsEmpty(MaxHeap H) {
// //     return H.size == 0;
// // }

// // int IsFull(MaxHeap H) {
// //     return H.size == MAX_SIZE;
// // }

// // // ==================== 上滤（插入时用） ====================
// // void ShiftUp(MaxHeap *H, int idx) {
// //     while (idx > 0) {
// //         int parent = (idx - 1) / 2;
// //         if (H->data[parent] < H->data[idx]) {
// //             // 交换父节点与当前节点
// //             int temp = H->data[parent];
// //             H->data[parent] = H->data[idx];
// //             H->data[idx] = temp;

// //             idx = parent;
// //         } else {
// //             break;
// //         }
// //     }
// // }

// // // ==================== 插入元素 ====================
// // void Insert(MaxHeap *H, int value) {
// //     if (IsFull(*H)) {
// //         printf("Heap is full!\n");
// //         return;
// //     }

// //     H->data[H->size] = value;   // 新元素放到末尾
// //     ShiftUp(H, H->size);        // 上滤调整
// //     H->size++;
// // }

// // // ==================== 下滤（删除堆顶时用） ====================
// // void ShiftDown(MaxHeap *H, int idx) {
// //     int left, right, largest;

// //     while (1) {
// //         left = 2 * idx + 1;
// //         right = 2 * idx + 2;
// //         largest = idx;

// //         // 找到左右孩子中较大的
// //         if (left < H->size && H->data[left] > H->data[largest]) {
// //             largest = left;
// //         }
// //         if (right < H->size && H->data[right] > H->data[largest]) {
// //             largest = right;
// //         }

// //         // 如果孩子比父亲大，交换
// //         if (largest != idx) {
// //             int temp = H->data[idx];
// //             H->data[idx] = H->data[largest];
// //             H->data[largest] = temp;

// //             idx = largest;
// //         } else {
// //             break;
// //         }
// //     }
// // }

// // // ==================== 删除堆顶（最大值） ====================
// // int RemoveMax(MaxHeap *H) {
// //     if (IsEmpty(*H)) {
// //         printf("Heap is empty!\n");
// //         return -1;
// //     }

// //     int max_value = H->data[0];
// //     H->data[0] = H->data[H->size - 1]; // 用最后元素替代堆顶
// //     H->size--;

// //     ShiftDown(H, 0); // 下滤调整
// //     return max_value;
// // }

// // // ==================== 打印堆 ====================
// // void PrintHeap(MaxHeap H) {
// //     printf("Heap: ");
// //     for (int i = 0; i < H.size; i++) {
// //         printf("%d ", H.data[i]);
// //     }
// //     printf("\n");
// // }

// // // ==================== 测试 ====================
// // int main() {
// //     MaxHeap H;
// //     InitHeap(&H);

// //     Insert(&H, 30);
// //     Insert(&H, 10);
// //     Insert(&H, 50);
// //     Insert(&H, 40);
// //     Insert(&H, 60);

// //     PrintHeap(H);

// //     printf("Remove max: %d\n", RemoveMax(&H));
// //     PrintHeap(H);

// //     return 0;
// // }


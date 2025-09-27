#include <stdio.h>

#define MAX 100

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void heapifyUp(int heap[], int index) {
    while (index > 0 && heap[(index - 1) / 2] < heap[index]) {
        swap(heap, (index - 1) / 2, index);
        index = (index - 1) / 2;
    }
}

void heapifyDown(int heap[], int size, int index) {
    int largest = index;
    int left = 2 * index + 1, right = 2 * index + 2;

    if (left < size && heap[left] > heap[largest])
        largest = left;
    if (right < size && heap[right] > heap[largest])
        largest = right;

    if (largest != index) {
        swap(heap, index, largest);
        heapifyDown(heap, size, largest);
    }
}

int insert(int heap[], int size, int value) {
    heap[size] = value;
    heapifyUp(heap, size);
    return size + 1;
}

int extractMax(int heap[], int size) {
    if (size == 0) return size;

    heap[0] = heap[size - 1];
    heapifyDown(heap, size - 1, 0);
    return size - 1;
}

void display(int heap[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    int heap[MAX];
    int size = 0;
    int values[] = {50, 30, 20, 15, 10, 8, 16};

    for (int i = 0; i < 7; i++)
        size = insert(heap, size, values[i]);

    printf("Max Heap: ");
    display(heap, size);

    size = extractMax(heap, size);

    printf("After extractMax: ");
    display(heap, size);

    return 0;
}

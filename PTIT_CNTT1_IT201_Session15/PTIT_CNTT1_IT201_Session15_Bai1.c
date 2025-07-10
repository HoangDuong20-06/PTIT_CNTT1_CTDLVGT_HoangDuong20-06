#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    int front;
    int rear;
    int capacity;
} Queue;
Queue* createQueue(int maxSize) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->array = (int*)malloc(sizeof(int) * maxSize);
    q->capacity = maxSize;
    q->front = 0;
    q->rear = -1;
    return q;
}
void printQueueInfo(Queue* q) {
    printf("Front: %d\n", q->front);
    printf("Rear: %d\n", q->rear);
    printf("Capacity: %d\n", q->capacity);
    printf("Array: [");
    for (int i = 0; i < q->capacity; i++) {
        printf("%d", q->array[i]);
        if (i < q->capacity - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    int maxSize;
    Queue* q = createQueue(maxSize);
    printQueueInfo(q);
    free(q->array);
    free(q);
    return 0;
}

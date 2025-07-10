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
int enqueue(Queue* q, int value) {
    if (q->rear >= q->capacity - 1) {
        printf("Queue is full!\n");
        return 0;
    }
    q->rear++;
    q->array[q->rear] = value;
    return 1;
}
void printQueueInfo(Queue* q) {
    printf("Front: %d\n", q->front);
    printf("Rear: %d\n", q->rear);
    printf("Capacity: %d\n", q->capacity);
    printf("Array: [");
    for (int i = 0; i <= q->rear; i++) {
        printf("%d", q->array[i]);
        if (i < q->rear) printf(", ");
    }
    printf("]\n");
}

int main() {
    int maxSize = 5;
    Queue* q = createQueue(maxSize);
    int value;
    while (1) {
        printf("Nhap phan tu: ");
        scanf("%d", &value);

        if (value== -1 ) {
            break;
        }
        if (!enqueue(q, value)) {
            break;
        }
        printQueueInfo(q);
    }
    free(q->array);
    free(q);
    return 0;
}
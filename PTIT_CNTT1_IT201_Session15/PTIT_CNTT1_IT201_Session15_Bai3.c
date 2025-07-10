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
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d", q->array[i]);
        if (i < q->rear) printf(", ");
    }
    printf("]\n\n");
}
int isEmpty(Queue* q) {
    if (q->rear < q->front){
        printf("True\n");
        return 0;
    }if (q-> rear >= q->front) {
        printf("False\n");
        return 0;
    }
}
void enqueue(Queue* q, int value) {
    if (q->rear >= q->capacity - 1) {
        printf("Queue is full!\n");
        return;
    }
    q->rear++;
    q->array[q->rear] = value;
}
int main() {
    int maxSize = 5;
    Queue* q = createQueue(maxSize);
    printQueueInfo(q);
    isEmpty(q);
    free(q->array);
    free(q);
    return 0;
}

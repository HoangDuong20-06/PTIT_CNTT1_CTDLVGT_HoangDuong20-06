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

void enqueue(Queue* q, int value) {
    if (q->rear >= q->capacity - 1) {
        printf("Queue is full!\n");
        return;
    }
    q->rear++;
    q->array[q->rear] = value;
}

int dequeue(Queue* q) {
    if (q->rear < q->front) {
        return -1;
    }
    int value = q->array[q->front];
    q->front++;
    return value;
}

int check(Queue* q) {
    for (int i = q->front; i < q->rear; i++) {
        if (q->array[i + 1] - q->array[i] != 1) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    Queue* q = createQueue(n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        enqueue(q, x);
    }

    if (check(q)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    free(q->array);
    free(q);
    return 0;
}

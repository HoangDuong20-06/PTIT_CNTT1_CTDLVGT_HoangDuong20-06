#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;
typedef struct {
    Node* front;
    Node* rear;
} Queue;
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Khong the cap phat bo nho.\n");
        exit(1);
    }
    q->front = NULL;
    q->rear = NULL;
    return q;
}
int main() {
    Queue* q = createQueue();
    if (q->front == NULL && q->rear == NULL) {
        printf("Hang trong (front -> NULL, rear -> NULL).\n");
    }
    free(q);
    return 0;
}
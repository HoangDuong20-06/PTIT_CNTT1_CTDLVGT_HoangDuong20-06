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
Node* createNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->next = NULL;
    return node;
}
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}
void enqueue(Queue* q, int value) {
    Node* node = createNode(value);
    if (q->rear == NULL) {
        q->front = node;
        q->rear = node;
    } else {
        q->rear->next = node;
        q->rear = node;
    }
}
void printQueue(Queue* q) {
    printf("queue = { front->");
    Node* cur = q->front;
    while (cur != NULL) {
        printf("%d->", cur->data);
        cur = cur->next;
    }
    printf("NULL,\nrear->");
    if (q->rear != NULL)
        printf("%d->NULL", q->rear->data);
    else
        printf("NULL");
    printf(" }\n");
}
int main() {
    Queue* q = createQueue();
    printQueue(q);
    int value;
    printf("Nhap gia tri can them: ");
    scanf("%d", &value);
    enqueue(q, value);
    printQueue(q);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 5);
    enqueue(q, 3);
    printQueue(q);
    Node* tmp;
    while (q->front != NULL) {
        tmp = q->front;
        q->front = q->front->next;
        free(tmp);
    }
    free(q);
    return 0;
}
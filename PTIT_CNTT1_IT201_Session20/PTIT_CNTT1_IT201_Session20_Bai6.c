#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;
Node* createNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}
typedef struct QueueNode {
    Node* data;
    struct QueueNode* next;
} QueueNode;
typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;
void enqueue(Queue* q, Node* node) {
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->data = node;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
}
Node* dequeue(Queue* q) {
    if (q->front == NULL) return NULL;
    QueueNode* temp = q->front;
    Node* result = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return result;
}
int isEmpty(Queue* q) {
    return q->front == NULL;
}
int findLevel(Node* root, int targetValue) {
    if (root == NULL) return -1;
    Queue q = {NULL, NULL};
    enqueue(&q, root);
    int level = 0;
    while (!isEmpty(&q)) {
        int size = 0;
        QueueNode* temp = q.front;
        while (temp) {
            size++;
            temp = temp->next;
        }
        for (int i = 0; i < size; i++) {
            Node* current = dequeue(&q);
            if (current->data == targetValue)
                return level;
            if (current->left) enqueue(&q, current->left);
            if (current->right) enqueue(&q, current->right);
        }

        level++;
    }
    return -1;
}
int main() {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);
    int value = 2;
    int level = findLevel(root, value);
    if (level != -1)
        printf("Node level: %d\n", level);
    else
        printf("Node not found\n");
    return 0;
}
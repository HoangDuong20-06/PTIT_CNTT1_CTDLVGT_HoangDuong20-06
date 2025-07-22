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
void insertNode(Node* root, int value) {
    if (root == NULL) return;

    Queue q = {NULL, NULL};
    enqueue(&q, root);
    while (!isEmpty(&q)) {
        Node* current = dequeue(&q);

        if (current->left == NULL) {
            current->left = createNode(value);
            return;
        } else {
            enqueue(&q, current->left);
        }

        if (current->right == NULL) {
            current->right = createNode(value);
            return;
        } else {
            enqueue(&q, current->right);
        }
    }
}
void levelOrder(Node* root) {
    if (root == NULL) return;
    Queue q = {NULL, NULL};
    enqueue(&q, root);
    while (!isEmpty(&q)) {
        Node* current = dequeue(&q);
        printf("%d ", current->data);
        if (current->left) enqueue(&q, current->left);
        if (current->right) enqueue(&q, current->right);
    }
    printf("\n");
}
int main() {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);
    int newValue;
    printf("Nhap gia tri muon them: ");
    scanf("%d", &newValue);
    insertNode(root, newValue);
    printf("After insert: ");
    levelOrder(root);
    return 0;
}

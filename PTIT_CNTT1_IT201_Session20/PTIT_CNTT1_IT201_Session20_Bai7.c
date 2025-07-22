#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* createNode(int val) {
    Node* node = malloc(sizeof(Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}
typedef struct Queue {
    Node* data[100];
    int front, rear;
} Queue;
void initQueue(Queue* q) {
    q->front = q->rear = 0;
}
void enqueue(Queue* q, Node* node) {
    q->data[q->rear++] = node;
}
Node* dequeue(Queue* q) {
    return q->data[q->front++];
}
int isEmpty(Queue* q) {
    return q->front == q->rear;
}
int deleteNode(Node* root, int val) {
    if (!root) return 0;
    Queue q;
    initQueue(&q);
    enqueue(&q, root);
    Node *target = NULL, *last = NULL, *parent = NULL;
    while (!isEmpty(&q)) {
        Node* cur = dequeue(&q);
        if (cur->data == val) target = cur;
        if (cur->left) {
            parent = cur;
            enqueue(&q, cur->left);
        }
        if (cur->right) {
            parent = cur;
            enqueue(&q, cur->right);
        }
        last = cur;
    }
    if (!target) {
        printf("Khong tim thay gia tri %d\n", val);
        return 0;
    }
    target->data = last->data;
    if (parent && parent->right == last) parent->right = NULL;
    else if (parent && parent->left == last) parent->left = NULL;

    free(last);
    return 1;
}
void print(Node* root) {
    if (!root) return;
    Queue q;
    initQueue(&q);
    enqueue(&q, root);
    while (!isEmpty(&q)) {
        Node* cur = dequeue(&q);
        printf("%d ", cur->data);
        if (cur->left) enqueue(&q, cur->left);
        if (cur->right) enqueue(&q, cur->right);
    }
    printf("\n");
}
int main() {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);
    root->left->right = createNode(6);
    printf("Truoc khi xoa: ");
    print(root);
    int x;
    printf("Nhap gia tri muon xoa: ");
    scanf("%d", &x);
    if (deleteNode(root, x)) {
        printf("Sau khi xoa: ");
        print(root);
    }
    return 0;
}
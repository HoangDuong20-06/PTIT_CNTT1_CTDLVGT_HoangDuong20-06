#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
bool findValueBFS(Node* root, int value) {
    if (root == NULL) return false;
    Node* queue[100];
    int front = 0;
    int rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        Node* current = queue[front++];
        if (current->data == value) return true;
        if (current->left != NULL) queue[rear++] = current->left;
        if (current->right != NULL) queue[rear++] = current->right;
    }

    return false;
}
int main() {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);
    int target = 6;
    if (findValueBFS(root, target)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    return 0;
}
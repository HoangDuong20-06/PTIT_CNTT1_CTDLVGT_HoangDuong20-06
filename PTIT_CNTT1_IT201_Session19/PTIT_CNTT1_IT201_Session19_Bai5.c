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
bool findValueDFS(Node* root, int value) {
    if (root == NULL) return false;
    if (root->data == value) return true;
    return findValueDFS(root->left, value) || findValueDFS(root->right, value);
}
int main() {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);
    int target = 7;
    if (findValueDFS(root, target)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    return 0;
}
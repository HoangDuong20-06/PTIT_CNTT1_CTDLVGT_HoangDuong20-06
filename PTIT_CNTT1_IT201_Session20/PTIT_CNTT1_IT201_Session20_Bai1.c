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

void printNode(Node* node) {
    printf("node = {\n");
    printf("  data: %d,\n", node->data);

    if (node->left == NULL) {
        printf("  left->NULL,\n");
    } else {
        printf("  left->NOT NULL,\n");
    }
    if (node->right == NULL) {
        printf("  right->NULL\n");
    } else {
        printf("  right->NOT NULL\n");
    }

    printf("}\n");
}


int main() {
    int value=5;
    Node* node = createNode(value);
    printNode(node);
    return 0;
}
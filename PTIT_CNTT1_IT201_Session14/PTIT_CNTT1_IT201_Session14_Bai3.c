#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;
typedef struct {
    Node* top;
} Stack;
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
void initStack(Stack* stack) {
    stack->top = NULL;
}
void push(Stack* stack, int value) {
    Node* newNode = createNode(value);
    newNode->next = stack->top;
    stack->top = newNode;
}
void printStack(Stack stack) {
    if (stack.top == NULL) {
        printf("Ngan xep trong\n");
        return;
    }
    Node* temp = stack.top;
    printf("Cac phan tu trong ngan xep:\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    Stack stack;
    initStack(&stack);
    int value;
    printf("Nhap so luong phan tu can them vao stack: ");
    int n;
    scanf("%d", &n);
    printf("Nhap %d phan tu:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        push(&stack, value);
    }
    printStack(stack);
    return 0;
}

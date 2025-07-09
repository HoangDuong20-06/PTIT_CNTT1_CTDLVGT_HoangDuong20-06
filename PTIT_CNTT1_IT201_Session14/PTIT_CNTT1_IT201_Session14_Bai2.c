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

void push(Stack* stack, int value) {
    Node* newNode = createNode(value);
    newNode->next = stack->top;
    stack->top = newNode;
}
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

void printStack(Stack stack) {
    if (stack.top == NULL) {
        printf("Stack rong!\n");
        return;
    }

    Node* temp = stack.top;
    printf("stack = { ");
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL }\n");
}

int main() {
    Stack stack;
    stack.top = NULL;

    if (isEmpty(&stack)) {
        printf("Stack ban dau rong!\n");
        return 0;
    }

    push(&stack, 5);
    push(&stack, 4);
    push(&stack, 3);
    push(&stack, 2);
    push(&stack, 1);
    int x;
    printf("Nhap phan tu muon them vao stack: ");
    scanf("%d", &x);
    push(&stack, x);

    printf("Stack sau khi them phan tu:\n");
    printStack(stack);

    return 0;
}

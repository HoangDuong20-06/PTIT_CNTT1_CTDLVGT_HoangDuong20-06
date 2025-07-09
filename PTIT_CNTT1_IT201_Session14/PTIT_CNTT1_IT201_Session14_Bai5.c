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
    Node* temp = stack.top;
    printf("stack = { ");
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL }\n");
}
int peek(Stack stack) {
    if (stack.top == NULL) {
        printf("Ngan xep trong\n");
        return -1;
    }
    return stack.top->data;
}

int main() {
    Stack stack;
    initStack(&stack);
    push(&stack, 5);
    push(&stack, 4);
    push(&stack, 3);
    push(&stack, 2);
    push(&stack, 1);
    printStack(stack);
    int topValue = peek(stack);
    if (topValue != -1)
        printf("Phan tu tren dinh stack: %d\n", topValue);
    return 0;
}
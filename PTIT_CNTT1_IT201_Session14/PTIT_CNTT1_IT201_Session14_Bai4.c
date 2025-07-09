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
void pushBottom(Stack* stack, int value) {
    Node* newNode = createNode(value);
    if (stack->top == NULL) {
        stack->top = newNode;
    } else {
        Node* temp = stack->top;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Ngan xep trong\n");
        return -1;
    }
    Node* temp = stack->top;
    int value = temp->data;
    stack->top = temp->next;
    free(temp);
    return value;
}
void printStack(Stack stack) {
    Node* temp = stack.top;
    if (temp == NULL) {
        printf("Ngan xep trong\n");
        return;
    }
    printf("Stack hien tai:\n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Stack stack;
    initStack(&stack);
    int n, value;
    printf("Nhap so phan tu muon them: ");
    scanf("%d", &n);
    printf("Nhap %d phan tu:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        pushBottom(&stack, value);
    }
    printf("Truoc khi pop:\n");
    printStack(stack);
    int removed = pop(&stack);
    if (removed != -1)
        printf("Gia tri vua lay ra: %d\n", removed);
    printf("Sau khi pop:\n");
    printStack(stack);

    return 0;
}
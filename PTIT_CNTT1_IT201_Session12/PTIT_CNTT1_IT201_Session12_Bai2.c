#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void addToHead(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head != NULL) {
        newNode->next = *head;
        (*head)->prev = newNode;
    }
    *head = newNode;
}
void printFromHead(Node* head) {
    while (head != NULL) {
        printf("data: %d\n", head->data);
        head = head->next;
    }
}

int main() {
    Node* head = NULL;
    for (int i = 5; i >= 1; i--) {
        addToHead(&head, i);
    }
    printFromHead(head);
    return 0;
}
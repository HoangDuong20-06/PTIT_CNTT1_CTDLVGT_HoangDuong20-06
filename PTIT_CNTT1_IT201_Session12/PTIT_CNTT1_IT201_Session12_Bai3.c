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
void append(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next) printf("<->");
        temp = temp->next;
    }
    printf("->NULL\n");
}
int main() {
    Node* head = NULL;
    for (int i = 5; i >= 1; i--)
        append(&head, i);
    int newValue;
    printf("Nhap gia tri moi: ");
    scanf("%d", &newValue);
    append(&head, newValue);
    printf("Danh sach sau khi them: ");
    printList(head);
    return 0;
}
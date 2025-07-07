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
void removeLast(Node** head) {
    if (*head == NULL) return;
    Node* temp = *head;
    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    temp->prev->next = NULL;
    free(temp);
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
    removeLast(&head);
    printf("Danh sach sau khi xoa cuoi: ");
    printList(head);
    return 0;
}
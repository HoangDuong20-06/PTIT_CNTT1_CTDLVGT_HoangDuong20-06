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
void sortList(Node* head) {
    Node *i, *j;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                int tmp = i->data;
                i->data = j->data;
                j->data = tmp;
            }
        }
    }
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
    int arr[] = {5, 4, 3, 2, 1, 6};
    for (int i = 0; i < 6; i++)
        append(&head, arr[i]);
    sortList(head);
    printf("Danh sach sau khi sap xep: ");
    printList(head);
    return 0;
}

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
void deleteByValue(Node** head, int target) {
    Node* temp = *head;
    while (temp != NULL) {
        if (temp->data == target) {
            Node* toDelete = temp;
            if (toDelete->prev)
                toDelete->prev->next = toDelete->next;
            else
                *head = toDelete->next;
            if (toDelete->next)
                toDelete->next->prev = toDelete->prev;
            temp = toDelete->next;
            free(toDelete);
        } else {
            temp = temp->next;
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
    int arr[] = {5, 4, 3, 5, 2, 1, 5};
    for (int i = 0; i < 7; i++)
        append(&head, arr[i]);
    int x;
    printf("Nhap gia tri muon xoa: ");
    scanf("%d", &x);
    deleteByValue(&head, x);
    printf("Danh sach sau khi xoa: ");
    printList(head);
    return 0;
}

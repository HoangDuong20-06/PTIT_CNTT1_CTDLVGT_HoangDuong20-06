// Bai1_TaoDanhSach.c
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
        printf("data: %d\n", temp->data);
        temp = temp->next;
    }
}
int main() {
    Node* head = NULL;
    int n, val;
    printf("Nhap so phan tu: ");
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        printf("Nhap gia tri phan tu %d: ", i + 1);
        scanf("%d", &val);
        append(&head, val);
    }
    printf("Danh sach lien ket:\n");
    printList(head);
    return 0;
}

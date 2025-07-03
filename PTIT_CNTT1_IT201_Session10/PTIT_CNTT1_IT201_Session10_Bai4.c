#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* appendNode(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) return newNode;
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    return head;
}
struct Node* deleteLastNode(struct Node* head) {
    if (head == NULL) return NULL;

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
    return head;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    head = appendNode(head, 5);
    head = appendNode(head, 4);
    head = appendNode(head, 3);
    head = appendNode(head, 2);
    head = appendNode(head, 1);
    printf("Danh sach ban dau:\n");
    printList(head);
    head = deleteLastNode(head);
    printf("Danh sach sau khi xoa node cuoi:\n");
    printList(head);
    return 0;
}
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
    if (head == NULL) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
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

struct Node* deleteValue(struct Node* head, int x) {
    while (head != NULL && head->data == x) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    struct Node* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->next->data == x) {
            struct Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
    return head;
}

int main() {
    struct Node* head = NULL;
    head = appendNode(head, 5);
    head = appendNode(head, 4);
    head = appendNode(head, 3);
    head = appendNode(head, 5);
    head = appendNode(head, 2);
    head = appendNode(head, 1);
    head = appendNode(head, 5);
    printf("Danh sach ban dau:\n");
    printList(head);
    int x;
    printf("Nhap gia tri muon xoa: ");
    scanf("%d", &x);
    head = deleteValue(head, x);
    printf("Danh sach sau khi xoa cac gia tri = %d:\n", x);
    printList(head);
    return 0;
}
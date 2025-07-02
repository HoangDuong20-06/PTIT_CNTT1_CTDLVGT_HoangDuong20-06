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

void appendNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void deleteAtPosition(struct Node** head, int pos) {
    if (*head == NULL || pos <= 0) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    pos--;
    struct Node* temp = *head;
    if (pos == 0) {
        *head = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Vi tri vuot qua do dai danh sach.\n");
        return;
    }
    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}
int main() {
    struct Node* head = NULL;
    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);
    appendNode(&head, 4);
    appendNode(&head, 5);
    printf("Danh sach ban dau:\n");
    printList(head);
    int pos;
    printf("Nhap vi tri muon xoa: ");
    scanf("%d", &pos);
    deleteAtPosition(&head, pos);
    printf("Danh sach sau khi xoa:\n");
    printList(head);
    return 0;
}
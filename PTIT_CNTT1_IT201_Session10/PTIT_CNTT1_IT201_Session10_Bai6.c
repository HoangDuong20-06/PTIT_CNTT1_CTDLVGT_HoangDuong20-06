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
void findMiddle(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    if (count == 0) {
        printf("Danh sach rong.\n");
        return;
    }
    int middleIndex = count / 2;
    temp = head;
    for (int i = 0; i < middleIndex; i++) {
        temp = temp->next;
    }
    printf("Node %d: %d\n", middleIndex + 1, temp->data);
}

int main() {
    struct Node* head = NULL;
    head = appendNode(head, 5);
    head = appendNode(head, 4);
    head = appendNode(head, 3);
    head = appendNode(head, 2);
    head = appendNode(head, 1);

    findMiddle(head);
    return 0;
}
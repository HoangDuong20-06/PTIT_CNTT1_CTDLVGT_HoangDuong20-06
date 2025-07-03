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
void printEachData(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("data: %d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct Node* head = NULL;
    head = appendNode(head, 5);
    head = appendNode(head, 4);
    head = appendNode(head, 3);
    head = appendNode(head, 2);
    head = appendNode(head, 1);
    printEachData(head);
    return 0;
}
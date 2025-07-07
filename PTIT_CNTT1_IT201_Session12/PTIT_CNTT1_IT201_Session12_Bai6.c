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
int countNodes(Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}
Node* findMiddle(Node* head) {
    int count = countNodes(head);
    int mid = count / 2;
    if (count % 2 == 0) mid++;
    for (int i = 1; i < mid; i++)
        head = head->next;
    return head;
}
int main() {
    Node* head = NULL;
    int arr[] = {5, 4, 3, 2, 1};
    for (int i = 0; i < 5; i++)
        append(&head, arr[i]);
    Node* middle = findMiddle(head);
    printf("Node o giua: %d\n", middle->data);
    return 0;
}

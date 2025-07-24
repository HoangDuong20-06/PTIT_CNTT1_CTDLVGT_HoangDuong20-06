#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
void append(Node** head, int v) {
    Node* newNode = createNode(v);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* curr = *head;
        while (curr->next != NULL)
            curr = curr->next;
        curr->next = newNode;
    }
}
void addEdge(Node* graph[], int u, int v) {
    append(&graph[u], v);
    append(&graph[v], u);
}
int main() {
    int n;
    scanf("%d", &n);
    getchar();
    Node* graph[MAX] = { NULL };
    char line[100];
    while (fgets(line, sizeof(line), stdin)) {
        if (strcmp(line, "\n") == 0) break; // dòng rỗng thì dừng lại
        int u, v;
        if (sscanf(line, "%d%d", &u, &v) == 2) {
            addEdge(graph, u, v);
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d:", i);
        Node* temp = graph[i];
        while (temp != NULL) {
            printf(" %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
    return 0;
}
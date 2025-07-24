#include <stdio.h>
#include <stdlib.h>

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

void addEdge(Node** adjList, int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;
}

int main() {
    int n;
    scanf("%d", &n);
    int matrix[5][5];
    Node* adjList[5] = { NULL };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = n-1; j >= 0; j--) {
            if (matrix[i][j] == 1) {
                addEdge(adjList, i, j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d:", i);
        Node* temp = adjList[i];
        while (temp != NULL) {
            printf(" %d ->", temp->vertex);
            temp = temp->next;
        }
        printf(" NULL\n");
    }
    return 0;
}
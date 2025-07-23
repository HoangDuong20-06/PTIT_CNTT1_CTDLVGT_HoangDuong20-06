#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
 int data;
 struct Node* next;
} Node;

Node* createNode(int data) {
 Node* newNode = malloc(sizeof(Node));
 newNode->data = data;
 newNode->next = NULL;
 return newNode;
}

void addEdge(Node* graph[], int start, int end) {
 Node* node1 = createNode(end);
 node1->next = graph[start];
 graph[start] = node1;

 Node* node2 = createNode(start);
 node2->next = graph[end];
 graph[end] = node2;
}

void printGraph(Node* graph[], int size) {
 printf("[\n");
 for (int i = 0; i < size; i++) {
  printf(" ");
  Node* temp = graph[i];
  if (!temp) {
   printf("NULL,\n");
  } else {
   while (temp) {
    printf("%d", temp->data);
    temp = temp->next;
    printf(temp ? "->" : "->NULL,\n");
   }
  }
 }
 printf("]\n");
}

int main() {
 Node* graph[3] = {NULL, NULL, NULL};
 printGraph(graph, 3);
 int startNode;
 printf("startNode = ");
 scanf("%d", &startNode);
 int endNode;
 printf("endNode = ");
 scanf("%d", &endNode);
 addEdge(graph, startNode, endNode);
 printGraph(graph, 3);
 return 0;
}

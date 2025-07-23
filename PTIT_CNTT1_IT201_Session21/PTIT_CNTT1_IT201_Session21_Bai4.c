#include <stdio.h>

void printGraph(int graph[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}
void addEdge(int graph[3][3], int startNode, int endNode) {
    graph[startNode][endNode] = 1;
}

int main() {
    int graph[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    addEdge(graph, 1, 0);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    printGraph(graph);
    return 0;
}
#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
void addEdge(int g[MAX][MAX], int u, int v) {
    g[u][v] = 1;
    g[v][u] = 1;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;
    int u, v;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &u, &v);
        addEdge(graph, u, v);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d", graph[i][j]);
        printf("\n");
    }
    return 0;
}

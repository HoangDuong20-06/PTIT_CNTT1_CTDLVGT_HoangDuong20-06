#include <stdio.h>

int main() {
    int n, c;
    printf("Nhap so dinh va so canh: ");
    scanf("%d %d", &n, &c);
    int matrix[100][100] = {0};  // ma trận kề
    printf("Nhap cac canh:\n");
    for (int i = 0; i < c; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }
    int k;
    printf("Nhap dinh k muon kiem tra: ");
    scanf("%d", &k);
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (matrix[k][i] == 1)
            count++;
    }
    printf("So dinh ke voi %d la: %d\n", k, count);
    return 0;
}
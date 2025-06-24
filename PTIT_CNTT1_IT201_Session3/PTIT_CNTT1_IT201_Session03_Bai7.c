#include <stdio.h>
#include <stdlib.h>

int tinhTong(int **arr, int cols, int rowIndex) {
    int sum = 0;
    for (int j = 0; j < cols; j++) {
        sum += arr[rowIndex][j];
    }
    return sum;
}
int main() {
    int rows, cols, k;
    printf("Nhap so hang: ");
    scanf("%d", &rows);
    printf("Nhap so cot: ");
    scanf("%d", &cols);
    if (rows <= 0 || rows >= 1000 || cols <= 0 || cols >= 1000) {
        printf("So hang khong hop le\n");
        return 0;
    }
    int **arr = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        arr[i] = (int *)malloc(cols * sizeof(int));
    }
    printf("Nhap cac phan tu cho mang:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("Mang gom cac phan tu:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("Nhap chi so hang can tinh tong: ");
    scanf("%d", &k);
    int realIndex = k -1  ;
    if (realIndex < 0 || realIndex >= rows) {
        printf("Hang can tinh khong ton tai\n");
    } else {
        int sum = tinhTong(arr, cols, realIndex);
        printf("sum = %d\n", sum);
    }
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);
    return 0;
}
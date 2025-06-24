#include <stdio.h>
#include <stdlib.h>
int findMin(int **arr, int row, int col) {
    int min = arr[0][0];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (arr[i][j] < min) {
                min = arr[i][j];
            }
        }
    }
    return min;
}
int findMax(int **arr, int row, int col) {
    int max = arr[0][0];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (arr[i][j] > max) {
                max = arr[i][j];
            }
        }
    }
    return max;
}
int main() {
    int row, col;
    int **arr;
    int min,max;
    printf("Nhap so hang: ");
    scanf("%d", &row);
    printf("Nhap so cot: ");
    scanf("%d", &col);
    if (row <0 || row > 1000) {
        printf("So hang khong hop le");
        return 1;
    }
    if (col <0 || col > 1000) {
        printf("So cot khong hop le");
        return 1;
    }
    if (row == 0 && col == 0) {
        printf("So hang hoac so cot khong hop le");
        return 1;
    }
    arr = (int **)malloc(row * sizeof(int *));
    if (arr == NULL) {
        printf("Bo nho day\n");
        return 1;
    }
    for (int i = 0; i < row; i++) {
        arr[i] = (int *)malloc(col * sizeof(int));
        if (arr[i] == NULL) {
            printf("Khong the cap phat dong thu %d\n", i);
            return 1;
        }
    }
    printf("Nhap phan tu cho mang:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("arr[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    printf("Mang vua nhap:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    printf("So lon nhat trong mang : %d\n",findMax(arr,row,col));
    printf("So nho nhat trong mang : %d\n",findMin(arr,row,col));
    for (int i = 0; i < row; i++) {
        free(arr[i]);
    }
    free(arr);
    return 0;
}
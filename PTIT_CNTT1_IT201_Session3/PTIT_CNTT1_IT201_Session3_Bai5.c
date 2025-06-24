#include <stdio.h>
#include <stdlib.h>
int findMainDiagonal(int **arr,int size) {
    int mainDiagonal = 0;
    for (int i = 0; i < size; i++) {
        mainDiagonal += arr[i][i];
    }
    return mainDiagonal;
}
int findSecondDiagonal(int **arr,int size) {
    int secondDiagonal = 0;
    for (int i = 0; i < size; i++) {
        secondDiagonal += arr[i][size-1-i];
    }
    return secondDiagonal;
}
int main() {
    int col,row;
    int **arr;
    printf("Nhap so hang: ");
    scanf("%d",&col);
    printf("Nhap so cot: ");
    scanf("%d",&row);
    if(col < 0 || col > 1000) {
        printf("So cot khong hop le");
        return 1;
    }
    if(row < 0 || row > 1000) {
        printf("So hang khong hop le");
        return 1;
    }
    if (col == 0 && row == 0) {
        printf("So hang va so cot khong hop le");
        return 1;
    }
    if (row != col) {
        printf("Khong ton tai duong cheo phu");
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
    printf("Tong duong cheo chinh : %d\n",findMainDiagonal(arr,row));
    printf("Tong duong cheo phu : %d",findSecondDiagonal(arr,row));
    for (int i = 0; i < row; i++) {
        free(arr[i]);
    }
    free(arr);
    return 0;
}
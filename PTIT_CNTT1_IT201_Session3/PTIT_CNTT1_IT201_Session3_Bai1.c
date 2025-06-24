#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *arr;
    int position = 0;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    if(n < 1 || n > 1000) {
        printf("Gia tri nhap khong hop le");
        return 1;
    }
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Khong du bo nho.\n");
        return 1;
    }
    printf("Nhap %d phan tu: \n",n);
    for(int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    printf("Cac gia tri trong mang:\n");
    for(int i = 0; i < n; i++) {
        position = position + 1;
        printf("So thi %d = %d\n",position,arr[i]);
    }
    free(arr);
    return 0;
}
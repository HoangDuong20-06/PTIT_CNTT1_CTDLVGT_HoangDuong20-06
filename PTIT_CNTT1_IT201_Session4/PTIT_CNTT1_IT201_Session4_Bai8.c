#include <stdio.h>

int main() {
    int n,f;
    int arr[100];
    printf("Nhap so luong phan tu cho mang: ");
    scanf("%d", &n);
    printf("Nhap phan tu cho mang: \n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] ", i);
        scanf("%d", &arr[i]);
    }
    printf("Mang hien co: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nNhap phan tu can tim: ");
    scanf("%d", &f);
    int find = 0;
    printf("Cac vi tri co gia tri %d la: ",f);
    for (int i = 0; i < n; i++) {
        if (arr[i] == f) {
            printf("%d ",i);
            find = 1;
        }
    }
    if (!find) {
        printf("Khong tim thay phan tu\n");
    }
    return 0;
}
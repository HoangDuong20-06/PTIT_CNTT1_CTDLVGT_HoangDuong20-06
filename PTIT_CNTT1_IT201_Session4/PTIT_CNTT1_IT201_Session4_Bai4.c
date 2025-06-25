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
    printf("\nNhap vi tri phan tu can tim: ");
    scanf("%d", &f);
    int find = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == f) {
            find = i;
        }
    }
    if (find!= -1) {
        printf("Chi so cuoi cung cua phan tu %d trong mang la: %d",f,find);
    }else {
        printf("Khong tim thay phan tu");
    }
    return 0;
}
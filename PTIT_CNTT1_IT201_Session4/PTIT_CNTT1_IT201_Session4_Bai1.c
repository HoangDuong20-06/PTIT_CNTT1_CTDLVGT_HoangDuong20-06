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
    int find = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == f) {
            printf("Chi so dau tien cua phan tu %d trong mang la: %d",f,i);
            find = 1;
            break;
        }
    }
    if (!find) {
        printf("Khong tim thay phan tu\n");
    }
    return 0;
}
#include <stdio.h>

int tinhTong(int arr[], int n) {
    if (n == 0) return 0;
    return arr[n - 1] + tinhTong(arr, n - 1);
}
int main() {
    int n;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);
    int arr[n];
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    int tong = tinhTong(arr, n);
    printf("Tong cac phan tu trong mang la: %d\n", tong);
    return 0;
}

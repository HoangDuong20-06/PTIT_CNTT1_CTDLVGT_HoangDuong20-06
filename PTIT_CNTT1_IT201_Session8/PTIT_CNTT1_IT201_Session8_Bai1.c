#include <stdio.h>

int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x)
            return i;
    }
    return -1;
}
int main() {
    int n, search;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);
    if (n <= 0 || n >= 1000) {
        printf("Gia tri n khong hop le!\n");
        return 1;
    }
    int arr[n];
    printf("Nhap %d phan tu cua mang:\n", n);
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    printf("Nhap gia tri can tim: ");
    scanf("%d", &search);
    int result = linearSearch(arr, n, search);
    if (result != -1)
        printf("Vi tri thu %d\n", result + 1); // Đánh số từ 1
    else
        printf("Khong ton tai phan tu\n");
    return 0;
}
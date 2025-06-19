#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, position, value;
    int *arr;
    printf("Nhap so luong phan tu (0 < n <= 100): ");
    scanf("%d", &n);
    if (n <= 0 || n > 100) {
        printf("So luong phan tu khong hop le.\n");
        return 1;
    }
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Khong du bo nho.\n");
        return 1;
    }
    printf("Nhap %d phan tu:\n", n);
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    printf("Nhap vi tri muon chen (tu 0 den %d): ", n);
    scanf("%d", &position);
    printf("Nhap gia tri muon chen: ");
    scanf("%d", &value);
    if (position < 0 || position > n) {
        printf("Khong hop le\n");
        free(arr);
        return 1;
    }
    arr = (int *)realloc(arr, (n + 1) * sizeof(int));
    if (arr == NULL) {
        printf("Khong du bo nho.\n");
        return 1;
    }
    for (int i = n; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = value;
    n++;
    printf("Mang sau khi chen: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
    free(arr);
    return 0;
}
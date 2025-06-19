#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, *arr;
    int position;
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
    printf("Mang dang co = ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Vi tri muon xoa: ");
    scanf("%d", &position);
    if (position < 0 || position >= n) {
        printf("Vi tri khong hop le.\n");
    } else {
        for (int i = position; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;
    }
    printf("Mang sau khi xoa: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}
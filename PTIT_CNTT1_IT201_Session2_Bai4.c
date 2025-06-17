#include <stdio.h>

int main() {
    int n, arr[100], x;
    int position;
    int value;
    printf("Nhap so luong phan tu (0 < n <= 100): ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("So luong phan tu khong hop le.\n");
        return 1;
    }
    printf("Nhap %d phan tu:\n", n);
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    printf("Mang dang co = ");
    for (int i = 0; i < n; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("Nhap vi tri muon sua: ");
    scanf("%d", &position);
    if (position < 0 || position >= n) {
        printf("Vi tri khong hop le.\n");
        return 1;
    }
    printf("Nhap gia tri: ");
    scanf("%d", &value);
    arr[position] = value;
    printf("Mang sau khi sua: ");
    for (int i = 0; i < n; i++) {
        printf("%d ",arr[i]);
    }
    return 0;
}
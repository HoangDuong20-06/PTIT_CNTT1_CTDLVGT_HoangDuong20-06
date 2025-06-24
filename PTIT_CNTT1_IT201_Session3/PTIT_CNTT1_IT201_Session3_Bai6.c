#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    if (n <= 0 || n >= 1000) {
        printf("So luong phan tu khong hop le\n");
        return 0;
    }
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Khong the cap phat bo nho\n");
        return 1;
    }

    printf("Nhap %d phan tu:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Nhap so luong phan tu muon them: ");
    scanf("%d", &m);
    if (m < 0 || n + m > 1000) {
        printf("So luong phan tu them khong hop le\n");
        free(arr);
        return 0;
    }
    int *temp = (int *)realloc(arr, (n + m) * sizeof(int));
    if (temp == NULL) {
        printf("Khong the cap phat bo nho moi\n");
        free(arr);
        return 1;
    }
    arr = temp;
    printf("Nhap %d phan tu moi:\n", m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &arr[n + i]);
    }
    printf("Mang sau khi them: [ ");
    for (int i = 0; i < n + m; i++) {
        printf("%d", arr[i]);
        if (i < n + m - 1)
            printf(", ");
    }
    printf(" ]\n");
    free(arr);
    return 0;
}
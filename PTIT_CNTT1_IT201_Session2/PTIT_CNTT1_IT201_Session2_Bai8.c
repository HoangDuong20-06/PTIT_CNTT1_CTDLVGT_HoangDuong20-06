#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *arr;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Khong the cap phat bo nho.\n");
        return 1;
    }
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    printf("Phan tu co gia tri lon hon cac gia tri dung sau no la:\n");
    for (int i = 0; i < n; i++) {
        int bigger = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] <= arr[j]) {
                bigger = 0;
                break;
            }
        }
        if (bigger) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
    free(arr);
    return 0;
}
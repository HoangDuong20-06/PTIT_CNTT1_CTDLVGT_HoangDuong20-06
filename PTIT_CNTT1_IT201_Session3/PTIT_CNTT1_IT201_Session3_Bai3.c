#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    int *arr;
    int count;
    int sumEven;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    if (n < 0 || n > 1000) {
        printf("So luong phan tu khong hop le \n");
        return 1;
    }
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Bo nho day\n");
        return 1;
    }
    printf("Nhap phan tu: \n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] =  ", i);
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            sumEven += arr[i];
            count++;
        }
    }
    if (count == 0) {
        printf("Mang khong co so chan\n");
    }else {
        sumEven = sumEven / count;
        printf("Trung binh cong so chan trong mang: %d",sumEven);
    }
    free(arr);
    return 0;
}
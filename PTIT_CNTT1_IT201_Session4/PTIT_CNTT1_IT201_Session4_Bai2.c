#include <stdio.h>

int main() {
    int n;
    int arr[100];
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    printf("Nhap phan tu: \n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] ", i);
        scanf("%d", &arr[i]);
    }
    printf("Mang hien co: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    int max = arr[0];
    int index = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
            index = i;
        }
    }
    printf("Phan tu lon nhat dau tien trong mang la %d o vi tri %d",max,index);
    return 0;
}